
namespace otus
{
    template <bool conditional, typename T>
    struct EnableIf;

    template <typename T>
    struct EnableIf<true, T>
    {
        using type = T;
    };

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