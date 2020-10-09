#include "basics/len1.hpp"
#include <vector>
#include <iostream>
#include <memory>

int main()
{
  int a[10];
  std::cout << len(a) << '\n';      // OK: only len() for array matches
  std::cout << len("tmp") << '\n';  // OK: only len() for array matches

  std::vector<int> v;
  std::cout << len(v) << '\n';      // OK: only len() for a type with size_type matches

  int *p;
  std::cout << len(p) << '\n';      // ERROR: no matching len() function found

  std::allocator<int> x;
  std::cout << len(x) << '\n';      // ERROR: len() function found, but cannot size()
}