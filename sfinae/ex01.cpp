#include <iostream>
#include<vector>
#include <assert.h>


// how we can use sfinae to our advantage 


// we can use it to explicitly if we want a certain template function specialisition to be used during overload resolution  
using namespace std;


template<typename Iter>
typename Iter::value_type sum(Iter b, Iter e, typename Iter::value_type acc)
{
    std::cout << "sum 1\n";

    while(b != e)
    {
        acc += *b++;
    }
    return acc;
} 
//if two functions are suitable (for example for a vect it succided for template function that takes pointer to memory block and for a regular function)
//so how we can use sfinae for our adventage, we can use it to explicitly  state that we dont want a certain function template specialization to be used during overload resolution 
// in our case we excluded all types that dont have type member value type in its definition, in c++20 this idea replaced by concept so 

template<typename T,class = typename std::enable_if<std::is_integral<T>::value>::type>
T sum(T * b, T *e, T acc)
{
    cout << "or here\n";
    cout << "sum 2" << endl;
    while(b != e)
    {
        acc += *b++;
    }
    return acc;
}
// this is a regular function
int sum(int *b, int *e, int acc)
{
    cout << "here\n";
    cout << "sum 3 " << endl;
    while(b != e)
    {
        acc += *b++;
    }
    return acc;
}

int main()

{
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    //vector<double> vect2 {5.0,6.2,7.5};
    //auto res0 = sum(a.begin(), a.end(), 0);
    //auto res1 = sum(a.data(), a.data() + 4, 0);
    //assert(res0 == 10);
    // cout <<"Here the result is : " << sum(a.begin(), a.end(), 0) << endl;
    // cout <<"here the result of vect double " << sum(vect2.begin(), vect2.end(), 0) << endl;
    // cout << sum(a.data(), a.data() + 4, 0) << endl;
    //  cout << sum(vect2.data(), vect2.data() + 4, 0.0) << endl;

    cout << "here --> " << sum(a.data(),a.data() + 2, 1) << endl;
    return 1;
}