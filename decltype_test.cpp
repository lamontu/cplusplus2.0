
#include <iostream>
#include <map>
#include <complex>
#include <deque>

using namespace std;


namespace ff18 {

template<typename T>
void test18_decltype(T obj) {
  cout << "\ntest18_decltype()........................\n";

  map<string, float>::value_type elem1;
  cout << "typeid of map<string, float>::value_type elem1 ====" << endl;
  cout << typeid(elem1).name() << endl;

  map<string, float> coll;
  decltype(coll)::value_type elem2;
  cout << "typeid of decltype(coll)::value_type elem2 ====" << endl;
  cout << typeid(elem2).name() << endl << endl;


  typedef typename decltype(obj)::iterator iType;
  typedef typename T::iterator iTypes;  // OK, same as above

  cout << "typeid of typename iterator_traits<iType>::value_type() ===="<<endl;
  // Error if using argument complex<int>(), no type named 'iterator' 
  cout << typeid(typename iterator_traits<iType>::value_type()).name() << endl;

  cout << "typeid of T obj ====" << endl;
  cout << typeid(obj).name() << endl;

  cout << "typeid of decltype(obj) anotherObj(obj) ====" << endl;
  decltype(obj) anotherObj(obj);
  cout << typeid(anotherObj).name() << endl;
}
}  // namespace ff18


int main(int argc, char** argv) {
  cout << __cplusplus << endl;

  ff18::test18_decltype(map<string, complex<double>>());
  ff18::test18_decltype(deque<double>());
  ff18::test18_decltype(string());
  // ff18::test18_decltype(complex<int>());  // Error
 
  return 0;
}


