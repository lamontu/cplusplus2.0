
#include <iostream>

using namespace std;


namespace ff29 {

void process(int& i) {
  cout << "process(int&): " << i << endl;
}

void process(const int& i) {
  cout << "process(const int&): " << i << endl;
}

void process(int&& i) {
  cout << "process(int&&): " << i << endl;
}

void process(const int&& i) {
  cout << "process(const int&&): " << i << endl;
}

template<typename T>
void forward(T& val) {
  cout << "forward<T>(T&) " << val << ", ";
  process(static_cast<T&&>(val));
}

template<typename T>
void forward(T&& val) {
  cout << "forward<T>(T&&) " << val << ", ";
  process(static_cast<T&&>(val));
}

void test29_perfect_forward() { 
  cout << "\ntest29_perfect_forward()........................\n";

  int a = 0;
  const int& b = 1;
  forward(a);
  // if process(const int&&) not exist, call process(const int&), 
  forward(b);  

  forward(2);
  forward(move(a));
  // if process(const int&&) not exist, call process(const int&), 
  forward(move(b));
  forward(int(9));
}
};  // namespace ff29


int main(int argc, char** argv) {
  cout << __cplusplus << endl;

  ff29::test29_perfect_forward();

  return 0;
}


