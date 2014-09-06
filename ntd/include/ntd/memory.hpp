#ifndef __NTD_MEMORY_HPP__
#define __NTD_MEMORY_HPP__

#include <memory>

namespace ntd {

    /**
        This function can turn a C construct and destruct combo-function into a smart pointer.

        <b>Example</b> <pre>auto window = ntd::make_smart<Window>(Lib_CreateWindow, Lib_DestroyWindow, "Title", x, y);</pre>

        @param creator_function A function (object_type* function()) which creates the object.
        @param deleter_function A function (void function(object_type*)) which deletes the object.
        @param arguments... The arguments passed into the creator function

        @return A std::shared_ptr to the object created with the creator_function
    */
    template<typename type, typename creator_function, typename deleter_function, typename... arguments>
    auto make_smart(creator_function c, deleter_function d, arguments... args) {
        return std::shared_ptr<type>(c(std::forward<arguments>(args)...), d);
    }
}

#endif