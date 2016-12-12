
#include <iostream>
#include <vector>

using namespace std;


namespace ff30 {

class MyString {
 private:
  char* _data;
  size_t _len;
  void _init_data(const char* s) {
    _data = new char[_len+1];
    memcpy(_data, s, _len);
    _data[_len] = '\0';
  }

 public:
  // default ctor
  MyString() : _data(nullptr), _len(0) {  }
  // ctor
  MyString(const char* p) : _len(strlen(p)) {
    _init_data(p);
  }
  // copy ctor
  MyString(const MyString& str) : _len(str._len) {
    cout << "Copy Constructor is called! source: " << str._data
         << " [" << (void*)(str._data) << "]" << endl;
    _init_data(str._data);  // COPY
  }
  // move ctor
  MyString(MyString&& str) noexcept : _data(str._data), _len(str._len) {
    cout << "Move Constructor is called! source: " << str._data
         << " [" << (void*)(str._data) << "]" << endl;
    str._len = 0;
    /* set str._data nullptr to avoid the content pointed by _data
     * deleted by dtor of str
     * but do not delete str._data
     */
    str._data = nullptr;
  }

  //  copy assignment
  MyString& operator=(const MyString& str) {
    cout << "Copy Assignment is called! source: " << str._data
         << " [" << (void*)(str._data) << "]" << endl;
    if (this != &str) {
      if (_data) delete _data;
      _len = str._len;
      _init_data(str._data);  // COPY
    } else {
      cout << "Self Assignment. Nothing to do." << endl;
    }
    return *this;
  }
  // move assignment
  MyString& operator=(MyString&& str) {
    cout << "Move Assignment is called! source: " << str._data
         << " [" << (void*)(str._data) << "]" << endl;
    if (this != &str) {
      if (_data) delete _data;
      _len = str._len;
      _data = str._data;  // MOVE
      str._len = 0;
      str._data = nullptr;
    }
    return *this;
  }
  
  // dtor
  virtual ~MyString() {
    cout << "Destructor is called! " << "source: ";
    if (_data) cout << _data;
    cout << " [" << (void*)(_data) << "]" << endl;
    if (_data) delete _data;
  }
};

void test30_move_semantics_with_noexcept() {
  cout << "\ntest30_move_semantics_with_noexcept()............\n";

  vector<MyString> vec;

  vec.push_back(MyString("lamont"));
  vec.push_back(MyString("sabrina"));
  vec.push_back(MyString("stacy"));

  cout << "vec.clear() ------ \n";
  vec.clear();
}
}  // namespace ff30


int main(int argc, char** argv) {
  cout << __cplusplus << endl;

  ff30::test30_move_semantics_with_noexcept();

  return 0;
}


