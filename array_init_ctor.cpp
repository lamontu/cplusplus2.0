
#include <iostream>

using namespace std;


namespace ff36 {

class T {
 private:
  int intArray[6];

 public:
  T() : intArray { 6, 5, 4, 3, 2, 1 } {  }

  void print() {
    for (auto& elem : intArray) {
      cout << elem << ' ';
    }
    cout << endl;
  }
};

void test36_array_initialized_in_ctor() {
  cout << "\ntest36_array_initialized_in_ctor()......\n";

  T t;
  t.print();
}

}  // namespace ff36


int main(int argc, char** argv) {
  cout << __cplusplus << endl;

  ff36::test36_array_initialized_in_ctor();

  int arr[10] = {1, 2, 3};
  return 0;
}


