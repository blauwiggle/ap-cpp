# Exercise: Int Array

This exercise consists of two parts for implementing a dynamic array. In the first part the basic functionality of the dynamic array should be implemented. In the second part, the type should be extended to support value semantics (copying, moving).

There are unit tests provided by the `int_array_tests` CMake target so you can test your implementation using the tests. There is also a main function which you can use for ad-hoc testing of your implementation.

## Basics

Implement a class `IntArray`, which implements a dynamic array of `int`-values and a
program which uses the class and tests the implemented methods. The class `IntArray`
should use a pointer to dynamically allocated memory to store the data. The array should resize itself, when necessary.

The class `IntArray` should implement the following methods:

1. A Default-Constructor and a constructor expecting the initial size of the array as input parameter.
2. A method size(), which returns the number of elements stored in the array.
3. An overloaded operator [] for accessing the elements of the array (usable for read- and for write-operations!!).
4. Destructor
5. A method append(int value) for appending values at the end of the array
6. A method erase(int index) which removes values anywhere in the list
7. Try to implement a strategy for reducing dynamic memory allocations when appending to the vector.

## Value Type Semantics

The `IntArray` from the previous excercise is missing value semantics. If an `IntArray` object is assigned to another, a double-free occurs since the destructor of both `IntArray`s deletes the same memory location. Extend the `IntArray` with value type semantics by implementing copy and move operations.

The class `IntArray` should implement the following constructors and operators:

1. Copy-Constructor which allocates storage and copies data
2. Copy-Assignment-Operator which frees allocated storage of the assignee, allocates storage and copies data
3. Move-Constructor which handles object destruction
4. Move-Assignment-Operator which frees allocated storage of the assignee and handles object destruction