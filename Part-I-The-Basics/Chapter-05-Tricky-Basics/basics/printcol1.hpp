#pragma once

#include <iostream>

// print elements of an STL container
template<typename T>
void printcol1(T const& col1)
{
  typename T::const_iterator pos;             // iterator to iterate over col1
  typename T::const_iterator end(col1.end()); // end position
  for (pos = col1.begin(); pos != end; ++pos) {
    std::cout << *pos << ' ';
  }
  std::cout << '\n';
}