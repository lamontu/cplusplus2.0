
#include <iostream>

using namespace std;


namespace ff27 {

void process(int& i) {
  cout << "process(int&): " << i << endl;
}

void process(int&& i) {
  cout << "process(int&&): " << i << endl;
}

void forward(int&& i) {
  cout << "==== forward(int&&) " << i << endl;
  process(i);
  cout << "forward(int&&) ====" << endl;
}


void test27_rvalue_reference() { 
  cout << "\ntest27_rvalue_reference()........................\n";

  int a = 0;

  process(a);  // a: lvalue

  process(1);  // 1: rvalue

  process(move(a));  // move(a): rvalue

  forward(2);  // rvalue pass to forward(), lvalue pass to process() 

  // forward(a);  // Error, no matching function for call to forward
  forward(move(a));

  cout << "------------------------" << endl;

  const int& rcc(5);
  const int& rcv = a;
  // would lose const qualifier
  // process(rcc);
  // process(move(rcc));
  // process(rcv);
  // process(move(rcv));

  // int& ra(5);  // Error
  int& rb = a;
  process(rb);
  forward(move(rb));
}
};  // namespace ff27


int main(int argc, char** argv) {
  cout << __cplusplus << endl;

  ff27::test27_rvalue_reference();

  return 0;
}


