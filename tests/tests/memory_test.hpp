#ifndef __NTD_MEMORY_TEST_HPP__
#define __NTD_MEMORY_TEST_HPP__

#include <string>

#include "../mavis.hpp"

#include <ntd/memory.hpp>

// cuz, if you don't know how to call something just call it widget
struct widget_t {
    std::string name;
    int x;
    int y;
};

widget_t* widget_creator(std::string name, int x, int y) {
    widget_t *w = new widget_t;

    w->name = name;
    w->x = x;
    w->y = y;

    return w;
}

void widget_deleter(widget_t *w) {
    delete w;
}

void run_memory_tests() {
    mavis::describe("ntd/memory.hpp", [](auto& s) {
        s.it("can make C construct/deleter functions smarter", [](auto& spec) {
            auto widget_ptr = ntd::make_smart<widget_t>(widget_creator, widget_deleter, "widget#1", 13, 37);

            spec.expect_equals(std::string{"widget#1"}, widget_ptr->name);
        });

        s.it("makes sure the deleter is called", [](auto& spec) {
            bool was_deleted = false;

            auto custom_deleter = [&was_deleted](widget_t *w) {
                was_deleted = true;

                delete w;
            };

            if(!was_deleted) {
                auto widget_ptr = ntd::make_smart<widget_t>(widget_creator, custom_deleter, "widget#2", 13, 37);
            }

            spec.expect_true(was_deleted);
        });
    });
}

#endif
