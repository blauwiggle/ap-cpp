#pragma once
class IntArray
{
    // pointer to the actual data array that is stored
    int *m_data;
    // size of the data array
    int m_capacity;
    // number of element that are currently stored
    int m_size;

public:
    IntArray();
    IntArray(int size);
    // copy constructor (does not modify original object so it is passed as const)
    IntArray(const IntArray &rhs);
    // move constructor (steals data of original object so it cannot be passed as const)
    IntArray(IntArray &&rhs);

    ~IntArray();

    // getter for the size (does not modify the object, so method is const)
    int size() const;

    IntArray &operator=(const IntArray &rhs);
    IntArray &operator=(IntArray &&rhs);

    // const IntArrays should still be accessable so we need both a const and a non-const
    // version of the array access operator.
    const int &operator[](int index) const;
    int &operator[](int index);

    // append one value to the end of the IntArray
    void append(int value);
    // erase an element from the IntArray at a specific index
    void erase(int index);
};
