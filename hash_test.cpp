
#include <iostream>

using namespace std;


namespace ff50 {

void test50_hash() {
  cout << "\ntest50_hash()..................\n";

  void* pi = (void*)(new int(100));

  cout << hash<int>()(123) << endl
       << hash<long>()(123L) << endl
       << hash<string>()(string("Ace")) << endl
       << hash<char>()('A') << endl
       << hash<float>()(3.1415926535) << endl
       << hash<double>()(3.1415926535) << endl
       << hash<void*>()(pi) << endl;
}
};  // namespace ff50


int main(int argc, char** argv) {
  cout  << __cplusplus << endl;

  ff50::test50_hash();

  return 0;
}


