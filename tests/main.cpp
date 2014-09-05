#include "tests/curry_test.hpp"
#include "tests/string_test.hpp"
#include "tests/memory_test.hpp"

int main() {
    run_curry_tests();
    run_string_tests();
    run_memory_tests();

    return 0;
}
