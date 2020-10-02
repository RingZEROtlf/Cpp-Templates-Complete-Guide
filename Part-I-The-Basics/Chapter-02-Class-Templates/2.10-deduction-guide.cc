#include <string>

template<typename T>
struct ValueWithComment {
  T value;
  std::string comment;
};

ValueWithComment(char const*, char const*)
  -> ValueWithComment<std::string>;
ValueWithComment vc2 = { "hello", "initial value" };