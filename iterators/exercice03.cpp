#include <cstddef>
#include <iostream>
using namespace std;
int main()
{
    const std::size_t N = 10;
    int* a = new int[N];
    int* end = &a[N];
    for (int i = N; i > 0; --i)
        std::cout << (*(end) = i) << endl;
    delete[] a;
}