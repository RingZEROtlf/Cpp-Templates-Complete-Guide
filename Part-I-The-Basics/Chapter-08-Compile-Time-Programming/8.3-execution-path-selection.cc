#include "basics/isprime14.hpp"
#include <cstddef>

// primary helper template:
template<int SZ, bool = isPrime(SZ)>
struct Helper;

// implemention if SZ is not a prime number:
template<int SZ>
struct Helper<SZ, false>
{
  // ...
};

// implemention if SZ is a prime number:
template<int SZ>
struct Helper<SZ, true>
{
  // ...
};

template<typename T, std::size_t SZ>
long foo(std::array<T, SZ> const& col1)
{
  Helper<SZ> h; // implementation depends on whether array has prime number as size
}