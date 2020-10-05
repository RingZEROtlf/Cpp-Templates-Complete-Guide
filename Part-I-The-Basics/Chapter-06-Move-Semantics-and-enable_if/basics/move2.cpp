#include <utility>
#include <iostream>

class X {};

void g(X&) {
  std::cout << "g() for variable\n";
}

void g(X const&) {
  std::cout << "g() for constant\n";
}

void g(X&&) {
  std::cout << "g() for movable object\n";
}

// let f() perfect forward argument val to g():
template<typename T>
void f(T&& val) {
  g(std::forward<T>(val));  // val is non-const lvalue => calls g(X&)
}

int main()
{
  X v;              // create variable
  X const c;        // create constant

  f(v);             // f() for non-constant object calls f(X&) => cals g(X&)
  f(c);             // f() for constant object calls f(X const&) => calls g(X const&)
  f(X());           // f() for temporary calls f(X&&) => calls g(X&&)
  f(std::move(v));  // f() for movable variable calls f(X&&) => calls g(X&&)
}