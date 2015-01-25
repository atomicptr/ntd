#ifndef __NTD_TESTS_CURRY_TEST_HPP__
#define __NTD_TESTS_CURRY_TEST_HPP__

#include "../mavis.hpp"

#include <ntd/partial_function.hpp>

// used for test_partial_function_function and test_partial_function_partial_function
int add(int x, int y) {
    return x + y;
}

void run_partial_function_tests() {
    mavis::describe("ntd/partial_function.hpp", [](auto& s) {
        s.it("works with lambdas", [](auto &spec) {
                auto sum = [](auto first, auto... rest) {
                auto sum = first;

                for(auto x : {rest...}) {
                    sum += x;
                }

                return sum;
            };

            auto func = ntd::partial_function(sum, 1, 2, 3, 4);

            spec.expect_equals(sum(1, 2, 3, 4, 5, 5, 22), func(5, 5, 22));
        });

        s.it("works with regular functions", [](auto &spec) {
            auto add40 = ntd::partial_function(add, 40);

            spec.expect_equals(42, add40(2));
        });

        s.it("works with itself", [](auto &spec) {
            // to partial_function partial_function I need to put it into another function
            auto partial_function = [](auto... args) {
                return ntd::partial_function(args...);
            };

            auto curried_partial_function = ntd::partial_function(partial_function, add, 4);

            spec.expect_equals(10, curried_partial_function(6)());
        });
    });
}

#endif
