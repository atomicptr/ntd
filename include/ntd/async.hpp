#ifndef __NTD_ASYNC_HPP__
#define __NTD_ASYNC_HPP__

#include <chrono>
#include <future>
#include <functional>

namespace ntd {

    template<typename T, typename U>
    void timeout(std::chrono::duration<T, U> t, std::function<void()> callback) {
        std::async(std::launch::async, [t, &callback]() {
            std::this_thread::sleep_for(t);
            callback();
        });
    }
}

#endif
