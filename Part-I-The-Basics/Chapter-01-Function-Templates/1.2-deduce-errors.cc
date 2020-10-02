#include <string>

template <typename T>
T max(T a, T b)
{
    return b < a ? a : b;
}

template <typename T>
void foo(T t1, T t2)
{}

int main()
{
    max(4, 7.2);        // ERROR: T can be deduced as int or double
    std::string s;
    foo("hello", s);    // ERROR: T can be deduced as char const[6] or std::string

    max(static_cast<double>(4), 7.2);   // OK
    max<double>(4, 7.2);                // OK
}