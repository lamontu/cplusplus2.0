
#include <iostream>

using namespace std;


namespace ff45 {

class Foo {
 private:
  int _i;

 public:
  Foo(int i) : _i(i) {  }
  Foo() = default;

  Foo(const Foo& x) : _i(x._i) {  }
  // Foo(const Foo& x) = default;  // Error
  // Foo(const Foo& x) = delete;  // Error

  Foo& operator=(const Foo& x) {
    _i = x._i;
    return *this;
  }
  // Foo& operator=(const Foo& x) = default;  // Error 
  // Foo& operator=(const Foo& x) = delete;  // Error

  void func1() = delete;
  // void func2() = default;  // Error

  ~Foo() = default;
  // ~Foo() = delete;  // Error

};

void test45_default_and_delete() {
  cout << "\ntest45_default_and_delete()..................\n";

  Foo f1(5);
  Foo f2;
  Foo f3(f1);
  f3 = f2;
}
}  // namespace ff45


int main(int argc, char** argv) {
  cout << __cplusplus << endl;

  ff45::test45_default_and_delete();
  
  return 0;
}


