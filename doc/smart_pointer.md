# Exercise: Unique Pointer

Implement a class template for a smart pointer which guarantees single ownership of arbitrary dynamically allocated objects. Your implementation should mimick the interface of raw pointers as closely as possible, however should not allow pointer arithmetic.

1. Implement a class template called `UniquePointer` with exactly one template parameter.
2. Implement a constructor and destructor according to the RAII principle
3. Handle copy and move operations: Copying should not be allowed.
4. Implement operators for dereferencing the pointer operator-> and operator* as well as a method called `get()` which returns the raw pointer.
5. Implement comparison operators: operator==, operator<, operator<=, ...