#include <type_traits>
#include "lib_sfinae.h"

namespace otus
{
    class Math
    {
    public:
        static constexpr double PI = 3.141592653589793;

        template <typename T>
        static constexpr inline T Pow2(T t)
        {
            static_assert(otus::IsArithmetic<T>, "T must be arithmetic");
            return t * t;
        }
    };
}