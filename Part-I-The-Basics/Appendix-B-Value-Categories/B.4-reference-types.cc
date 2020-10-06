#include <iostream>
#include <type_traits>

int&  lvalue();
int&& xvalue();
int   prvalue();

int main()
{
  std::cout << std::is_same_v<decltype(lvalue()),  int&>  << '\n';  // yields true because result is lvalue
  std::cout << std::is_same_v<decltype(xvalue()),  int&&> << '\n';  // yields true because result is xvalue
  std::cout << std::is_same_v<decltype(prvalue()), int>   << '\n';  // yields true because result is prvalue

  int& lref1 = lvalue();    // OK: lvalue reference can bind to an lvalue
  int& lref3 = prvalue();   // ERROR: lvalue reference cannot bind to a prvalue
  int& lref2 = xvalue();    // ERROR: lvalue reference cannot bind to an xvalue

  int&& rref1 = lvalue();   // ERROR: rvalue reference cannot bind to an lvalue
  int&& rref2 = prvalue();  // OK: rvalue reference can bind to a prvalue
  int&& rref3 = xvalue();   // OK: rvalue reference can bind to an xvalue
}