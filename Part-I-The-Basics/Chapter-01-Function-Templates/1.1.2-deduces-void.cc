template <typename T>
T foo(T*) {}

int main()
{
    void* vp = nullptr;
    foo(vp);    // OK: deduces void
}