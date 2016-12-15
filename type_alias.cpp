
#include <iostream>

using namespace std;


// http://en.cppreference.com/w/cpp/language/type_alias
namespace ff48 {

// type alias, identical to
// typdedef void (*func)(int, int);
using func = void(*)(int, int);

// the name 'func' now denotes a pointer to function:
void example(int, int) {  }
func fn = example;

// type alias used to hide a template parameter
template<typename CharT>
using mystring = std::basic_string<CharT, std::char_traits<CharT>>;

mystring<char> str;

// type alias can introduce a member typedef name
template<typename T>
struct Container {
  using value_type = T;  // can be used in generic programming.
};

template<typename Container>
void fn2(const Container& c) {
  typename Container::value_type n;
}

void test48_type_alias() {
  cout << "\ntest48_type_alias()........................\n";

  Container<int> c;
  fn2(c);
}
}  // namespace ff48


int main(int argc, char** argv) {
  cout << __cplusplus << endl;

  ff48::test48_type_alias();

  return 0;
}


