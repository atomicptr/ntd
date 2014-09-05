#ifndef __NTD_MEMORY_TEST_HPP__
#define __NTD_MEMORY_TEST_HPP__

#include <mavis/mavis.hpp>

#include <ntd/memory.hpp>

#include <string>

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

auto test_make_smart() {
    auto widget_ptr = ntd::make_smart<widget_t>(widget_creator, widget_deleter, "widget#1", 13, 37);

    return mavis_assert_equals("widget#1", widget_ptr->name);
}

auto test_make_smart_test_deleter_called() {
    bool was_deleted = false;

    auto custom_deleter = [&](widget_t *w) {
        was_deleted = true;

        delete w;
    };

    if(!was_deleted) {
        auto widget_ptr = ntd::make_smart<widget_t>(widget_creator, custom_deleter, "widget#2", 13, 37);
    }

    return mavis_assert_true(was_deleted);
}

void run_memory_tests() {
    auto unit = mavis::create_test_unit("memory tests");

    unit.add_test(test_make_smart);
    unit.add_test(test_make_smart_test_deleter_called);

    unit.run_tests();
}

#endif