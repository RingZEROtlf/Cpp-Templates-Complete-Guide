#include <iostream>
#include <string>
#include <utility>
#include <type_traits>

template<typename T> requires !std::is_const_v<T>
void outR(T& arg)
{
  if (std::is_array_v<T>) {
    std::cout << "got array of " << std::extent_v<T> << " elems\n";
  }
}

int main()
{
  std::string returnString();
  std::string s = "hi";
  outR(s);                  // OK: T deduced as std::string, arg is std::string&
  outR(std::string("hi"));  // ERROR: not allowed to pass a temporary (prvalue)
  outR(returnString());     // ERROR: not allowed to pass a temporary (prvalue)
  outR(std::move(s));       // ERROR: not allowed to pass an xvalue

  int arr[4];
  outR(arr);                // OK: T deduced as int[4], arg is int(&)[4]

  std::string const c = "hi";
  outR(c);                    // OK: T deduced as std::string const
  std::string const returnConstString();
  outR(returnConstString());  // OK: same if returnConstString() returns const string
  outR(std::move(c));         // OK: T deduced as std::string const
  outR("hi");                 // OK: T deduced as char const[3]
}