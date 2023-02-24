#include "iostream"

using namespace std;

template <typename T>
class vec 
{
    public:
        vec(T n, T val);

     template <class InputIterator,typename std::enable_if<std::iterator<T>::value>::type>
     vec(InputIterator first, InputIterator last);


 

};

int main()
{
    vec<int> v1(4, 8);
}