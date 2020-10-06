#include <iostream>
#include <utility>

template<typename T>
void printV(T arg) {}

int main()
{
  std::string returnString();
  std::string s = "hi";
  printV(s);                  // copy constructor
  printV(std::string("hi"));  // copying usually optimized away (if not, move constructor)
  printV(returnString());     // copying usually optimized away (if not, move constructor)
  printV(std::move(s));       // move constructor

  // value decays
  std::string const c = "hi";
  printV(c);                  // c decays so that arg has type std::string

  printV("hi");               // decays to pointer so that arg has type char const*

  int arr[4];
  printV(arr);                // decays to pointer so that arg has type char int*
}