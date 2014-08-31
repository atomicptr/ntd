#ifndef __NTD_CURRY_HPP__
#define __NTD_CURRY_HPP__

namespace ntd {
    template<typename function, typename... arguments>
    auto curry(function func, arguments... args) {
        return [=](auto... rest) {
            return func(args..., rest...);
        };
    }
}

#endif
