class N {
 public:
  N();
  N(N const&) = delete; // this class is neither copyable ...
  N(N&&) = delete;      // ... nor movable
};

N make_N() {
  return N{};       // Always creates a conceptual temporay prior to C++17
}                   // In C++17, no temporary is created at this point

auto n = make_N();  // ERROR prior to C++17 because the prvalue needs a
                    // conceptual copy. OK since C++17, because n is
                    // initialized directly from the prvalue.

#include <utility>

class X {};
X v;
X const c;

void f(X const&);   // accepts an expression of any value category
void f(X&&);        // accepts prvalues and xvalues only but is a better match
                    // for those than the previous declaration

int main()
{
  f(v);             // passes a modifiable lvalue to the first f()
  f(c);             // passes a nonmodifiable lvalue to the first f()
  f(X());           // passees a prvalue (since C++17 materialized as xvalue) to the 2nd f()
  f(std::move(v));  // passes an xvalue to the second f()
}