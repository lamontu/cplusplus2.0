
#include <iostream>
#include <vector>

using namespace std;


namespace ff03 {

class P {
 public:
  P(int a, int b) {
    cout << "P(int, int), a = " << a << ", b = " << b << ", " << endl;
  }
  P(initializer_list<int> initlist) {
    cout << "P(initializer_list<int>), values = ";
    for (auto i : initlist) {
      cout << i << ", " ;
    }
    cout << endl;
  }
};

void print(initializer_list<int> vals) {
  for (auto p = vals.begin(); p != vals.end(); ++p) {
    cout << *p << ", ";
  }
  cout << endl;
}

void test03_initializer_list() {
  cout << "\ntest03_initializer_list()........................\n";

  print( { 12, 3, 5, 7, 11, 13, 17 } );
 
  int i;
  int j{};
  int* p;
  int* q{};
  cout << i << ", " << j << ", " << p << ", " << q << ", " << endl;

  /* Warning: implicit conversion from 'double' to 'int'
  int x1(5.3);
  int x2 = 5.3;
  cout << x1 << ", " << x2 << ", " << endl;
  */
  char c1{7};
  char c2{65};
  cout << c1 << ", " << c2 << ", " << endl;


  /* Error: type 'double' cannot be narrowed to 'int' in initializer list.
  int x3{5.0};
  int x4={5.3};
  vector<int> v1 {1, 2.3, 4, 5.6};
  */
  vector<int> v2 {1, 2, 4, 5};
  for (auto& elem: v2) {
    cout << elem << ", ";
  }
  cout << endl;

  {
  P p(77, 5);
  P q{77, 5};
  P r{77, 5, 42};
  P s={77, 5};
  }

  {
  vector<int> v1 {2, 5, 7, 13, 69, 83, 50};
  vector<int> v2 ( { 2, 5, 7, 13, 69, 83, 50 } );
  vector<int> v3;
  v3 = {2, 5, 7, 13, 69, 83, 50};
  v3.insert(v3.begin() + 2, { 0, 1, 2, 3, 4 } );
  for (auto i: v3) {
    cout << i << ", ";
  }
  cout << endl;

  cout << max( { string("Ace"), string("Stacy"),
                string("Sabrina"), string("Barkley") } ) << ", ";
  cout << min( { string("Ace"), string("Stacy"),
                string("Sabrina"), string("Barkley") } ) << ", " << endl;
  cout << max( { 54, 16, 48, 5 } ) << ", ";
  cout << min( { 54, 16, 48, 5 } ) << ", " << endl;
  }
}
}  // namespace ff03


int main(int argc, char** argv) {
  cout << __cplusplus << endl;

  ff03::test03_initializer_list();

  return 0;
}


