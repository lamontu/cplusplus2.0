
#include <iostream>
#include <vector>

using namespace std;


namespace ff06 {

function<int(int, int)> returnLambda () {
  return [] (int x, int y) {
           return x * y;
         };
} 

void test06_lambda() {
  cout << "\ntest06_lambda()........................\n";

  auto lf = returnLambda();
  cout << lf(9, 8) << endl;

   // decltype(lf)(3);  // Error
   // decltype(lf)(3, 5);  // Error
  decltype(lf)();

  [] {
      cout << "hello lambda" << endl;
      static int x = 5;
      int y = 6;
      return x;
  }();

  {
  int id = 0;
  auto f = [id] () mutable  {
      cout << "id: " << id << endl;
      ++id;
  };
  id = 42;
  f();
  f();
  f();
  cout << id << endl;
  // decltype(f)(3, 5);  // Error
  // decltype(f)();  // Error
  }

  {
  int id = 0;
  auto f = [&id] (int param) {
      cout << "id: " << id << endl;
      ++id;
      ++param;
  };
  id = 42;
  f(7);
  f(7);
  f(7);
  cout << id << endl;
  }

  vector<int> vi { 5, 28, 50, 83, 70, 590, 245, 59, 24 };
  int x = 30;
  int y = 100;
  vi.erase(remove_if(vi.begin(), vi.end(),
                     [x, y] (int n) { return x < n && n < y; } ),
           vi.end()
          );
  for (auto i : vi) {
    cout << i << ", ";
  }
  cout << endl;
}
}  // namespace ff06


int main(int argc, char** argv) {
  cout << __cplusplus << endl;

  ff06::test06_lambda(); 

  return 0;
}


