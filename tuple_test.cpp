
#include <iostream>
#include <complex>

using namespace std;


namespace ff07 {

template <int IDX, int MAX, typename... Args>
struct PRINT_TUPLE {
  static void print(ostream& os, const tuple<Args...>& t) {
    os << get<IDX>(t) << (IDX + 1 == MAX ? "" : ",");
    PRINT_TUPLE<IDX + 1, MAX, Args...>::print(os, t);
  }
};

template <int MAX, typename... Args>
struct PRINT_TUPLE<MAX, MAX, Args...> {
  static void print(std::ostream& os, const tuple<Args...>& t) {  }
};

template <typename... Args>
ostream& operator<< (ostream& os, const tuple<Args...>& t) {
  os << "[";
  PRINT_TUPLE<0, sizeof...(Args), Args...>::print(os, t);
  return os << "]";
}

void test07_tuples() {
  cout << "\ntest07_tuples()........................\n";

  cout << "string, sizeof = " << sizeof(string) << endl;
  cout << "double, sizeof = " << sizeof(double) << endl;
  cout << "float, sizeof = " << sizeof(float) << endl;
  cout << "int, sizeof = " << sizeof(int) << endl;
  cout << "complex<double>, sizeof = " << sizeof(complex<double>) << endl;

  tuple<string, int, int, complex<double>> t;
  cout << "tuple<string, int, int, complex<double>>, sizeof = "
       << sizeof(t) << endl;

  tuple<int, float, string> t1(41, 6.3, "nico");
  cout << "tuple<int, float, string>, sizeof = " << sizeof(t1) << endl;

  cout << "t1: "
       << get<0>(t1) << ", " << get<1>(t1) << ", " << get<2>(t1)
       << endl;

  auto t2 = make_tuple(22, 44, "stacy");
  get<1>(t1) = get<1>(t2);
  cout << get<1>(t1) << endl;

  if (t1 < t2) {
    cout << "t1 < t2" << endl;
  } else {
    cout << "t1 >= t2" << endl;
  }
  t1 = t2;
  cout << "t1: " << t1 << endl;

  tuple<int, float, string> t3(77, 1.1, "more light");
  int i1;
  float f1;
  string s1;
  tie(i1, f1, s1) = t3;
  cout << i1 << ", " << f1 << ", " << s1 << endl;

  int n = 100;
  auto t4 = tuple_cat(make_tuple(52, 7.7, "hello"), tie(n));
  const int i = 1;
  int j = 2;
  cout << get<i>(t4) << endl;
  // cout << get<j>(t4) << endl;  // Error, the value of j should be constant
  cout << t4 << endl;

  // Error, typename should be used before a nested-name-specifier.
  // typename tuple<int, float, string> TupleType;
  typedef tuple<int, float, string> TupleType;
  cout << tuple_size<TupleType>::value << endl;
  tuple_element<1, TupleType>::type fl = 1.0;
  typedef tuple_element<1, TupleType>::type T;
  cout << "Type Traits...\n";
  cout << is_void<TupleType>::value << endl;
  cout << is_const<TupleType>::value << endl;
  cout << is_floating_point<T>::value << endl;

  cout << make_tuple(7.5, string("hello"), bitset<16>(377), 42) << endl;
}
}  // namespace ff07


int main(int argc, char** argv) {
  cout << __cplusplus << endl;

  ff07::test07_tuples();

  return 0;
}


