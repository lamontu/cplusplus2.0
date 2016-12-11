
#include <iostream>

using namespace std;


namespace ff19 {

struct NoCopy {
  NoCopy() = default;
  NoCopy(const NoCopy&) = delete;
  NoCopy& operator= (const NoCopy&) = delete;
  ~NoCopy() = default;
};

struct NoDtor {
  NoDtor() = default;
  ~NoDtor() = delete;
};

void test19_default_delete();

class PrivateCopy {
  friend void test19_default_delete();

 private:
  PrivateCopy(const PrivateCopy&) = default;
  PrivateCopy& operator= (const PrivateCopy&) = default;

 public:
  PrivateCopy() = default;
  ~PrivateCopy() = default;
};

struct Type1 {
  Type1() = default;
  Type1(string value) {  }
};

struct NonCopyable {
  NonCopyable() = default;
  NonCopyable(const NonCopyable&) = delete;
  NonCopyable& operator= (const NonCopyable&) = delete;
};

struct NoInt {
  void f(double d) {  }
  // void f(int) = delete
  template<class T> void f(T) = delete;

  void f2(const char* s) {
    cout << "void f2(const char*) " << s << endl;
  }
  void f2(string& s) {
    cout <<"void f2(string&) " << s << endl;
  }
};

void test19_default_delete() {
  cout << "\ntest19_default_delete()........................\n";
     
  NoCopy ncp1, ncp2;
  // ncp2 = ncp1;  // Error, overload resolution selected deleted operator '=' 


  // NoDtor nd;  // Error, attempt to use a deleted function 
  NoDtor* p = new NoDtor();
  // delete p;  // Error, attempt to use a deleted function

  PrivateCopy pc;
  PrivateCopy pc2(pc);  // OK, this function is a friend of class PrivateCopy 
  pc2 = pc;  // OK, this function is a friend of class PrivateCopy 

  Type1 tp1;
  Type1* ptp2 = new Type1;
  Type1 tp3 = Type1(); 
  tp3 = tp1;
  string str1{"hello"};
  Type1 tp4 = Type1(str1);
  Type1 tp5 = Type1(string("hello"));
  Type1 tp6{ str1 };
  Type1 tp7 = { str1 };
  Type1 tp8(str1);
  Type1 tp9 = (str1);

  NonCopyable nc1, nc2;
  // nc2 = nc2;  // Error, overload resolution selected deleted operator '=' 

  NoInt ni;
  ni.f(5.6);
  // ni.f(7);  // Error
  // ni.f('a');  // Error
  char s[20]{ "world" };
  ni.f2(s);
  string str2("hello");
  ni.f2(str2); 

  /* candidate function not viable:
   * no known conversion from string to const char *
   * candidate function not viable: 
   * expects an l-value for 1st argumet
   */
  // ni.f2(string("hello"));
}
}  // namespace ff19


int main(int argc, char** argv) {
  cout << __cplusplus << endl;

  ff19::test19_default_delete();

  return 0;
}


