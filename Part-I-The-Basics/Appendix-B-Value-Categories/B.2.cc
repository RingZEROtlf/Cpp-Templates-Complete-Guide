int main()
{
  int x = 3;  // x here is a variable, not an lvalue. 3 is a prvalue initializing
              // the variable x.
  int y = x;  // x here is an lvalue. The evaluation of that lvalue expression does not
              // produce the value 3, but a designation of an object containing the value 3.
              // That lvalue is then converted to a prvalue, which is what initializes y.
}