#ifndef __NTD_TESTS_CURRY_TEST_HPP__
#define __NTD_TESTS_CURRY_TEST_HPP__

#include <ntd/partial_function.hpp>
#include <mavis/mavis.hpp>

// used for test_partial_function_function and test_partial_function_partial_function
int add(int x, int y) {
    return x + y;
}

// test cases
auto test_partial_function_lambda() {
    auto sum = [](auto first, auto... rest) {
        auto sum = first;

        for(auto x : {rest...}) {
            sum += x;
        }

        return sum;
    };

    auto func = ntd::partial_function(sum, 1, 2, 3, 4);

    return mavis_assert_equals(sum(1, 2, 3, 4, 5, 5, 22), func(5, 5, 22));
}

auto test_partial_function_function() {
    auto add40 = ntd::partial_function(add, 40);

    return mavis_assert_equals(42, add40(2));
}

auto test_partial_function_partial_function() {
    // to partial_function partial_function I need to put it into another function
    auto partial_function = [](auto... args) {
        return ntd::partial_function(args...);
    };

    auto curried_partial_function = ntd::partial_function(partial_function, add, 4);

    return mavis_assert_equals(10, curried_partial_function(6)());
}


void run_partial_function_tests() {
    // partial_function tests
    auto partial_function_tests = mavis::create_test_unit("partial_function tests");

    partial_function_tests.add_test(test_partial_function_lambda);
    partial_function_tests.add_test(test_partial_function_function);
    partial_function_tests.add_test(test_partial_function_partial_function);

    partial_function_tests.run_tests();
}

#endif
