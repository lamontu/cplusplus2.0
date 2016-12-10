
#include <iostream>
#include <complex>

using namespace std;


namespace ff15 {

// recursive function calling
// case1
// ...\4.9.2\include\c++\bits\predefined_oops.h
struct _Iter_less_iter {
  template<typename _Iterator1, typename _Iterator2>
  bool
  operator() (_Iterator1 __it1, _Iterator2 __it2) const {
    return *__it1 < *__it2;
  }
};

inline _Iter_less_iter
__iter_less_iter() {
  return _Iter_less_iter();
}

// ...\4.9.2\include\c++\bits\stl_algo.h
template<typename _ForwardIterator, typename _Compare>
_ForwardIterator
__max_element(_ForwardIterator __first, _ForwardIterator __last,
              _Compare __comp) {
  if (__first == __last) return __first;
  _ForwardIterator __result = __first;
  while (++__first != __last) {
    if (__comp(__result, __first)) __result = __first;
  }
  return __result;
}

template<typename _ForwardIterator>
inline _ForwardIterator
max_element(_ForwardIterator __first, _ForwardIterator __last) {
  return __max_element(__first, __last, __iter_less_iter());
}

template<typename _Tp>
inline _Tp
max(initializer_list<_Tp> __l) {
  return *max_element(__l.begin(), __l.end());
}

// case2
int maximum(int n) {
  return n;
}

template<typename... Args>
int maximum(int n, Args... args) {
  return std::max(n, maximum(args...));
}

// case3
void printf(const char *s) {
  while(*s) {
    if (*s == '%' && *(++s) != '%') {
      throw std::runtime_error("invalid format string: missing arguments");
    }
    std::cout << *s++;
  }
}


template<typename T, typename... Args>
void printf(const char* s, T value, Args... args) {
  while (*s) {
    if (*s == '%' && *(++s) != '%') {
      std::cout << value;
      printf(++s, args...);
      return;
    }
    std::cout << *s++;
  }
  throw std::logic_error("extra arguments provided to printf");
}

// case4
void printX() {  }

// specialization relative to next function
template<typename T, typename... Types>
void printX(const T& firstArg, const Types&... args) {
  cout << firstArg << endl;
  printX(args...);
}

template<typename... Types>
void printX(const Types&... args) {
  cout << "printX(const Types&... args)" << endl;
}

// case5, refer to ff07::test07_tuples()

// case6
// recursive inheritance
template<typename... Values> class tuple;
template<>class tuple<> {  };

template<typename Head, typename... Tail>
class tuple<Head, Tail...> : private tuple<Tail...> {
  typedef tuple<Tail...> inherited;
 public:
  tuple() {  }
  tuple(Head v, Tail... vtail) : m_head(v), inherited(vtail...) {  }
  Head head() { return m_head; }
  inherited& tail() { return *this; }
 protected:
  Head m_head;
};

// case7
// recursive composition
template<typename... Values> class tup;
template<> class tup<> {  };

template<typename Head, typename... Tail>
class tup<Head, Tail...> {
  typedef tup<Tail...> composited;
 protected:
  Head m_head;
  composited m_tail;

 public:
  tup() {  }
  tup(Head v, Tail... vtail) : m_head(v), m_tail(vtail...) {  }
  Head head() { return m_head; }
  composited& tail() { return m_tail; }
}; 

void test15_variadic_template() {
  cout << "\ntest15_variadic_template()........................\n";

  // case1
  cout << ff15::max( { 57, 48, 60, 100, 20, 18 } ) << endl;

  // case2
  cout << maximum(57, 48, 60, 100, 20, 18) << endl;

  // case3
  int* pi = new int;
  printf("%d %s %p %f \n", 15, "This is Ace", pi, 3.141592653);
  // Any character next to '%' is OK for function printf does not use it.
  printf("%1 %p %p %x \n", 15, "This is Ace", pi, 3.141592653);

  // case4
  cout << "printX(...) >>>> " << endl;
  printX(7.5, "hello", bitset<16>(377), 42);

  // case6
  cout << "size of short : " << sizeof(short) << endl;
  cout << "size of int : " << sizeof(int) << endl;
  cout << "size of long : " << sizeof(long) << endl;
  cout << "size of float : " << sizeof (float) << endl;
  cout << "size of double : " << sizeof(double) << endl;
  cout << "size of char* : " << sizeof(char*) << endl;
  cout << "size of string : " << sizeof(string) << endl;
  cout << "size of complex<int> : " << sizeof(complex<int>) << endl;
  cout << "size of bitset<16> : " << sizeof(bitset<16>) << endl;

  tuple<short> tpsh(3);
  cout << "size of tuple<short> : " << sizeof(tpsh) << endl;
  tuple<int> tpint(10);
  cout << "size of tuple<int> : " << sizeof(tpint) << endl;
  tuple<long> tplong(123);
  cout << "size of tuple<long> : " << sizeof(tplong) << endl;
  tuple<float> tpft(1.2);
  cout << "size of tuple<float> : " << sizeof(tpft) << endl;
  tuple<double> tpdbl(1.2);
  cout << "size of tuple<double> : " << sizeof(tpdbl) << endl;
  tuple<string> tpstr("tuple");
  cout << "size of tuple<string> : " << sizeof(tpstr) << endl;

  tuple<int, float, string> t1(41, 6.3, "nico");
  cout << "size of tuple<int,float,string> t1 : " << sizeof(t1) << endl;
  cout << t1.head() << endl;
  cout << t1.tail().head() << endl;
  cout << t1.tail().tail().head() << endl;
  tuple<string, float, int> t1_ ("nico", 6.3, 41);
  cout << "size of tuple<string,float,int> t1_ : " << sizeof(t1_) << endl;

  tuple<string, complex<int>, bitset<16>, double>
    t2("Ace", complex<int>(3, 8), bitset<16>(377), 3.1415926535);
  cout << "size of tuple<string,complex<int>,bitset<16>,double> t2 : "
       << sizeof(t2) << endl;
  cout << t2.head() << endl;
  cout << t2.tail().head() << endl;
  cout << t2.tail().tail().head() << endl;
  cout << t2.tail().tail().tail().head() << endl;

  tuple<string, complex<int>, double> 
    t3("Stacy", complex<int>(4, 9), 1.6180339);
  cout << "size of tuple<string,complex<int>,double> t3 : "
       << sizeof(t3) << endl;
  cout << t3.head() << endl;
  cout << t3.tail().head() << endl;
  cout << t3.tail().tail().head() << endl;

  // case7
  // Unknown : size of tup in composition
  tup<short> itpsh(3);
  cout << "size of tup<short> : " << sizeof(itpsh) << endl;
  tup<int> itpint(10);
  cout << "size of tup<int> : " << sizeof(itpint) << endl;
  tup<long> itplong(123);
  cout << "size of tup<long> : " << sizeof(itplong) << endl;
  tup<float> itpft(1.2);
  cout << "size of tup<float> : " << sizeof(itpft) << endl;
  tup<double> itpdbl(1.2);
  cout << "size of tup<double> : " << sizeof(itpdbl) << endl;
  tuple<string> itpstr("tuple");
  cout << "size of tup<string> : " << sizeof(itpstr) << endl;

  tup<int, float, string> it1(41, 6.3, "nico");
  cout << "size of tup<int,float,string> it1 : " << sizeof(it1) << endl;
  cout << it1.head() << endl;
  cout << it1.tail().head() << endl;
  cout << it1.tail().tail().head() << endl;
  tup<string, float, int> it1_ ("nico", 6.3, 41);
  cout << "size of tup<string,float,int> it1_ : " << sizeof(it1_) << endl;

  tup<string, complex<int>, bitset<16>, double>
    it2("Ace", complex<int>(3, 8), bitset<16>(377), 3.1415926535);
  cout << "size of tup<string,complex<int>,bitset<16>,double> it2 : "
       << sizeof(it2) << endl;
  cout << it2.head() << endl;
  cout << it2.tail().head() << endl;
  cout << it2.tail().tail().head() << endl;
  cout << it2.tail().tail().tail().head() << endl;

  tup<string, complex<int>, double> 
    it3("Stacy", complex<int>(4, 9), 1.6180339);
  cout << "size of tup<string,complex<int>,double> it3 : "
       << sizeof(it3) << endl;
  cout << it3.head() << endl;
  cout << it3.tail().head() << endl;
  cout << it3.tail().tail().head() << endl;
}
}  // namespace ff15


int main(int argc, char** argv) {
  cout << __cplusplus << endl;

  ff15::test15_variadic_template();

  return 0;
}


