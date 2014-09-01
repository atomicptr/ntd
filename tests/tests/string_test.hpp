#ifndef __NTD_TESTS_STRING_TEST_HPP__
#define __NTD_TESTS_STRING_TEST_HPP__

#include <mavis/mavis.hpp>
#include <ntd/string.hpp>

auto test_replace_simple() {
    auto str = ntd::replace("Java is awesome", "Java", "C++14");

    return mavis_assert_equals("C++14 is awesome", str);
}

auto test_replace_letters() {
    auto str = ntd::replace("AaAaAaAaAaAaAaAaAaAaAa", "A", "B");

    return mavis_assert_equals("BaBaBaBaBaBaBaBaBaBaBa", str);
}

auto test_replace_with_space() {
    auto str = ntd::replace("Luke, I'm your mother yes", "your mother yes", "your father! D:");

    return mavis_assert_equals("Luke, I'm your father! D:", str);
}

auto test_replace_duplex() {
    auto str = ntd::replace(ntd::replace("Hello\tWorld\tand\tUniverse", "\t", "\n"), "\n", "\t");

    return mavis_assert_equals("Hello\tWorld\tand\tUniverse", str);
}

auto test_replace_nothing() {
    auto str = ntd::replace("Bacon Melt", "Veggie", "Bacon");

    return mavis_assert_equals("Bacon Melt", str);
}

auto test_replace_empty() {
    auto str = ntd::replace("", "", "ntd");

    return mavis_assert_equals("", str);
}

auto test_split_spaces() {
    auto strings = ntd::split("Lorem ipsum dolor sit amet", ' ');

    auto vec = std::vector<std::string>{"Lorem", "ipsum", "dolor", "sit", "amet"};

    return mavis_assert_vector_equals(strings, vec);
}

auto test_split_breaks() {
    auto strings = ntd::split("Lorem\nipsum\ndolor\nsit\namet", '\n');

    auto vec = std::vector<std::string>{"Lorem", "ipsum", "dolor", "sit", "amet"};

    return mavis_assert_vector_equals(strings, vec);
}

auto test_split_nothing() {
    auto strings = ntd::split("Hello, World!", 'x');

    return mavis_assert_equals("Hello, World!", strings[0]);
}

void run_string_tests() {
    auto string_test_unit = mavis::create_test_unit("string tests");

    string_test_unit.add_test(test_replace_simple);
    string_test_unit.add_test(test_replace_letters);
    string_test_unit.add_test(test_replace_with_space);
    string_test_unit.add_test(test_replace_duplex);
    string_test_unit.add_test(test_replace_nothing);
    string_test_unit.add_test(test_replace_empty);

    string_test_unit.add_test(test_split_spaces);
    string_test_unit.add_test(test_split_breaks);
    string_test_unit.add_test(test_split_nothing);

    string_test_unit.run_tests();
}

#endif