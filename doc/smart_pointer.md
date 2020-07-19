# Exercise: Unique Pointer

Implement a class template for a smart pointer which guarantees single ownership of arbitrary dynamically allocated objects. Your implementation should mimick the interface of raw pointers as closely as possible, however should not allow pointer arithmetic.

1. Implement a class template called `UniquePointer` in `unique_pointer.hpp` with exactly one template parameter.
2. Implement a constructor and destructor according to the RAII principle.
3. Implement operators for dereferencing the pointer operator-> and operator* as well as a method called `get()` which returns the raw pointer.
4. Handle move operations so ownership is moved to the assignee.
5. Disallow copying operations.
6. Implement comparison operators: operator==, operator<, operator<=, ...

# Exercise: Shared Pointer

Implement a class template for a smart pointer which allows shared ownership of arbitrary dynamically allocated objects. Your implementation should mimick the interface of raw pointers as closely as possible, however should not allow pointer arithmetic.

1. Implement a class template called `SharedPointer` in `shared_pointer.hpp` with exactly one template parameter.
2. Implement a constructor and destructor according to the RAII principle.
3. Implement operators for dereferencing the pointer operator-> and operator* as well as a method called `get()` which returns the raw pointer.
4. Handle move operations so ownership is moved to the assignee.
5. Handle copy operations so ownership is shared between the operands.
6. Implement comparison operators: operator==, operator<, operator<=, ...

# Bonus Exercise: Improving The Shared Pointer

Try to improve your implementation of the smart pointers. Here are some ideas:

1. Make the unique and shared pointer implementations compatible with C-arrays, calling array delete.
2. The shared pointer needs to allocate memory for the count separately. Can you think of a way to allocate the count together with the pointee? Hint: you may assume the pointee knows it will at some point be used with shared pointers.
3. Implement a weak pointer, similar to the implementation in the C++ standard library. Do you have to adapt the shared pointer implementation? What are the downsides of supporting weak pointers?
