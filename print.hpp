#pragma once

#include <format>
#include <iostream>
namespace sktools::print {
    
template< class... Args >
void print( std::format_string<Args...> fmt, Args&&... args )
{
    std::cout << std::format( fmt, std::forward<Args>(args)... );
}

template< class... Args >
void println( std::format_string<Args...> fmt, Args&&... args )
{
    print("{}\n", std::format(fmt, args...));
}

}