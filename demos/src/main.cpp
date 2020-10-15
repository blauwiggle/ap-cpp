#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <memory>

struct Ptr
{

    std::vector<int> &operator*() const
    {
        return *m_ptr;
    }

    std::vector<int> *operator->()
    {
        return m_ptr;
    }

    explicit operator bool()
    {
        return m_ptr;
    }

    std::vector<int> *m_ptr;
};

void foo(int *ptr)
{
    std::cout << *ptr;
}

std::unique_ptr<std::vector<int>> buildVector(int size)
{

    auto v = std::make_unique<std::vector<int>>(size);

    // ...
    return v;
}

int main(int argc, char *argv[])
{
    std::vector<int> a(100000);

    auto a = buildVector(2);

    std::vector<int> v;
    v.front();

    int i = 10;
    foo(&i);

    {
        auto ptr = std::make_unique<std::vector<int>>(10);

        std::vector<int> i = *ptr;

        *ptr = {1, 2, 5};

        ptr->front(); // (*ptr).front();

        if (ptr)
        {
            return;
        }
    }

    {
        Ptr ptr;

        std::vector<int> i = *ptr;

        *ptr = {1, 2, 5};

        auto i = static_cast<bool>(ptr) + 3;
        if (ptr)
        {
        }
    }

    return 0;
}