
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
            int count = 0;
        };

        Counter *counter{0};

    public:
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
            ++(counter->count);
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
                delete t;
                delete counter;
            }

            t = std::exchange(ptr.t, nullptr);
            counter = std::exchange(ptr.counter, nullptr);

            return *this;
        }

        ~CustomSharedPtr()
        {
            --counter->count;
            if (counter->count == 0)
            {
                delete t;
                delete counter;
            }
        }
    };
} // namespace otus