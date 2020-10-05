#include "stack6decl.hpp"

template<typename T>
 template<typename T2>
Stack<T>& Stack<T>::operator=(Stack<T2> const& op2)
{
  elems.clear();                  // remove existing elements
  elems.insert(elems.begin(),     // insert at the beginning
               op2.elems.begin(), // all elemens from op2
               op2.elems.end());
  return *this;
}