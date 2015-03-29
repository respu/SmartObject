//
//  Containers.h
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

#ifndef Tools_Containers_h
#define Tools_Containers_h


// ================================================================================ Standard Includes
// Standard Includes
// --------------------------------------------------------------------------------
#include <array>
#include <vector>
#include <deque>
#include <map>
#include <unordered_map>


// ================================================================================ Tools Includes
// Tools Includes
// --------------------------------------------------------------------------------
#include "SmartWrapper.h"


namespace Core
{
    // ============================================================================ Containers
    // Containers
    //
    // SmartObject/SmartPtr-compatible container classes
    // ---------------------------------------------------------------------------- Array
    template < typename    value_t,
               std::size_t element_count >
    
    using Array = SmartWrapper< std::array<value_t, element_count> >;
    
    // ---------------------------------------------------------------------------- Vector
    template < typename value_t,
               typename alloc = std::allocator<value_t> >
    
    using Vector = SmartWrapper< std::vector<value_t, alloc> >;
    
    // ---------------------------------------------------------------------------- Deque
    template< typename value_t,
              typename alloc = std::allocator<value_t> >
    
    using Deque = SmartWrapper< std::deque<value_t, alloc> >;
    
    // ---------------------------------------------------------------------------- Map
    template < typename key_t,
               typename value_t,
               typename compare = std::less<key_t>,
               typename alloc   = std::allocator< std::pair<const key_t, value_t> > >
    
    using Map = SmartWrapper< std::map<key_t, value_t, compare, alloc> >;
    
    // ---------------------------------------------------------------------------- Unordered_Map
    template< typename key_t,
              typename value_t,
              typename hash      = std::hash<key_t>,
              typename key_equal = std::equal_to<key_t>,
              typename alloc     = std::allocator< std::pair<const key_t, value_t> > >
    
    using Unordered_Map = SmartWrapper< std::unordered_map<key_t, value_t> >;
};


#endif
