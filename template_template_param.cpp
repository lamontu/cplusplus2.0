
#include <iostream>
#include <list>
#include <vector>
#include <deque>

using namespace std;

class MyString {  };
class MyStrNoMove {  };

namespace ff47 {

template<typename T>
void output_static_data(const T& myStr) {
  // output...
}

template<typename Container>
void test_moveable(Container c) {
  typedef typename iterator_traits<typename Container::iterator>::value_type
                   Valtype;
  // typedef typename Container::value_type Valtype;  // also OK

  for (long i = 0; i < 100; ++i) {
    c.insert(c.end(), Valtype());
  }
  output_static_data(*(c.begin()));

  Container c1(c);
  Container c2(move(c));
  c1.swap(c2);
}

template<typename T,
         template<typename U>
         // template<typename>  // also OK
         // template<typename T>  // Error
             class Container>
class XCls {
 private:
  Container<T> c;

 public:
  XCls() {
    for (long i = 0; i < 100; ++i) {
      c.insert(c.end(), T());
    }
    output_static_data(T());
    Container<T> c1(c);
    Container<T> c2(move(c));
    c1.swap(c2);
    cout << "Constructor is called." << endl;
  }
};

template<typename T>
using Vec = vector<T, allocator<T>>;

template<typename T>
using Lst = list<T, allocator<T>>;

template<typename T>
using Deq = deque<T, allocator<T>>;

void test47_template_template_param_vs_iterator_traits() {
  cout << "\ntest47_template_template_param_vs_iterator_traits()......\n";

  test_moveable(list<MyString>());
  test_moveable(list<MyStrNoMove>());

  test_moveable(vector<MyString>());
  test_moveable(vector<MyStrNoMove>());

  test_moveable(deque<MyString>());
  test_moveable(deque<MyStrNoMove>());

  XCls<MyString, Vec> c1;
  XCls<MyStrNoMove, Vec> c2;

  XCls<MyString, Lst> c3;
  XCls<MyStrNoMove, Lst> c4;

  XCls<MyString, Deq> c5;
  XCls<MyStrNoMove, Deq> c6;
}
}  // namespace ff47


int main(int argc, char** argv) {
  cout << __cplusplus << endl;

  ff47::test47_template_template_param_vs_iterator_traits();

  return 0;
}


