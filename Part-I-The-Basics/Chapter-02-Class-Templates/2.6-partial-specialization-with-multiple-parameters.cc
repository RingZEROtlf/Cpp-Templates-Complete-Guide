template<typename T1, typename T2>
class MyClass {};

// partial specialization: both template parameters have same type
template<typename T>
class MyClass<T, T> {};

// partial specialization: second type is int
template<typename T>
class MyClass<T, int> {};

// partial specialization: both template parameters are pointer types
template<typename T1, typename T2>
class MyClass<T1*, T2*> {};

int main()
{
  MyClass<int, float> mif;    // uses MyClass<T1, T2>
  MyClass<float, float> mff;  // uses MyClass<T, T>
  MyClass<float, int> mfi;    // uses MyClass<T, int>
  MyClass<int*, float*> mp;   // uses MyClass<T1*, T2*>

  MyClass<int, int> m1;       // ERROR: matches MyClass<T, T> and MyClass<T, int>
  MyClass<int*, int*> m2;     // ERROR: matches MyClass<T, T> and MyClass<T1*, T2*>
}