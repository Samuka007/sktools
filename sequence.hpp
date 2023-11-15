#pragma once

#include <iostream>
#include <utility>

namespace sktools::sequence {

template <std::size_t... Is1, std::size_t... Is2>
auto concat_sequences(std::integer_sequence<std::size_t, Is1...>, std::integer_sequence<std::size_t, Is2...>) {
    return std::integer_sequence<std::size_t, Is1..., Is2...>{};
}

template <std::size_t Gen, std::size_t End>
struct makeDoubleSequence {
    using next = typename makeDoubleSequence<Gen * 2, End>::type;
    using type = decltype( concat_sequences( std::integer_sequence<std::size_t, Gen>{} , next{}) );
};

template <std::size_t End>
struct makeDoubleSequence<End, End> {
    using type = std::integer_sequence<std::size_t, End>;
};

template <std::size_t Gen, std::size_t End>
using makeDoubleSequence_t = typename makeDoubleSequence<Gen, End>::type;

template <std::size_t... Is>
void print_sequence(std::integer_sequence<std::size_t, Is...>) {
    ((std::cout << Is << ' '), ...);
}

}