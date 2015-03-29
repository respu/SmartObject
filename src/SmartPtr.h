//
//  SmartPtr.h
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

#ifndef Tools_SmartPtr_h
#define Tools_SmartPtr_h


// ================================================================================ Standard Includes
// Standard Includes
// --------------------------------------------------------------------------------
#include <utility>


// ================================================================================ Tools Includes
// Tools Includes
// --------------------------------------------------------------------------------
#include "SmartObject.h"


namespace Core
{
    // ============================================================================ SmartPtr_Base
    // SmartPtr_Base
    //
    // Helper object for SmartPtr template, do not use directly.
    // ----------------------------------------------------------------------------
    class SmartPtr_Base
    {
    public:
        static inline void                    Reference_Increment ( SmartObject * object_ptr ) noexcept { if     ( object_ptr )   object_ptr->Reference_Increment();     }
        static inline SmartObject::Refcount_t Reference_Decrement ( SmartObject * object_ptr ) noexcept { return ( object_ptr ) ? object_ptr->Reference_Decrement() : 0; }
        static inline SmartObject::Refcount_t Reference_Count     ( SmartObject * object_ptr ) noexcept { return ( object_ptr ) ? object_ptr->Reference_Count()     : 0; }
    };
    
    
    
    // ============================================================================ SmartPtr
    // SmartPtr
    //
    // Provides a reference-counting smart pointer for SmartObject-derived classes
    // ----------------------------------------------------------------------------
    template < class class_t >
    
    class SmartPtr final : private SmartPtr_Base
    {
    private:
        // -------------------------------------------------------------------- State
        class_t * _object_ptr;
        
        
    public:
        // ==================================================================== Construct / Destruct
        // Construct / Destruct
        // -------------------------------------------------------------------- Construct
        SmartPtr()                       noexcept : _object_ptr( nullptr    ) {}
        SmartPtr( class_t * object_ptr ) noexcept : _object_ptr( object_ptr ) { SmartPtr_Base::Reference_Increment( _object_ptr ); }
        
        // -------------------------------------------------------------------- Construct ( convert )
        template < class rhs_class_t >
        
        SmartPtr( SmartPtr< rhs_class_t > & rhs ) noexcept
        
            : _object_ptr( rhs.Get() )
        {
            SmartPtr_Base::Reference_Increment( _object_ptr );
        }
        
        // -------------------------------------------------------------------- Construct ( move/copy )
        SmartPtr( SmartPtr const  & source ) noexcept : _object_ptr( source._object_ptr ) { SmartPtr_Base::Reference_Increment( _object_ptr ); }
        SmartPtr( SmartPtr       && source ) noexcept : _object_ptr( source._object_ptr ) { source._object_ptr = nullptr; }
        
        // -------------------------------------------------------------------- Destruct
        ~SmartPtr()
        {
            // If no object, then nothing to destruct
            if ( _object_ptr == nullptr )
                return;
            
            
            // Decrement reference count, and delete object if necessary
            const SmartObject::Refcount_t ref_count = SmartPtr_Base::Reference_Decrement( _object_ptr );
            
            if ( !ref_count )
                delete _object_ptr;


            // Sanity
            _object_ptr = nullptr;
        }
        
        
    public:
        // ==================================================================== Public API
        // Public API
        // -------------------------------------------------------------------- Assignment
        SmartPtr & operator=( SmartPtr const  & source ) { SmartPtr(source                        ).Swap(*this); return *this; }
        SmartPtr & operator=( SmartPtr       && source ) { SmartPtr(std::forward<SmartPtr>(source)).Swap(*this); return *this; }
        SmartPtr & operator=( class_t         * source ) { SmartPtr(source                        ).Swap(*this); return *this; }
        
        // -------------------------------------------------------------------- Dereference
        class_t & operator* () const { return *_object_ptr; }
        class_t * operator->() const { return  _object_ptr; }
        
        // -------------------------------------------------------------------- Pointer Access
        class_t * Get() const noexcept { return _object_ptr; }
        
        
    private:
        // ==================================================================== Private API
        // Private API
        // -------------------------------------------------------------------- Swap()
        void Swap( SmartPtr & source )
        {
            std::swap( _object_ptr, source._object_ptr );
        }
    };
    
    
    
    // ============================================================================ SmartPtr Comparison Operators
    // SmartPtr Comparison Operators
    //
    // I apologize for the wide code.
    // ---------------------------------------------------------------------------- operator==()
    template < class class1_t, class class2_t > inline bool operator==( SmartPtr<class1_t> const & sp1, SmartPtr<class2_t> const & sp2 ) { return sp1.Get() == sp2.Get(); }
    template < class class1_t, class class2_t > inline bool operator==( SmartPtr<class1_t> const & sp1,          class2_t        *  p2 ) { return sp1.Get() ==  p2;       }
    template < class class1_t, class class2_t > inline bool operator==(          class1_t        *  p1, SmartPtr<class2_t> const & sp2 ) { return  p1       == sp2.Get(); }
    
    // ---------------------------------------------------------------------------- operator!=()
    template < class class1_t, class class2_t > inline bool operator!=( SmartPtr<class1_t> const & sp1, SmartPtr<class2_t> const & sp2 ) { return sp1.Get() != sp2.Get(); }
    template < class class1_t, class class2_t > inline bool operator!=( SmartPtr<class1_t> const & sp1,          class2_t        *  p2 ) { return sp1.Get() !=  p2;       }
    template < class class1_t, class class2_t > inline bool operator!=(          class1_t        *  p1, SmartPtr<class2_t> const & sp2 ) { return  p1       != sp2.Get(); }
    
    // ---------------------------------------------------------------------------- operator<()
    template < class class_t >
    
    inline bool operator<( SmartPtr<class_t> const & sp1,
                           SmartPtr<class_t> const & sp2 )
    {
        return std::less< class_t* >( sp1.Get(), sp2.Get() );
    }
};


#endif
