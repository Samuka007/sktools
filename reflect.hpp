#pragma once

#include <iostream>
#include <type_traits>

namespace sktools::meta {

struct init {
    template <typename T>
    operator T();
};

template <typename T>
consteval size_t size(auto&&...Args) {
    if constexpr (!requires{T{ Args... }; }) {
        return sizeof...(Args) - 1;
    }
    else {
        return size<T>(Args..., init{});
    }
}

template <typename T, typename F>
void for_each_member(T const& v, F&& f) {
    static_assert(std::is_aggregate_v<T>);

    if constexpr (size<T>() == 4u) {
        const auto& [m0, m1, m2, m3] = v;
        f(m0); f(m1); f(m2); f(m3);
    }
    else if constexpr (size<T>() == 3u) {
        const auto& [m0, m1, m2] = v;
        f(m0); f(m1); f(m2);
    }
    else if constexpr (size<T>() == 2u) {
        const auto& [m0, m1] = v;
        f(m0); f(m1);
    }
    else if constexpr (size<T>() == 1u) {
        const auto& [m0] = v;
        f(m0);
    }
}

}