//
//  SmartObject.h
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

#ifndef Tools_SmartObject_h
#define Tools_SmartObject_h


// ================================================================================ Tools Includes
// Tools Includes
// --------------------------------------------------------------------------------
#include "Types.h"


namespace Core
{
    // ============================================================================ SmartObject
    // SmartObject
    //
    // A reference-countable base class
    // ----------------------------------------------------------------------------
    class SmartObject
    {
    private:
        // -------------------------------------------------------------------- Private Typedefs
        using Atomic_t = atomic_uint32_t;

    public:
        // -------------------------------------------------------------------- Public Typedefs
        using Refcount_t = uint_fast32_t;

    private:
        // -------------------------------------------------------------------- Friend Classes
        friend class SmartPtr_Base;
        
        // -------------------------------------------------------------------- State
        mutable Atomic_t _reference_count;
        
        
    public:
        // ==================================================================== Construct / Destruct
        // Construct / Destruct
        // -------------------------------------------------------------------- Construct
        SmartObject() noexcept
        
            : _reference_count(0) {}
        
        // -------------------------------------------------------------------- Destruct
        virtual ~SmartObject() {}

        
    private:
        // ==================================================================== Private API
        // Private API
        // -------------------------------------------------------------------- Reference Counting
        inline void       Reference_Increment()       noexcept {        _reference_count.fetch_add(1, std::memory_order_relaxed);     }
        inline Refcount_t Reference_Decrement()       noexcept { return _reference_count.fetch_sub(1, std::memory_order_acq_rel) - 1; }
        inline Refcount_t Reference_Count    () const noexcept { return _reference_count.load(); }
    };
};


#endif
