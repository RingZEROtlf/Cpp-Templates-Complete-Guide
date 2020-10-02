template <typename T>
T max(T const& a, T const& b)
{
    return b < a ? a : b;
}