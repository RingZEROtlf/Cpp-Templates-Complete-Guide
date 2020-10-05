#include <iostream>

template<typename T>
constexpr T pi { 3.1415926535897932385 };

int main()
{
  std::cout << pi<double> << '\n';
  std::cout << pi<float> << '\n';
}