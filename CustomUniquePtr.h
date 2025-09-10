#include <algorithm>

namespace otus
{
    template <typename T>
    class CustomUniquePtr
    {
    private:
        T *t = nullptr;

    public:
        CustomUniquePtr<T>(const T &t) : t(t)
        {
        }
        CustomUniquePtr<T>(const CustomUniqPtr<T> &ptr) = delete;
        CustomUniquePtr<T>(CustomUniqPtr<T> &&ptr) : t(std::move(ptr.t))
        {
            ptr.t = nullptr;
        };

        CustomUniquePtr<T> &operator=(const CustomUniquePtr<T> &ptr) = delete;
        CustomUniquePtr<T> &operator=(CustomUniquePtr<T> &&ptr) noexcept
        {
            if (*(this) == ptr)
            {
                return *this;
            }

            t = std::move(ptr.t);
            ptr.t = nullptr;
            return *this;
        }

        ~CustomUniquePtr()
        {
            delete[] t;
        }
    };
}