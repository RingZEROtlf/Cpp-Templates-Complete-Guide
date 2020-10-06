#include <utility>
#include <type_traits>

int main()
{
  auto b = std::make_pair(1, 2);
}

// C++98
template<typename T1, typename T2>
std::pair<T1, T2> make_pair_98(T1 const& a, T2 const& b)
{
  return std::pair<T1, T2>(a, b);
}

// C++03
template<typename T1, typename T2>
std::pair<T1, T2> make_pair_03(T1 a, T2 b)
{
  return std::pair<T1, T2>(a, b);
}

// C++11
template<typename T1, typename T2>
constexpr std::pair<typename std::decay<T1>::type,
                    typename std::decay<T2>::type>
make_pair(T1&& a, T2&& b)
{
  return std::pair<typename std::decay<T1>::type,
                   typename std::decay<T2>::type>
         (std::forward<T1>(a), std::forward<T2>(b));
}