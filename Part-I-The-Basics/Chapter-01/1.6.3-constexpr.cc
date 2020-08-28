#include "../../basics/maxconstexpr.hpp"
#include <array>
#include <string>

int main()
{
    int a[::max(sizeof(char), 1000u)];
    std::array<std::string, ::max(sizeof(char), 1000u)> arr;
}