#pragma once

#include <type_traits>
#include "lib_sfinae.h"

namespace otus
{
    /**
     * @brief Custom math library
     *
     */
    class Math
    {
    public:
        static constexpr double PI = 3.141592653589793;

        /**
         * @brief Calculating the square of a number
         *
         * @param <in> Number with type T. type of number: int, double, float etc.
         *
         */
        template <typename T>
        static constexpr inline T Pow2(T t)
        {
            static_assert(otus::IsArithmetic<T>::value, "T must be arithmetic");
            return t * t;
        }
    };
}