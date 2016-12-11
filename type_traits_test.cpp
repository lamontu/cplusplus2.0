#include <iostream>
#include <typeinfo>
#include <list>
#include <string>
#include <set>
#include <complex>

using namespace std;


template<typename T>
void type_traits_output(const T& x) {
  cout << "\ntype traits for type : " << typeid(T).name()  << endl;

  cout << "====== Primary type categories: fundamental" << endl;
  cout << "is_void\t" << is_void<T>::value << endl;
  cout << "is_integral\t" << is_integral<T>::value << endl;
  cout << "is_floating_point\t"  << is_floating_point<T>::value << endl;

  cout << "====== Primary type categories: compound" << endl;
  cout << "is_pointer\t" << is_pointer<T>::value << endl;
  cout << "is_member_object_pointer\t"
       << is_member_object_pointer<T>::value << endl;
  cout << "is_member_function_pointer\t"
       << is_member_function_pointer<T>::value << endl;
  cout << "is_enum\t" << is_enum<T>::value << endl;
  cout << "is_union\t" << is_union<T>::value << endl;
  cout << "is_class\t" << is_class<T>::value << endl;
  cout << "is_array\t" << is_array<T>::value << endl;
  cout << "is_lvalue_reference\t" << is_lvalue_reference<T>::value << endl;
  cout << "is_rvalue_reference\t" << is_rvalue_reference<T>::value << endl;
  cout << "is_function\t" << is_function<T>::value << endl;

  cout << "====== Composite type" << endl;
  cout << "is_fundamental\t" << is_fundamental<T>::value << endl;
  cout << "is_compound\t" << is_compound<T>::value << endl;
  cout << "is_arithmethic\t" << is_arithmetic<T>::value << endl;
  cout << "is_member_pointer\t" << is_member_pointer<T>::value << endl;
  cout << "is_reference\t" << is_reference<T>::value << endl;
  cout << "is_scalar\t" << is_scalar<T>::value << endl;
  cout << "is_object\t" << is_object<T>::value << endl;

  cout << "====== Type properties" << endl;
  cout << "is_abstract\t" << is_abstract<T>::value << endl;
  cout << "is_const\t" << is_const<T>::value << endl;
  cout << "is_empty\t" << is_empty<T>::value << endl;
  cout << "is_literal_type\t" << is_literal_type<T>::value << endl;
  cout << "is_pod\t" << is_pod<T>::value << endl;
  cout << "is_polymorphic\t" << is_polymorphic<T>::value << endl;
  cout << "is_signed\t" << is_signed<T>::value << endl;
  cout << "is_standard_layout\t" << is_standard_layout<T>::value << endl;
  cout << "is_trivial\t" << is_trivial<T>::value << endl;
  cout << "is_trivially_copyable\t" << is_trivially_copyable<T>::value << endl;
  cout << "is_unsigned\t" << is_unsigned<T>::value << endl;
  cout << "is_volatile\t" << is_volatile<T>::value << endl;

  cout << "====== Type features" << endl;

  cout << "has_virtual_destructor\t"
       << has_virtual_destructor<T>::value << endl;
  cout << "is_destructible\t" << is_destructible<T>::value << endl;

  cout << "is_constructible\t" << is_constructible<T>::value << endl;
  cout << "is_default_constructible\t"
       << is_default_constructible<T>::value << endl;
  cout << "is_copy_constructible\t" << is_copy_constructible<T>::value << endl;
  cout << "is_move_constructible\t" << is_move_constructible<T>::value << endl;

  cout << "is_assignable\t" << is_assignable<T, T>::value << endl;
  cout << "is_copy_assignable\t" << is_copy_assignable<T>::value << endl;
  cout << "is_move_assignable\t" << is_move_assignable<T>::value << endl;

  cout << "====== Type trivial features" << endl;

  cout << "is_trivially_destructible\t"
       << is_trivially_destructible<T>::value << endl;

  cout << "is_trivially_constructible\t"
       << is_trivially_constructible<T>::value << endl;
  cout << "is_trivially_default_constructible\t"
       << is_trivially_default_constructible<T>::value << endl;
  cout << "is_trivially_copy_constructible\t"
       << is_trivially_copy_constructible<T>::value << endl;
  cout << "is_trivially_move_constructible\t"
       << is_trivially_move_constructible<T>::value << endl;

  cout << "is_trivially_assignable\t"
       << is_trivially_assignable<T, T>::value << endl;
  cout << "is_trivially_copy_assignable\t"
       << is_trivially_copy_assignable<T>::value << endl;
  cout << "is_trivially_move_assignable\t"
       << is_trivially_move_assignable<T>::value << endl;

  cout << "====== Type nothrow features" << endl;

  cout << "is_nothrow_destructible\t"
       << is_nothrow_destructible<T>::value << endl;

  cout << "is_nothrow_constructible\t"
       << is_trivially_constructible<T>::value << endl;
  cout << "is_nothrow_default_constructible\t"
       << is_nothrow_default_constructible<T>::value << endl;
  cout << "is_nothrow_copy_constructible\t"
       << is_nothrow_copy_constructible<T>::value << endl;
  cout << "is_nothrow_move_constructible\t"
       << is_nothrow_move_constructible<T>::value << endl;

  cout << "is_nothrow_copy_assignable\t"
       << is_nothrow_copy_assignable<T>::value << endl;
  cout << "is_nothrow_move_assignable\t"
       << is_nothrow_move_assignable<T>::value << endl;

  cout << "__has_trivial_assign\t" << __has_trivial_assign(T) << endl;
  cout << "__has_trivial_copy\t" << __has_trivial_copy(T) << endl;
  cout << "__has_trivial_constructor\t" << __has_trivial_constructor(T) << endl;
  cout << "__has_trivial_destructor\t" << __has_trivial_destructor(T) << endl;
}


namespace ff23 {

void test23_traits_for_string() {
  cout << "\ntest23_traits_for_string()........................\n";

  typedef iterator_traits<set<string>::iterator>::value_type T;
  cout << "iterator_traits<set<string>::iterator>::value_type ==> "
       << typeid(T).name() << endl;
  T obj("hello");
  cout << "iterator_traits<set<string>::iterator>::value_type ==> "
       << typeid(obj).name() << endl;

  // type_traits_output(complex<float>());

  // type_traits_output(list<int>());

  // type_traits_output(string());
  type_traits_output(T());
}
};  // namespace ff23


namespace ff24 {

class Foo {  // Foo is: trivial, standard_layout, POD, literal_type,
 private:
  int d1, d2;
};

void test24_traits_for_Foo() {
  cout << "\ntest23_traits_for_Foo()........................\n";

  type_traits_output(Foo());
}
};  // namespace ff24


namespace ff25 {

class Goo {  // Goo is: polymorphic, has_virtual_destructor
 public:
  virtual ~Goo() {  }
 private:
  int d1, d2;
};

void test25_traits_for_Goo() {
  cout << "\ntest25_traits_for_Goo()........................\n";

  type_traits_output(Goo());
}
};  // namespace ff25


namespace ff26 {

class Zoo {
 public:
  Zoo(int i1, int i2) : d1(i1), d2(i2) {  }
  Zoo(const Zoo&) = delete;
  Zoo(Zoo&&) = default;

  Zoo& operator= (const Zoo&) = default;
  Zoo& operator= (const Zoo&&) = delete;
  virtual ~Zoo() {  }

 private:
  int d1, d2;
};

void test26_traits_for_Zoo() {
  cout << "\ntest23_traits_for_Zoo()........................\n";

  type_traits_output(Zoo(1, 2));
}
};  // namespace ff26


int main(int argc, char** argv) {
  cout << __cplusplus << endl;

  // ff23::test23_traits_for_string();

  // ff24::test24_traits_for_Foo();

  // ff25::test25_traits_for_Goo();

  ff26::test26_traits_for_Zoo();

  return 0;
}


