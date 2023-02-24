#include "iostream"

using namespace std;

template <class T,typename std::enable_if<std::is_integral<T>::value,T>::type* = nullptr>
void do_stuff(T& t) 
{
  std::cout << "do_stuff integral\n";
    // an implementation for integral types (int, char, unsigned, etc.)
}

template <class T,typename std::enable_if<std::is_class<T>::value,T>::type* = nullptr>
void do_stuff(T& t) 
{
    // an implementation for class types
}


int main()
{
    int a = 24;
   do_stuff(a);
}

