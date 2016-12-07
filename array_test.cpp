
#include <iostream>
#include <array>

using namespace std;


namespace ff09 {
void test09_array() {
  cout << "\ntest09_array()..................\n";

  array<int, 10> c1 = { 42 };
  array<int, 10> c2 = { { 42 } };  // OK
  for (const auto& s : c1) {
    cout << s << ", ";
  }
  cout << endl;

  array<char, 10> c3 = { 'a' };
  for (const auto& s : c3) {
    cout << s << ", ";
  }
  cout << endl;

  array<string, 2> a = { string("abc"), "xyz" };
  array<int, 3> b1{ 1, 2, 3 }; 
  array<int, 3> b2{ { 1, 2, 3 } };
  array<int, 3> ae1 = {1, 2, 3};
  array<int, 3> ae2 = { { 1, 2, 3 } };

  sort(ae1.begin(), ae1.end());
  reverse_copy(ae2.begin(), ae2.end(), ostream_iterator<int>(cout, " "));
  cout << endl;
}
}  // namespace ff09


int main(int argc, char** argv) {
  cout << __cplusplus << endl;

  ff09::test09_array();

  return 0;
}


