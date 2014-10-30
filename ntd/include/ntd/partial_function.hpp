#ifndef __NTD_PARTIAL_FUNCTION_HPP__
#define __NTD_PARTIAL_FUNCTION_HPP__

namespace ntd {

    /**
        <b>Example</b>

        <pre>

        auto add = [](auto x, auto y){ return x + y; };
        auto add4 = ntd::partial_function(add, 4);
        auto x = add4(6); // 10

        </pre>

        @param function
        @param arguments...

        @return
    */
    template<typename Function, typename... Arguments>
    auto partial_function(Function func, Arguments... args) {
        return [=](auto... rest) {
            return func(args..., rest...);
        };
    }
}

#endif
