#include <iostream>
#include <vector>


// what is template

/****you can create a single function or single class to work with different data types using templates. 

*/
// What is sfinae: in c++ when we have a template and the compiler try to substitude a certain type as template argument

//Substitution failure is not an error (SFINAE) refers to a situation in C++ where an invalid substitution of template parameters is not in itself an error.

// many function with the same name but different argument

void foo(double n)
{
    std::cout << "foo(double)" << std::endl;
}
 void foo(int n)
 {
    std::cout << "foo(int)" << std::endl;
 }




// but with function template is complicated
//overlload resolution rules for function template are generalise overload resolution rules for functions so in order to determine wich function to call 
//compiler performes more steps :
//for example when we call function foo() the compiler looks for all variable functions with this name declation and this include function template

// if not suitable function is found the i issues an error but in that process of trieng to substuted template argument if it failed at some point it is not an error 
// if it failed at some point it is not an error (it issues only if variable function cant be found or two equaly good functions exist)