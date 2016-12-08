
#include <iostream>
#include <unordered_set>

using namespace std;


namespace ff11 {
class Customer {
 private:

 public:
  Customer(const string& fn, const string& ln, const long& n)
    : fname(fn), lname(ln), no(n)
    {  }

  bool operator==(const Customer& c) const {
    if ( (fname == c.fname) && (lname == c.lname) && (no == c.no) ) {
      return true;
    } else {
      return false;
    }
  }

  string fname;
  string lname;
  long no;
};

ostream& operator<< (ostream& os, const Customer& c) {
  os << "Customer: " << c.fname << ' ' << c.lname << ' ' << c.no << endl;
  return os;
}

class CustomerHash1 {
 public:
  size_t operator() (const Customer& c) const {
    return hash<string>()(c.fname) +
           hash<string>()(c.lname) +
           hash<long>()(c.no);
  }
};

size_t CustomerHash2(const Customer& c) {
  return hash<string>()(c.fname) +
         hash<string>()(c.lname) +
         hash<long>()(c.no);
}

// from boost (functional/hash):
template <typename T>
inline void hash_combine (size_t& seed, const T& val) {
  seed ^= hash<T>()(val) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

// auxiliary generic functions to create a hash value using a seed
template <typename T>
inline void hash_val(size_t& seed, const T& val) {
  hash_combine(seed, val);
}

template <typename T, typename... Types>
inline void hash_val(size_t& seed, const T& val, const Types&... args) {
  hash_combine(seed, val);
  hash_val(seed, args...);
}

// auxiliary generic function
template <typename... Types>
inline size_t hash_val(const Types&... args) {
  size_t seed = 0;
  hash_val(seed, args...);
  return seed;
}

class CustomerHash3 {
 public:
  size_t operator() (const Customer& c) const {
    return hash_val(c.fname, c.lname, c.no);
  }
}; 

void test11_() {
  cout << "\ntest11_()..................\n";

  unordered_set<string> coll;
  cout << coll.max_load_factor() << endl;
  coll.max_load_factor(0.7);
  cout << coll.max_load_factor() << endl;

  Customer cer1 = Customer("Ace",   "Hou",    1L);
  Customer cer2 = Customer("Sabri", "Hou",    2L);
  Customer cer3 = Customer("Stacy", "Chen",   3L);
  Customer cer4 = Customer("Mike",  "Tseng",  4L);
  Customer cer5 = Customer("Paili", "Chen",   5L);
  Customer cer6 = Customer("Light", "Shiau",  6L);
  Customer cer7 = Customer("Shally", "Hwung", 7L);

  unordered_set<Customer, CustomerHash1> set1;
  set1.insert(cer1); 
  set1.insert(cer2); 
  set1.insert(cer3); 
  set1.insert(cer4); 
  set1.insert(cer5); 
  set1.insert(cer6); 
  set1.insert(cer7); 
  cout << "current size: " << set1.size() << endl;
  cout << "current max_size: " << set1.max_size() << endl;  // 2^61 - 1
  cout << "current load_factor: " << set1.load_factor() << endl;
  cout << "current max_load_factor: " << set1.max_load_factor() << endl;
  cout << "set1 current bucket_count: " << set1.bucket_count() << endl;
  cout << "current max_bucket_count: " << set1.max_bucket_count() << endl;
  for (unsigned i = 0; i < set1.bucket_count(); ++i) {
    cout << "bucket #" << i << " has " << set1.bucket_size(i) << " elements.\n";
  }
  cout << "Ace    located in bucket #" << set1.bucket(cer1) << "." << endl;
  cout << "Sabri  located in bucket #" << set1.bucket(cer2) << "." << endl;
  cout << "Stacy  located in bucket #" << set1.bucket(cer3) << "." << endl;
  cout << "Mike   located in bucket #" << set1.bucket(cer4) << "." << endl;
  cout << "Paili  located in bucket #" << set1.bucket(cer5) << "." << endl;
  cout << "Light  located in bucket #" << set1.bucket(cer6) << "." << endl;
  cout << "Shally located in bucket #" << set1.bucket(cer7) << "." << endl;
  for (auto& elem : set1) {
    cout << elem;
  }
  cout << endl;

  unordered_set<Customer, size_t(*)(const Customer&)> set2(20, CustomerHash2);
  set2.insert(cer1);
  set2.insert(cer2);
  set2.insert(cer3); 
  set2.insert(cer4);
  set2.insert(cer5);
  set2.insert(cer6);
  set2.insert(cer7);
  cout << "current size: " << set2.size() << endl;
  cout << "current max_size: " << set2.max_size() << endl;  // 2^61 - 1
  cout << "current load_factor: " << set2.load_factor() << endl;
  cout << "current max_load_factor: " << set2.max_load_factor() << endl;
  cout << "set2 current bucket_count: " << set2.bucket_count() << endl;
  cout << "current max_bucket_count: " << set2.max_bucket_count() << endl;
  for (unsigned i = 0; i < set2.bucket_count(); ++i) {
    cout << "bucket #" << i << " has " << set2.bucket_size(i) << " elements.\n";
  }
  cout << "Ace    located in bucket #" << set2.bucket(cer1) << "." << endl;
  cout << "Sabri  located in bucket #" << set2.bucket(cer2) << "." << endl;
  cout << "Stacy  located in bucket #" << set2.bucket(cer3) << "." << endl;
  cout << "Mike   located in bucket #" << set2.bucket(cer4) << "." << endl;
  cout << "Paili  located in bucket #" << set2.bucket(cer5) << "." << endl;
  cout << "Light  located in bucket #" << set2.bucket(cer6) << "." << endl;
  cout << "Shally located in bucket #" << set2.bucket(cer7) << "." << endl;
  for (auto& elem : set2) {
    cout << elem;
  }
  cout << endl;

  unordered_set<Customer, CustomerHash3> set3;
  set3.insert(cer1);
  set3.insert(cer2);
  set3.insert(cer3); 
  set3.insert(cer4);
  set3.insert(cer5);
  set3.insert(cer6);
  set3.insert(cer7);
  cout << "current size: " << set3.size() << endl;
  cout << "current max_size: " << set3.max_size() << endl;  // 2^61 - 1
  cout << "current load_factor: " << set3.load_factor() << endl;
  cout << "current max_load_factor: " << set3.max_load_factor() << endl;
  cout << "set3 current bucket_count: " << set3.bucket_count() << endl;
  cout << "current max_bucket_count: " << set3.max_bucket_count() << endl;
  for (unsigned i = 0; i < set3.bucket_count(); ++i) {
    cout << "bucket #" << i << " has " << set3.bucket_size(i) << " elements.\n";
  }
  cout << "Ace    located in bucket #" << set3.bucket(cer1) << "." << endl;
  cout << "Sabri  located in bucket #" << set3.bucket(cer2) << "." << endl;
  cout << "Stacy  located in bucket #" << set3.bucket(cer3) << "." << endl;
  cout << "Mike   located in bucket #" << set3.bucket(cer4) << "." << endl;
  cout << "Paili  located in bucket #" << set3.bucket(cer5) << "." << endl;
  cout << "Light  located in bucket #" << set3.bucket(cer6) << "." << endl;
  cout << "Shally located in bucket #" << set3.bucket(cer7) << "." << endl;
  for (auto& elem : set3) {
    cout << elem;
  }
  cout << endl;
  CustomerHash3 hh;
  cout << "hash code of Ace = " << hh(cer1) << endl;
  cout << "hash code of Sabri = " << hh(cer2) << endl;
  cout << "hash code of Stacy = " << hh(cer3) << endl;
  cout << "hash code of Mike = " << hh(cer4) << endl;
  cout << "hash code of Paili = " << hh(cer5) << endl;
  cout << "hash code of Light = " << hh(cer6) << endl;
  cout << "hash code of Shally = " << hh(cer7) << endl;
  cout << "bucket position of Ace = " << hh(cer1) % 11 << endl;
  cout << "bucket position of Sabri = " << hh(cer2) % 11 << endl;
  cout << "bucket position of Stacy = " << hh(cer3) % 11 << endl;
  cout << "bucket position of Mike = " << hh(cer4) % 11 << endl;
  cout << "bucket position of Paili = " << hh(cer5) % 11 << endl;
  cout << "bucket position of Light = " << hh(cer6) % 11 << endl;
  cout << "bucket positon of Shally = " << hh(cer7) % 11 << endl;
  
}
}  // namespace ff11


int main(int argc, char** argv) {
  cout << __cplusplus << endl;

  ff11::test11_();

  return 0;
}


