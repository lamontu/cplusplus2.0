
#include <iostream>

#include <array>
#include <vector>
#include <list>
#include <forward_list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;


namespace ff31 {

void test31_containers_size() {
  cout << "\ntest31_containers_size()........................\n";

  cout << "containers size: \n";
  cout << sizeof(array<int, 10>) << endl
       << sizeof(vector<int>) << endl
       << sizeof(list<int>) << endl
       << sizeof(forward_list<int>) << endl
       << sizeof(deque<int>) << endl
       << sizeof(stack<int>) << endl
       << sizeof(queue<int>) << endl;
  cout << sizeof(set<int>) << endl
       << sizeof(multiset<int>) << endl
       << sizeof(map<int, string>) << endl
       << sizeof(multimap<int, string>) << endl;
  cout << sizeof(unordered_set<int>) << endl
       << sizeof(unordered_multiset<int>) << endl
       << sizeof(unordered_map<int, string>) << endl
       << sizeof(unordered_multimap<int, string>) << endl;

  cout << "iterators size: \n";
  cout << sizeof(array<int, 10>::iterator) << endl
       << sizeof(vector<int>::iterator) << endl
       << sizeof(list<int>::iterator) << endl
       << sizeof(forward_list<int>::iterator) << endl
       << sizeof(deque<int>::iterator) << endl;
  // cout << sizeof(stack<int>::iterator) << endl;  // Error, no iterator
  // cout << sizeof(queue<int>::iterator) << endl;  // Error, no iterator
  cout << sizeof(set<int>::iterator) << endl
       << sizeof(multiset<int>::iterator) << endl
       << sizeof(map<int, string>::iterator) << endl
       << sizeof(multimap<int, string>::iterator) << endl;
  cout << sizeof(unordered_set<int>::iterator) << endl
       << sizeof(unordered_multiset<int>::iterator) << endl
       << sizeof(unordered_map<int, string>::iterator) << endl
       << sizeof(unordered_multimap<int, string>::iterator) << endl;
}
}  // namespace ff31


int main(int argc, char** argv) {
  cout << __cplusplus << endl;

  ff31::test31_containers_size();

  return 0;
}


