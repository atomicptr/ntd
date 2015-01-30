#ifndef __NTD_PARTIAL_FUNCTION_HPP__
#define __NTD_PARTIAL_FUNCTION_HPP__

namespace ntd {

    template<typename Function, typename... Arguments>
    auto partial_function(Function func, Arguments... args) {
        return [=](auto... rest) {
            return func(args..., rest...);
        };
    }
}

#endif
