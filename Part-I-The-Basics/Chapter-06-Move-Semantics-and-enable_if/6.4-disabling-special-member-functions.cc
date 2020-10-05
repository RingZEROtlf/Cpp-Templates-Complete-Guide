#include <type_traits>

template<typename T>
class C
{
 public:
  // ...

  // user-define the predefined copy constructor as deleted
  // (with conversion to volatile to enable better matches)
  C(C const volatile&) = delete;

  // if T is no integral type, provide copy constructor template with better match:
  template<typename U,
           typename = std::enable_if_t<!std::is_integral_v<U>>
  C(C<U> const&) {
    // ...
  }

  // ...
};