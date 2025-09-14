#pragma once
#include <algorithm>
#include <utility>

#include <iostream>

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

        Counter *counter = nullptr;

        void decrement()
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

    public:
        CustomSharedPtr() : t(nullptr), counter(new Counter())
        {
        }

        CustomSharedPtr(T *t) : t(t), counter(new Counter())
        {
        }

        CustomSharedPtr<T>(const CustomSharedPtr<T> &ptr) : t(ptr.t), counter(ptr.counter)
        {
            if (counter)
            {
                std::cout << "CustomSharedPtr<T>  " << typeid(this).name() << " count " << counter->count << "\n";
            }
            ++counter->count;
        }

        CustomSharedPtr<T>(CustomSharedPtr<T> &&ptr) : t(std::exchange(ptr.t, nullptr)), counter(std::exchange(ptr.counter, nullptr))
        {
        }

        CustomSharedPtr<T> &operator=(const CustomSharedPtr<T> &ptr)
        {
            if (counter)
            {
                std::cout << "CustomSharedPtr operator " << typeid(this).name() << " count " << counter->count << "\n";
            }

            if (this == &ptr)
            {
                return *this;
            }
            decrement();

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

            decrement();

            t = std::exchange(ptr.t, nullptr);
            counter = std::exchange(ptr.counter, nullptr);

            return *this;
        }

        ~CustomSharedPtr()
        {
            if (counter)
            {
                std::cout << "~CustomSharedPtr " << typeid(this).name() << " count " << counter->count << "\n";
            }

            decrement();
        }

        void Reset(T *t = nullptr)
        {
            decrement();
            this->t = t;
            counter = t ? new Counter() : nullptr;
        }

        T *get() const
        {
            return t;
        }
    };
} // namespace otus