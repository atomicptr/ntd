#include <mavis/mavis.hpp>

#include "tests/curry_test.hpp"

int main() {
    // curry tests
    auto curry_tests = mavis::create_test_unit("curry tests");

    curry_tests.add_test(test_curry_add);

    curry_tests.run_tests();

    return 0;
}
