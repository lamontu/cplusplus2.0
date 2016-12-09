
#include <iostream>
#include <complex>

using namespace std;


namespace ff12 {

void test12_rvalue_move() {
  cout << "\ntest12_rvalue_move()........................\n";

  string s1("international");
  string s2("ization");
  string s3 = s1 + s2;
  cout << "s3 = s1 + s2 = " << s3 << endl;
  cout << "s1 = " << s1 << endl;
  cout << "s2 = " << s2 << endl;

  string s4 = move(s1) + move(s2);
  cout << "s4 = move(s1) + move(s2) = " << s4 << endl;
  cout << "s1 after move: " << s1 << endl;
  cout << "s2 after move: " << s2 << endl;

  s1 = "Hello";
  s1 + s2 = s2;  // OK, assignable
  cout << "s1: " << s1 << endl;
  cout << "s2: " << s2 << endl;
  string() = "World";

  complex<int> c1(3, 8) , c2(1, 0);
  cout << "c1: " << c1 << endl;
  cout << "c2: " << c2 << endl;
  cout << "c1 + c2 = " << c1 + c2 << endl;
  c1 + c2 = complex<int>(4, 9);  // OK, assignable

  int x = 4;
  int y = 8;
  // x + y = 10;  // Error, not assignable
}
}  // namespace ff12


int main(int argc, char** argv) {
  cout << __cplusplus << endl;

  ff12::test12_rvalue_move();

  return 0;
}


