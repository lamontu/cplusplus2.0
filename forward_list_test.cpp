
#include <iostream>

#include <array>
#include <vector>
#include <deque>
#include <forward_list>
#include <list>

using namespace std;


namespace ff10 {
void test10_forward_list() {
  cout << "\ntest10_forward_list()..................\n";

  forward_list<int> fwl { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5 };
  cout << "fwl.size " << distance(fwl.begin(), fwl.end()) << endl;

  fwl.push_front(89);
  fwl.sort();
  // Error, no member named "push_back"
  // fwl.push_back(10);

  array<int, 20> arr { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5 };
  vector<int> vec { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5 };
  deque<int> deq { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5 };
  list<int> lst { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5 };


  cout << "arr.max_size " << arr.max_size() << endl;
  cout << "vec.max_size " << vec.max_size() << endl;  // 2^62 - 1
  cout << "deq.max_size " << deq.max_size() << endl;  // 2^62 - 1
  cout << "lst.max_size " << lst.max_size() << endl;  // 2^63 - 1
  cout << "fwl.max_size " << fwl.max_size() << endl;  // 2^64 - 1
}
}  // namespace ff10


int main(int argc, char** argv) {
  cout << __cplusplus << endl;

  ff10::test10_forward_list();

  return 0;
}


