#include "int_array.hpp"
#include <algorithm>

IntArray::IntArray()
    // do not allocate any data for array with zero elements.
    : m_data(nullptr), m_size(0), m_capacity(0)
{
}

IntArray::IntArray(int size)
    // if an initial size is given, allocate an array which is
    // large enough to hold the data of rhs
    : m_data(new int[size]), m_size(size), m_capacity(size)
{
}

IntArray::IntArray(IntArray &&rhs)
    // we simply copy the pointer from rhs and the respective sizes
    : m_data(rhs.m_data), m_size(rhs.m_size), m_capacity(rhs.m_capacity)
{
    /* do not forget to reset rhs because destructor is still called.
	   Setting the data pointer to nullptr prevents the destructor
	   from double freeing the same block of memory. (see destructor)
	*/
    rhs.m_data = nullptr;
    rhs.m_size = 0;
    rhs.m_capacity = 0;
}

IntArray::IntArray(const IntArray &rhs)
    // allocate a new data array which is large enough to hold the data of rhs
    : m_data(new int[rhs.m_size]), m_size(rhs.m_size), m_capacity(rhs.m_size)
{
    /* copy all elements from rhs to the new array
	for (int i = 0; i < rhs.m_size; ++i)
	{
		m_data[i] = rhs.m_data[i];
	}
	*/
    // or better: use standard algorithm to copy the data:
    std::copy(rhs.m_data, rhs.m_data + rhs.m_size, m_data);
}

IntArray::~IntArray()
{
    /* delete the data array if this object is destroyed
	   otherwise we would have a memory leak.
	   Note: we do not have to check whether the array is
	   not nullptr because the delete[] operator already
	   checks that.
	*/
    delete[] m_data;
}

IntArray &IntArray::operator=(const IntArray &rhs)
{
    /* we need to check for self assignment
	   because data would be deleted below
	*/
    if (&rhs == this)
    {
        return *this;
    }

    /* if the capaticy of current array is large enough
	   to hold all elements of rhs we don't need to
	   reallocate it. Otherwise old data has to be deleted
	   and a new array has to be allocated.
	*/
    if (m_capacity < rhs.m_size)
    {
        delete[] m_data;
        m_data = new int[rhs.m_size];
        m_capacity = rhs.m_size;
    }

    m_size = rhs.m_size;

    /* copy all elements from rhs to the new array
	for (int i = 0; i < rhs.m_size; ++i)
	{
		data[i] = rhs.m_data[i];
	}
	*/
    // or better: use standard algorithm to copy the data:
    std::copy(rhs.m_data, rhs.m_data + rhs.m_size, m_data);

    // assignment operators usually return the object that has been assigned to
    return *this;
}

IntArray &IntArray::operator=(IntArray &&rhs)
{
    /* we need to check for self assignment
	because data would be deleted below
	*/
    if (&rhs == this)
    {
        return *this;
    }

    // delete prevous data if there was any
    delete[] m_data;

    // only copy the pointer, not the elements
    m_data = rhs.m_data;
    m_size = rhs.m_size;
    m_capacity = rhs.m_capacity;

    /* do not forget to reset rhs because destructor is still called.
	Setting the data pointer to nullptr prevents the destructor
	from double freeing the same block of memory. (see destructor)
	*/
    rhs.m_data = nullptr;
    rhs.m_size = 0;
    rhs.m_capacity = 0;

    // assignment operators usually return the object that has been assigned to
    return *this;
}

int IntArray::size() const
{
    return m_size;
}

const int &IntArray::operator[](int index) const
{
    // if index is negative, we access the elements starting from the back
    if (index < 0)
    {
        return m_data[index + m_size];
    }
    else
    {
        return m_data[index];
    }
}

int &IntArray::operator[](int index)
{
    // if index is negative, we access the elements starting from the back
    if (index < 0)
    {
        return m_data[index + m_size];
    }
    else
    {
        return m_data[index];
    }
}

void IntArray::append(int value)
{
    /* We try to add an element but the data array is not large enough
	   to hold the additional data. We have to increase it.*/
    if (m_size == m_capacity)
    {
        if (m_capacity == 0)
        {
            // set initial capacity
            m_capacity = 10;
        }
        else
        {
            // double the capacity by default to reduce reallocations
            m_capacity *= 2;
        }

        /* allocate new storage which is at least large enough to hold
		   hold one additional element. */
        int *newData = new int[m_capacity];

        /* move all elements from the old array to the new one
		for (int i = 0; i < size; ++i)
		{
			newData[i] = std::move(data[i]);
		}
		*/
        // or better: use standard algorithm to move the data:
        std::move(m_data, m_data + m_size, newData);

        // delete old data since it is not needed anymore
        delete[] m_data;
        // apply newly allocated data
        m_data = newData;
    }

    /* append the value to the array and increase its size
	*/
    m_data[m_size] = value;
    ++m_size;
}

void IntArray::erase(int index)
{
    /*the array will always be large enough after an element
	  is removed so no reallocations are necessary.*/

    /* move all elements after the index one element to the front
	   so current element will be overridden.
	for (int i = index + 1; i < size; ++i)
	{
		data[i - 1] = std::move(data[i]);
	}
	*/
    // or better: use standard algorithm to move the data:
    std::move(m_data + index + 1, m_data + m_size, m_data + index);

    // array will be one element smaller after erasure.
    if (m_size > 0)
    {
        --m_size;
    }
}