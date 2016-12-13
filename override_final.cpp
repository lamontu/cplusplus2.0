
#include <iostream>

using namespace std;


namespace ff37 {

// test override

struct Base {
  virtual void vfunc(float) {  }
};

struct Derived1: Base {
  virtual void vfunc(int) {  }
};

struct Derived2: Base {
  // virtual void vfunc(int) override {  }
  virtual void vfunc(float) override {  }
};

// test final

struct BaseX final { };

// struct DerivedX: BaseX {  };  // Error

struct BaseY {
  virtual void f() final;
};

struct DerivedY: BaseY {
  // void f();  // Error
};

void test37_override_final() {
  cout << "\ntest37_override_final()........................\n";
}

}  // namespace ff37


int main(int argc, char** argv) {
  cout << __cplusplus << endl;

  ff37::test37_override_final();

  return 0;
}


