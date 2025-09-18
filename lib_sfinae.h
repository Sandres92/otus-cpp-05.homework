
#pragma once

namespace otus
{
    /**
     * @brief Sfinae functions
     *
     * This .h file contains some functions, to
     * detect contains functions that check whether the incoming type is a digit.
     *
     */
    template <bool conditional, typename T>
    struct EnableIf;

    template <typename T>
    struct EnableIf<true, T>
    {
        using type = T;
    };

    /**
     * @brief If type not belongs to type bellow, in means type is not digit
     *
     *
     */
    template <typename T>
    struct IsArithmetic
    {
        static constexpr bool value = false;
    };
    template <>
    struct IsArithmetic<bool>
    {
        static constexpr bool value = true;
    };
    template <>
    struct IsArithmetic<char>
    {
        static constexpr bool value = true;
    };
    template <>
    struct IsArithmetic<unsigned char>
    {
        static constexpr bool value = true;
    };
    template <>
    struct IsArithmetic<short>
    {
        static constexpr bool value = true;
    };
    template <>
    struct IsArithmetic<unsigned short>
    {
        static constexpr bool value = true;
    };
    template <>
    struct IsArithmetic<long>
    {
        static constexpr bool value = true;
    };
    template <>
    struct IsArithmetic<unsigned long>
    {
        static constexpr bool value = true;
    };
    template <>
    struct IsArithmetic<int>
    {
        static constexpr bool value = true;
    };
    template <>
    struct IsArithmetic<unsigned int>
    {
        static constexpr bool value = true;
    };
    template <>
    struct IsArithmetic<float>
    {
        static constexpr bool value = true;
    };
    template <>
    struct IsArithmetic<double>
    {
        static constexpr bool value = true;
    };
    template <>
    struct IsArithmetic<long double>
    {
        static constexpr bool value = true;
    };
}