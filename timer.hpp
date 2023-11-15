#pragma once 

#include <chrono>
#include <vector>
#include <thread>
#include <concepts>
#include <functional>
#include <iostream>

namespace sktools::timer {
    
    template < std::invocable FuncTy, typename... Arg >
    auto invoke_duration ( FuncTy&& func, Arg&&... args )
    {
        auto start = steady_clock::now();
        std::invoke( std::forward<FuncTy>(func), std::forward<Arg>(args)... );
        return steady_clock::now() - start;
    }

}