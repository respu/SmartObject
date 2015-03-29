# SmartObject
Basic thread-safe non-locking intrinsic-refcount smart object system for C++11 and newer


## Why?
Standard shared pointers in C++ allocated a separate piece of memory to hold the reference count. This can negatively impact the performance of any code that has a lot of smart pointers being added and removed from different places due to the extra memory hit incurred when the reference count is updated.

The SmartObject class in this repository adds an intrinsic thread-safe non-locking reference counter that is included directly in your object.


## Core::SmartObject
Inherit Core::SmartObject as a public base class and it can be used with the SmartPtr class for reference-counting.

```C++
class MyObject : public Core::SmartObject
{
    // Class internals go here.
    // SmartObject does not require any constuctor parameters
};

Core::SmartPtr< MyObject > sptr_to_object( new MyObject() );
```

Use as you would `std::shared_ptr`.


## Core::SmartWrapper
The SmartWrapper class allows you to add intrinsic refcount abilities to any existing class. See `Containers.h` for usage examples.
