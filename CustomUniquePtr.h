#pragma once

#include <algorithm>
#include <utility>

namespace otus
{
    /**
     * @brief Special additional class, to unique store and auto deletind data
     *
     * Alanog std::unique_ptr
     * @param  <in> T is type of data
     *
     */
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
        /**
         * @brief The copy constructor has been removed. You can't copy an object
         *
         */
        CustomUniquePtr(const CustomUniquePtr<T> &ptr) = delete;
        CustomUniquePtr(CustomUniquePtr<T> &&ptr) : t(std::exchange(ptr.t, nullptr))
        {
        }

        /**
         * @brief The copy operator has been removed. You can't copy an object
         *
         */
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

        /**
         * @brief Deletion of CustomUniquePtr is caused by deletion of data
         *
         */
        ~CustomUniquePtr()
        {
            if (t)
            {
                delete t;
            }
        }

        /**
         * @brief Get data of CustomUniquePtr
         *
         * @return Pointer on data of type T
         *
         */
        T *get() const
        {
            return t;
        }
    };
}