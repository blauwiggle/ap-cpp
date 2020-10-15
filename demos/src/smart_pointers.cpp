template <typename T>
struct SmartPointer
{
    T *m_ptr;

    explicit SmartPointer(T *ptr)
        : m_ptr(ptr)
    {
    }

    SmartPointer(SmartPointer &&);            // allow move construction
    SmartPointer &operator=(SmartPointer &&); // allow move assignment

    T *operator->() const
    {
        return m_ptr;
    }

    T &operator*() const
    {
        return *m_ptr;
    }

    T *get() const
    {
        return m_ptr;
    }

    ~SmartPointer()
    {
        delete m_ptr;
    }
};

void foo(SmartPointer<int> ptr, SmartPointer<int> ptr2)
{
}

int main(int argc, char *argv[])
{
    foo(SmartPointer<int>(new int(4)), SmartPointer<int>(new int(5)));
}