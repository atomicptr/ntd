#ifndef __NTD_ASYNC_TEST_HPP__
#define __NTD_ASYNC_TEST_HPP__

#include <future>
#include <chrono>

#include "../mavis.hpp"

#include <ntd/async.hpp>

void run_async_tests() {
    using namespace std::chrono_literals;

    mavis::describe("ntd/async.hpp", [](auto& s) {
        s.it("can change a value after timeout", [](auto& spec) {
            int x = 5;

            ntd::timeout(50ms, [&x]() {
                x = 1337;
            });

            std::this_thread::sleep_for(80ms);

            spec.expect_equals(x, 1337);
        });

        s.it("can change a value multiple times after timeout", [](auto& spec) {
            int x = 0;

            auto add1 = [&x]() { x++; };

            ntd::timeout(10ms, add1);
            ntd::timeout(20ms, add1);
            ntd::timeout(30ms, add1);

            std::this_thread::sleep_for(50ms);

            spec.expect_equals(x, 3);
        });
    });
}

#endif
