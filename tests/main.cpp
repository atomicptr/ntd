#include "tests/partial_function_test.hpp"
#include "tests/string_test.hpp"
#include "tests/memory_test.hpp"
#include "tests/async_test.hpp"

int main() {
    run_partial_function_tests();
    run_string_tests();
    run_memory_tests();
    run_async_tests();

    return 0;
}
