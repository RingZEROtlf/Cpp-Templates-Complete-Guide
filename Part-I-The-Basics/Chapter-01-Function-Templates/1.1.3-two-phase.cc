template <typename T>
void foo(T t)
{
    undeclared();   // first-phase compile-time error if undeclared() unknown
    undeclared(t);  // second-phase compile-time error if undeclared(T) unknown
    static_assert(sizeof(int) > 10, "int too small");   // always fails if sizeof(int)<=10
    static_assert(sizeof(T) > 10, "T too small");       // fails if instantiated for T with size <=10
}