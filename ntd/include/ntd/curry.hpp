#ifndef __NTD_CURRY_HPP__
#define __NTD_CURRY_HPP__

namespace ntd {

    /**
        This function returns a function with n-arguments curried into it. (<a href="http://en.wikipedia.org/wiki/Currying">What is curry?</a>)

        <b>Example</b>

        <pre>

        auto add = [](auto x, auto y){ return x + y; };
        auto add4 = ntd::curry(add, 4);
        auto x = add4(6); // 10

        </pre>

        @param function The function you want to curry.
        @param arguments... The curried arguments.

        @return A function with n-arguments curried into it.
    */
    template<typename function, typename... arguments>
    auto curry(function func, arguments... args) {
        return [=](auto... rest) {
            return func(args..., rest...);
        };
    }
}

#endif
