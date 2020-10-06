#include <string>
#include <functional>

template<typename T>
void printT(T arg) {}

int main()
{
  std::string s = "hello";
  printT(s);            // pass s by reference
  printT(std::cref(s)); // pass s "as if by reference"
}