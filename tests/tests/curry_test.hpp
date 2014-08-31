#ifndef __NTD_TESTS_CURRY_TEST_HPP__
#define __NTD_TESTS_CURRY_TEST_HPP__

#include <ntd/curry.hpp>
#include <mavis/mavis.hpp>

// used for test_curry_function and test_curry_curry
int add(int x, int y) {
    return x + y;
}

// test cases
auto test_curry_lambda() {
    auto sum = [](auto first, auto... rest) {
        auto sum = first;

        for(auto x : {rest...}) {
            sum += x;
        }

        return sum;
    };

    auto func = ntd::curry(sum, 1, 2, 3, 4);

    return mavis_assert_equals(sum(1, 2, 3, 4, 5, 5, 22), func(5, 5, 22));
}

auto test_curry_function() {
    auto add40 = ntd::curry(add, 40);

    return mavis_assert_equals(42, add40(2));
}

auto test_curry_curry() {
    // to curry curry I need to put it into another function
    auto curry = [](auto... args) {
        return ntd::curry(args...);
    };

    auto curried_curry = ntd::curry(curry, add, 4);

    return mavis_assert_equals(10, curried_curry(6)());
}


void run_curry_tests() {
    // curry tests
    auto curry_tests = mavis::create_test_unit("curry tests");

    curry_tests.add_test(test_curry_lambda);
    curry_tests.add_test(test_curry_function);
    curry_tests.add_test(test_curry_curry);

    curry_tests.run_tests();
}

#endif
