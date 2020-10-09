template<typename T>
auto len(T const& t) -> decltype((void)(t.size()), T::size_type())
{
  return t.size();
}