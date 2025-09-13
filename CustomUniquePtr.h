#pragma once
#include <algorithm>
#include <utility>

namespace otus
{
    template <typename T>
    class CustomUniquePtr
    {
    private:
        T *t = nullptr;

    public:
        CustomUniquePtr() : t(nullptr)
        {
        }

        CustomUniquePtr(T *t) : t(t)
        {
        }
        CustomUniquePtr(const CustomUniquePtr<T> &ptr) = delete;
        CustomUniquePtr(CustomUniquePtr<T> &&ptr) : t(std::exchange(ptr.t, nullptr))
        {
        }

        CustomUniquePtr<T> &operator=(const CustomUniquePtr<T> &ptr) = delete;
        CustomUniquePtr<T> &operator=(CustomUniquePtr<T> &&ptr) noexcept
        {
            if (this == &ptr)
            {
                return *this;
            }

            if (t)
            {
                delete t;
            }

            t = std::exchange(ptr.t, nullptr);
            return *this;
        }

        ~CustomUniquePtr()
        {
            if (t)
            {
                delete t;
            }
        }

        T *get() const
        {
            return t;
        }
    };
}