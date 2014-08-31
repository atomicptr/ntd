#ifndef __NTD_TESTS_CURRY_TEST_HPP__
#define __NTD_TESTS_CURRY_TEST_HPP__

#include <ntd/curry.hpp>
#include <mavis/mavis.hpp>

auto test_curry_add() {
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

#endif
