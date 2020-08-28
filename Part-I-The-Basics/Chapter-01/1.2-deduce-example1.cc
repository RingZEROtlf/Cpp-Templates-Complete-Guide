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
    int i = 41;
    int const c = 42;
    max(i, c);      // OK: T is deduced as int
    max(c, c);      // OK: T is deduced as int
    int& ir = i;
    max(i, ir);     // OK: T is deduced as int
    int arr[4];
    foo(&i, arr);   // OK: T is deduced as int*
}