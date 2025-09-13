#pragma once
#include <algorithm>
#include <utility>

namespace otus
{
    template <typename T>
    class CustomSharedPtr
    {
    private:
        T *t;

        struct Counter
        {
            int count = 1;
        };

        Counter *counter{1};

    public:
        CustomSharedPtr() : t(nullptr), counter(new Counter())
        {
        }

        CustomSharedPtr(T *t) : t(t), counter(new Counter())
        {
        }

        CustomSharedPtr<T>(const CustomSharedPtr<T> &ptr) : t(ptr.t), counter(ptr.counter)
        {
            ++counter->count;
        }

        CustomSharedPtr<T>(CustomSharedPtr<T> &&ptr) : t(std::exchange(ptr.t, nullptr)), counter(std::exchange(ptr.counter, nullptr))
        {
        }

        CustomSharedPtr<T> &operator=(const CustomSharedPtr<T> &ptr)
        {
            if (this == &ptr)
            {
                return *this;
            }

            t = ptr.t;
            counter = ptr.counter;
            ++counter->count;
            return *(this);
        }

        CustomSharedPtr<T> &operator=(CustomSharedPtr<T> &&ptr) noexcept
        {
            if (this == &ptr)
            {
                return *this;
            }

            if (counter && --counter->count == 0)
            {
                if (t)
                {
                    delete t;
                }

                delete counter;
            }

            t = std::exchange(ptr.t, nullptr);
            counter = std::exchange(ptr.counter, nullptr);

            return *this;
        }

        ~CustomSharedPtr()
        {
            if (counter && --counter->count == 0)
            {
                if (t)
                {
                    delete t;
                }
                delete counter;
            }
        }

        T *get() const
        {
            return t;
        }
    };
} // namespace otus