#ifndef __NTD_MEMORY_HPP__
#define __NTD_MEMORY_HPP__

#include <memory>

namespace ntd {

    /**
        This function can turn a C construct and destruct combo-function into a smart pointer.

        <b>Example</b> <pre>auto window = ntd::make_smart<Window>(Lib_CreateWindow, Lib_DestroyWindow, "Title", x, y);</pre>

        @param Constructor A function (object_type* function()) which creates the object.
        @param Destructor A function (void function(object_type*)) which deletes the object.
        @param Arguments... The Arguments passed into the creator function

        @return A std::shared_ptr to the object created with the Constructor
    */
    template<typename T, typename Constructor, typename Destructor, typename... Arguments>
    auto make_smart(Constructor construct, Destructor destroy, Arguments... args) {
        return std::shared_ptr<T>(construct(std::forward<Arguments>(args)...), destroy);
    }
}

#endif