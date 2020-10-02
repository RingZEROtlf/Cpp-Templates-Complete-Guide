#include "../../basics/max1.hpp"
#include <complex>

int main()
{
    std::complex<float> c1, c2; // doesn't provide operator<
    ::max(c1, c2);              // ERROR at compile time
}