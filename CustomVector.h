
namespace otus
{
    template <typename T>
    class CustomVector
    {
    private:
        T *array = nullptr;
        size_t size{0};
        size_t capacity{0};

    public:
        CustomVector() : array(nullptr), size(0), capacity(0)
        {
        }

        CustomVector(size_t size) : size(size), capacity(size)
        {
            array = new T[size]{};
        }

        CustomVector()
        {
            delete[] array;
        }

        void PushBack(const T &t)
        {
            if (size + 1 > capacity)
            {
                capacity *= 2;
            }
        }

        size_t Size() const noexcept
        {
            return size;
        }
    };
}