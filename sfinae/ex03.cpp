#include "iostream"
#include "vector"

using namespace std;

int  test(int i) 
{
  return i;
}

template <typename T>
T test(const T& t) 
{
    cout << "Template\n";
  return -T(t);
}

int main()
{
    int a = 42;
    int result;
    result = test(42);
    cout << "Result =-->" << result << endl;
    
    
}