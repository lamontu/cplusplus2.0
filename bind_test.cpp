// http://www.cplusplus.com/reference/functional/bind/

#include <iostream>
#include <vector>

using namespace std;


namespace ff41 {

double my_divide(double x, double y) {
  return x / y;
}

struct MyPair {
  double a, b;
  double multiply() {
    return a * b;
  }
};

void test41_bind() {
  cout << "\ntest41_bind()........................\n";

  using namespace std::placeholders;

  // binding functions:
  auto fn_five = bind(my_divide, 10, 2);
  cout << fn_five() << endl;

  auto fn_half = bind(my_divide, _1, 2);
  cout << fn_half(10) << endl;

  auto fn_invert = bind(my_divide, _2, _1);
  cout << fn_invert(10, 2) << endl;

  auto fn_rounding = bind<int>(my_divide, _1, _2);
  cout << fn_rounding(10, 3) << endl;

  // binding members:
  MyPair ten_two {10, 2};

  auto bound_memfn = bind(&MyPair::multiply, _1);
  cout << bound_memfn(ten_two) << endl;

  auto bound_memdata = bind(&MyPair::a, ten_two);
  cout << bound_memdata() << endl;

  auto bound_memdata2 = bind(&MyPair::b, _1);
  cout << bound_memdata2(ten_two) << endl;
  
  vector<int> v { 15, 37, 94, 50, 73, 58, 28, 98 };
  int n = count_if(v.cbegin(), v.cend(), not1(bind2nd(less<int>(), 50)));
  cout << "n = " << n << endl;

  auto fn_ = bind(less<int>(), _1, 50);
  cout << count_if(v.cbegin(), v.cend(), fn_) << endl;
  cout << count_if(v.begin(), v.end(), bind(less<int>(), _1, 50)) << endl;
}
}  // namespace ff41


int main(int argc, char** argv) {
  cout << __cplusplus << endl;

  ff41::test41_bind();

  return 0;
}


