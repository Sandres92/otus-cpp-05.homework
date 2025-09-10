
#include <algorithm>

template <typename T>
class CustomSharedPtr
{
private:
    T *t;

    struct Counter
    {
        int count = 0;
    };

    Counter *counter{0};

public:
    CustomSharedPtr(T *t) : t(t), counter(new Counter())
    {
    }

    CustomSharedPtr<T>(const CustomSharedPtr<T> &ptr) : t(ptr.t), counter(ptr.counter)
    {
        ++(*counter.count);
    }

    CustomSharedPtr<T>(CustomSharedPtr<T> &&ptr) : t(std::move(ptr.t)), counter(std::move(ptr.counter)) noexcept
    {
        ptr.t = nullptr;
        ptr.counter = nullptr;
    }

    CustomUniquePtr<T> &operator=(const CustomUniquePtr<T> &ptr)
    {
        if (*(this) == ptr)
        {
            return *(this);
        }

        t = ptr.t;
        counter = ptr.counter;
        ++(*counter.count);
    }

    CustomUniquePtr<T> &operator=(const CustomUniquePtr<T> &ptr)
    {
        if (*(this) == ptr)
        {
            return *(this);
        }

        t = std::move(ptr.t);
        counter = std::move(ptr.counter);
        ptr.t = nullptr;
        ptr.counter = nullptr;
    }

    ~CustomSharedPtr()
    {
        --counter.count;
        if (counter.count == 0)
        {
            delete[] t;
            delete t;
        }
    }
};
