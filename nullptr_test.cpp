
#include <iostream>

using namespace std;


namespace ff00 {
void f(int) {
  cout << "f(int) be called" << endl;
}

void f(void*) {
  cout << "f(void*) be called" << endl;
}

/*
 * If f(void*), f(char*) both exist, f(nullptr) will be wrong.
void f(char*) {
  cout << "f(char*) be calls" << endl;
}
 */

void test00_nullptr() {
  cout << "\ntest00_nullptr()........................\n";

  char* pchar;

  f(0);  // calls f(int)
  f(nullptr);  // calls f(void*) or calls f(char*) when only one of them exists
  f(pchar);  // calls f(void*), or calls f(char*) if f(char*) exists

/*
 * warning: comparison between NULL and non-pointer 
 * (NULL and 'int') [-Wnull-arithmetic]
  if (NULL == 0) {
    cout << "NULL == 0" << endl;
  }
 */

  if (NULL == (void *)0) {
    cout << "NULL == (void *)0" << endl;
  }

  if (NULL != (void *)1) {
    cout << "NULL != (void *)1" << endl;
  }
}
}


int main(int argc, char** argv) {
  cout << __cplusplus << endl;

  ff00::test00_nullptr();

  return 0;
}


