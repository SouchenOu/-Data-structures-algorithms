#include <iostream>


// The lesson here is that if we want to write a template that only makes sense for some types, we must make it fail deduction for invalid types right in the declaration, to cause substitution failure.

template <class T>
void foo(T)
{
    std::cout << "T is signed" << std::endl;
}

//here we check if the type of the value  is unsigned (in this case value will be true sinon will be false ) --->std::enable_if<std::is_unsigned<T>
template<class T>
void foo(T)
{
    std::cout << "T is unsigned" << std::endl;
}

int main()
{
    int x = 5;
    foo(x);
}