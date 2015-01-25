#ifndef __NTD_TESTS_STRING_TEST_HPP__
#define __NTD_TESTS_STRING_TEST_HPP__

#include "../mavis.hpp"

#include <ntd/string.hpp>

void run_string_tests() {
    mavis::describe("ntd/string.hpp", [](auto &s) {
        s.it("can replace Java with C++14", [](auto &spec) {
            auto str = ntd::replace("Java is awesome", "Java", "C++14");

            spec.expect_equals(std::string{"C++14 is awesome"}, str);
        });

        s.it("can replace letters", [](auto &spec) {
            auto str = ntd::replace("AaAaAaAaAaAaAaAaAaAaAa", "A", "B");

            spec.expect_equals(std::string{"BaBaBaBaBaBaBaBaBaBaBa"}, str);
        });

        s.it("can replace with spaces", [](auto &spec) {
            auto str = ntd::replace("Luke, I'm your mother yes", "your mother yes", "your father! D:");

            spec.expect_equals(std::string{"Luke, I'm your father! D:"}, str);
        });

        s.it("can replace in both ways", [](auto &spec) {
            auto str = ntd::replace(ntd::replace("Hello\tWorld\tand\tUniverse", "\t", "\n"), "\n", "\t");

            spec.expect_equals(std::string{"Hello\tWorld\tand\tUniverse"}, str);
        });

        s.it("can replace nothing", [](auto &spec) {
            auto str = ntd::replace("Bacon Melt", "Veggie", "Bacon");

            spec.expect_equals(std::string{"Bacon Melt"}, str);
        });

        s.it("can replace empty string", [](auto &spec) {
            auto str = ntd::replace("", "", "ntd");

            spec.expect_equals(std::string{""}, str);
        });

        s.it("can split spaces", [](auto &spec) {
            auto strings = ntd::split("Lorem ipsum dolor sit amet", ' ');

            auto vec = std::vector<std::string>{"Lorem", "ipsum", "dolor", "sit", "amet"};

            spec.expect_equals(strings.size(), vec.size());
        });

        s.it("can split line breaks", [](auto &spec) {
            auto strings = ntd::split("Lorem\nipsum\ndolor\nsit\namet", '\n');

            auto vec = std::vector<std::string>{"Lorem", "ipsum", "dolor", "sit", "amet"};

            spec.expect_equals(strings.size(), vec.size());
        });

        s.it("can split nothing", [](auto &spec) {
            auto strings = ntd::split("Hello, World!", 'x');

            spec.expect_equals(std::string{"Hello, World!"}, strings[0]);
        });

        s.it("can lower string", [](auto &spec) {
            auto string = std::string{"HELLO WORLD"};

            spec.expect_equals(std::string{"hello world"}, ntd::to_lower(string));
        });

        s.it("can upper string", [](auto &spec) {
            auto string = std::string{"hello world"};

            spec.expect_equals(std::string{"HELLO WORLD"}, ntd::to_upper(string));
        });
    });
}

#endif
