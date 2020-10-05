auto f = [](auto x, auto y) {
  return x + y;
};

class SomeCompilerSpecificName {
 public:
  SomeCompilerSpecificName();   // constructor only callable by compiler
  template<typename T1, typename T2>
  auto operator()(T1 x, T2 y) const {
    return x + y;
  }
};