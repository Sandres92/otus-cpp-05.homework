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

            delete t;

            t = std::exchange(ptr.t, nullptr);
            return *this;
        }

        ~CustomUniquePtr()
        {
            delete t;
        }

        T *get() const
        {
            return t;
        }
        T &operator*() const
        {
            return *t;
        }
        T *operator->() const
        {
            return t;
        }
    };
}