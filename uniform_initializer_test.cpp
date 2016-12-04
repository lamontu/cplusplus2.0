
#include <iostream>
#include <vector>
#include <complex>

using namespace std;


namespace ff02 {
void test02_uniform_initializer() {
  cout << "\ntest02_uniform_initializer()..................\n";

  int values[] {1, 2, 3};

  vector<int> v {2, 3, 5, 7, 11, 13, 17};
  vector<string> cities {
    "Berlin", "New York", "London", "Braunschweig", "Cairo", "Cologne"
  };
  complex<double> c {4.0, 3.0};
}
}  // namespace ff02


int main(int argc, char** argv) {
  cout << __cplusplus << endl;

  ff02::test02_uniform_initializer();

  return 0;
}


