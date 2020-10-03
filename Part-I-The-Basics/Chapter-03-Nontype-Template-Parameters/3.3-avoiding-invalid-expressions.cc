template<int I, bool B>
class C {};

C<sizeof(int) + 4, sizeof(int)==4> c1;
C<42, sizeof(int) > 4> c2;
C<42, (sizeof(int) > 4)> c3;