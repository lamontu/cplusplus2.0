
#include <iostream>
#include <vector>
using namespace std;


namespace ff01 {
double func() {
  return 0;
}

void test01_auto() {
  cout << "\ntest01_auto()........................\n";

  auto i = 42;
  auto d = func();

  vector<string> vs;
  auto pos = vs.begin();

  auto l = [] (int x) -> bool {
    return 1 == 1;
  };
}
}  // namespace ff01


int main(int argc, char** argv) {
  cout << __cplusplus << endl;

  ff01::test01_auto();

  return 0;
}


