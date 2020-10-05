#include "basics/specialmemtmp12.hpp"
#include <string>
#include <utility>

int main()
{
  std::string s = "sname";
  Person p1(s);             // init with string object => calls TMPL-CONSTR
  Person p2("tmp");         // init with string literal => calls TMPL-CONSTR
  Person p3(p1);            // ERROR
  Person p4(std::move(p1)); // OK: move Person => calls MOVE-CONST
}