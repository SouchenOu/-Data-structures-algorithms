#include <iostream>
#include <vector>



using namespace std;
int main ()
{

std::vector<int> myvector;
myvector.push_back(10);
myvector.push_back(10);
myvector.push_back(10);
myvector.push_back(10);
myvector.push_back(10);

cout << "capacity =" << myvector.capacity() << endl;
cout << "size =" << myvector.size() << endl;

  return 0;
}