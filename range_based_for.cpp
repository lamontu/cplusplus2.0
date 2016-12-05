
#include <iostream>
#include <vector>

using namespace std;


namespace ff05 {

void test05_range_based_for() {
  cout << "\ntest05_range_based_for()..................\n";

  for (int i : { 2, 3, 5, 7, 9, 11, 13, 17, 19 } ) {
    cout << i << ", ";
  }
  cout << endl;

  vector<double> vec {2, 3, 5, 7, 11, 13, 17};
  for (auto& elem : vec) {
    cout << (elem *= 3) << ", ";
  }
  cout << endl;

  int array[] = { 1, 2, 3, 4, 5 };
  long sum = 0;
  for (int x : array) {
    sum += x;
  }
  for (auto elem : { sum, sum * 2, sum * 4 } ) {
    cout << elem << ", ";
  }
  cout << endl;
}
}  // namespace ff05


int main(int argc, char** argv) {
  cout << __cplusplus << endl;

  ff05::test05_range_based_for(); 

  return 0;
}


