
#include <iostream>
#include <list>

using namespace std;


namespace ff35 {

class Foo {
 public:
  int _i;

  Foo(const int& i) : _i(i) {
    cout << "Foo(i) \n";
  }
  Foo(const Foo&) {
    cout << "Foo Copy Ctor \n";
  }
  Foo& operator=(const Foo&) {
    cout << "Foo Copy Assignment \n";
    return *this;
  }
  ~Foo() {
    cout << "~Foo()" << endl;
  }
};

ostream& operator<< (ostream& os, const Foo& c) {
  os << c._i << endl;
  return os;
}

struct D {
  void operator()(int* p) {
    cout << "[deleter called]\n";  
    delete[] p;
  }
};

void test35_shared_ptr() {
  cout << "\ntest35_shared_ptr()..............................\n";

  cout << "sizeof(shared_ptr<string>) = " << sizeof(shared_ptr<string>) << endl;

  shared_ptr<Foo> sp1(new Foo(1));
  shared_ptr<Foo> sp2(sp1);

  list<shared_ptr<Foo>> lst;
  lst.push_back(sp2);
  lst.push_back(sp2);
  lst.push_back(sp2);

  cout << "sp1.use_count() = " << sp1.use_count() << endl;
  cout << "sp1.unique() = " << sp1.unique() << endl;

  for (auto& elem : lst) {
    cout << (*elem)._i << endl;
  }

  cout << "===== Modify the object by first element in share_ptr list" << endl;
  list<shared_ptr<Foo>>::iterator itr = lst.begin();
  (*(*itr))._i = 9;
  for (auto& elem : lst) {
    // All object pointed by elme changed for no copy-on-write 
    cout << (*elem)._i << endl;
    cout << elem.use_count() << endl;
  }

  cout << "===== Reset the first element of shared_ptr"
       << "pointer to another object" << endl;
  (*itr).reset(new Foo(3));
  for (auto& elem : lst) {
    cout << (*elem)._i << endl;
    cout << elem.use_count() << endl;
  }

  cout << "======" << endl;
  lst.clear();
  cout << lst.size() << endl;
  cout << "sp1.use_count() = " << sp1.use_count() << endl;
  cout << "sp2.use_count() = " << sp2.use_count() << endl;
  cout << "done \n";

  cout << "====== install deleter(should be a callable entity)" << endl;
  shared_ptr<int> sp3(new int[10], D());
}
}  // namespace ff35


int main(int argc, char** argv) {
  cout << __cplusplus << endl;

  ff35::test35_shared_ptr();

  return 0;
}


