#include <type_traits>
#include <iostream>

int main()
{
  auto f = [](int a) { return a + 1; };
  if constexpr (std::is_lvalue_reference_v<decltype((1+2))>) {
    std::cout << "expression is lvalue\n";
  } else if constexpr (std::is_rvalue_reference_v<decltype((1+2))>) {
    std::cout << "expression is xvalue\n";
  } else {
    std::cout << "expression is prvalue\n";
  }
}