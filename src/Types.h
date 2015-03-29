//
//  Types.h
//
// The MIT License (MIT)
//
// Copyright (c) 2015 Bradley Wilson
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//

#ifndef Tools_Types_h
#define Tools_Types_h


// ================================================================================ Standard Includes
// Standard Includes
// --------------------------------------------------------------------------------
#include <cstdint>
#include <string>
#include <sstream>
#include <utility>


// ================================================================================ Atomics
// Atomics
// --------------------------------------------------------------------------------
using atomic_bool     = std::atomic_bool;

using atomic_int8_t   = std::atomic_int_fast8_t;
using atomic_int16_t  = std::atomic_int_fast16_t;
using atomic_int32_t  = std::atomic_int_fast32_t;
using atomic_int64_t  = std::atomic_int_fast64_t;

using atomic_uint8_t  = std::atomic_uint_fast8_t;
using atomic_uint16_t = std::atomic_uint_fast16_t;
using atomic_uint32_t = std::atomic_uint_fast32_t;
using atomic_uint64_t = std::atomic_uint_fast64_t;



// ================================================================================ Numeric Pairs
// Numeric Pairs
// --------------------------------------------------------------------------------
using int8_pair_t   = std::pair<   int_fast8_t,   int_fast8_t >;
using int16_pair_t  = std::pair<  int_fast16_t,  int_fast16_t >;
using int32_pair_t  = std::pair<  int_fast32_t,  int_fast32_t >;
using int64_pair_t  = std::pair<  int_fast64_t,  int_fast64_t >;

using uint8_pair_t  = std::pair<  uint_fast8_t,  uint_fast8_t >;
using uint16_pair_t = std::pair< uint_fast16_t, uint_fast16_t >;
using uint32_pair_t = std::pair< uint_fast32_t, uint_fast32_t >;
using uint64_pair_t = std::pair< uint_fast64_t, uint_fast64_t >;

using size_t_pair_t = std::pair< std::size_t,   std::size_t   >;

using float_pair_t  = std::pair<         float,         float >;
using double_pair_t = std::pair<        double,        double >;



// ================================================================================ Enum Utilities
// Enums and Utilities
// -------------------------------------------------------------------------------- Utilities
namespace Enum
{
    // ------------------------------------------------------------------------ as_Index()
    template < typename enum_t >

    inline constexpr std::size_t as_Index( enum_t enum_value )
    {
        return static_cast< std::size_t >( enum_value );
    }
}

#endif
