#ifndef __NTD_MEMORY_HPP__
#define __NTD_MEMORY_HPP__

namespace ntd {

    template<typename type, typename creator_function, typename deleter_function, typename... arguments>
    auto make_smart(creator_function c, deleter_function d, arguments... args) {
        return std::shared_ptr<type>(c(std::forward<arguments>(args)...), d);
    }
}

#endif