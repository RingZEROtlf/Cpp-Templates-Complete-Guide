// template <typename T>
// void f(T = "")
// {}

// int main()
// {
//     f(1);   // OK: deduced T to be int, so that it calls f<int>(1)
//     f();    // ERROR: cannot deduce T
// }

#include <string>

template <typename T = std::string>
void f(T = "")
{}

int main()
{
    f();    // OK
}