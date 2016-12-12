
#include <iostream>
#include <list>

using namespace std;


namespace ff34 {

template<typename T>
using Vec = list<T, allocator<T>>;  // template alias

template<typename First, typename Second, int Third>
class SomeType {  };
template<typename Second>
using TypedefName = SomeType<string, Second, 5>;

typedef void (*Func1)(double);  // old style
using Func2 = void(*)(double);  // New introduced syntax

void test34_alias_template() {
  cout << "\ntest34_alias_template()........................\n";

  Vec<int> coll;
  coll.push_back(10);
  coll.push_back(11);
  coll.push_back(12);

  TypedefName<string> obj;
}

}  // namespace ff34


int main(int argc, char** argv) {
  cout << __cplusplus << endl;

  ff34::test34_alias_template();

  return 0;
}


