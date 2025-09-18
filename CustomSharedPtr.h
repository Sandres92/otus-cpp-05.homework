#pragma once
#include <algorithm>
#include <utility>

#include <iostream>

namespace otus
{
    /**
     * @brief Special additional class, to unique shared and auto deletind data
     *
     * Alanog std::unique_ptr
     * @param  <in> T is type of data
     *
     */
    template <typename T>
    class CustomSharedPtr
    {
    private:
        T *t;

        /**
         * @brief additional class, to counter of shared ptr
         *
         */
        struct Counter
        {
            int count = 1;
        };

        Counter *counter = nullptr;

        /**
         * @brief Reduces the data storage counter. Delete data if counter has been zero
         *
         */
        void decrement()
        {
            if (counter && --counter->count == 0)
            {
                // std::cout << "~Destroyed!! " << typeid(this).name() << " count " << counter->count << "\n";

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

        /**
         * @brief Copy data and counter, and increment counter
         *
         */
        CustomSharedPtr<T>(const CustomSharedPtr<T> &ptr) : t(ptr.t), counter(ptr.counter)
        {
            ++counter->count;
        }

        /**
         * @brief Copy data and counter, but delete data from <in> object
         *
         */
        CustomSharedPtr<T>(CustomSharedPtr<T> &&ptr) : t(std::exchange(ptr.t, nullptr)), counter(std::exchange(ptr.counter, nullptr))
        {
        }

        /**
         * @brief Copy data and counter, and increment counter
         *
         */
        CustomSharedPtr<T> &operator=(const CustomSharedPtr<T> &ptr)
        {
            // if (counter)
            //{
            //     //std::cout << "CustomSharedPtr operator " << typeid(this).name() << " count " << counter->count << "\n";
            // }

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

        /**
         * @brief Copy data and counter, but delete data from <in> object
         *
         */
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
            // if (counter)
            //{
            //     std::cout << "~CustomSharedPtr " << typeid(this).name() << " count " << counter->count << "\n";
            // }

            decrement();
        }

        /**
         * @brief decrement counter
         *
         */
        void Reset(T *t = nullptr)
        {
            decrement();
            this->t = t;
            counter = t ? new Counter() : nullptr;
        }

        /**
         * @brief Take the number of owners of the object
         *
         * @return number of owners
         *
         */
        int use_count() const
        {
            return counter ? counter->count : 0;
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
} // namespace otus