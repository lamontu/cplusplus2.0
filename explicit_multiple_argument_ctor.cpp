
#include <iostream>

using namespace std;


namespace ff04 {

struct Complex1 {
  int real, imag;

  Complex1(int re, int im=0) : real(re), imag(im) {  }

  Complex1 operator+(const Complex1& x) {
    return Complex1((real + x.real), (imag + x.imag));
  }
};

struct Complex2 {
  int real, imag;

  explicit
  Complex2(int re, int im=0) : real(re), imag(im) {  }

  Complex2 operator+(const Complex2& x) {
    return Complex2((real + x.real), (imag + x.imag));
  }
};

class P {
 public:
  P(int a, int b) {
    cout << "P(int a, int b) \n";
  }

  P(initializer_list<int>) {
    cout << "P(initializer_list<int>) \n";
  }

  explicit P(int a, int b, int c) {
    cout << "explicit P(int a, int b, int c) \n";
  }
};

void fp(const P&) {  }

void test04_explicit_multiple_argument_ctor() {
  cout << "\ntest04_explicit_multiple_argument_ctor()............\n";

  cout << "----Using '()'----" << endl;
  // P pa1 (33);  // Erro
  P pa2 (77, 5);
  P pa3(77, 5, 42);
  // pp4(77, 5, 42, 33);  // Error
  cout << "----Using '{}'----" << endl;
  P pb1 {33};
  P pb2 {77, 5};
  P pb3 {77, 5, 42};
  P pb4 {77, 5, 42, 33};
 
  cout << "----Using '= ()'----" << endl;
  /* Erro
  //P paa2 = (77, 5);
  //P paa3 = (77, 5, 42);
  */
  cout << "----Using '= {}'----" << endl;
  P pbb1 = {33};
  P pbb2 = {77, 5};
  P pbb3 = {77, 5, 42};
  P pbb4 = {77, 5, 42, 33};

  {
  Complex1 c1(12, 5);
  Complex1 c2 = c1 + 5;
  cout << "[" << c2.real << ", " << c2.imag << "i]" << endl;
  // Complex1 c3 = c1 + {2, 6}; // Error
  } 

  {
  Complex2 c1(3, 8);
  // Complex2 c2 = c1 + 3;  // Error
  Complex2 c2 {4, 0};
  c2 = c1 + c2;
  cout << "[" << c2.real << ", " << c2.imag << "i]" << endl;
  // Complex2 c3 = c1 + {2, 6}; // Error
  } 

  fp( {22} );
  fp( {47, 11} );
  fp( {47, 11, 3} );
  fp( {46, 11, 3, 4} );

}
}  // namespace ff04


int main(int argc, char** argv) {
  cout << __cplusplus << endl;

  ff04::test04_explicit_multiple_argument_ctor();

  return 0;
}


