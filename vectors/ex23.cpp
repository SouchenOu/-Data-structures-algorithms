#include "iostream"
#include "vector"

using namespace std;


int main ()
{
  std::vector<int> vect1 (3,100);   // three ints with a value of 100
  std::vector<int> vect2 (5,200);   // five ints with a value of 200

  vect1.swap(vect2);

  std::cout << "vector1 contains:";
  for (unsigned i=0; i<vect1.size(); i++)
    std::cout << ' ' << vect1[i];
  std::cout << '\n';

  std::cout << "vector2 contains:";
  for (unsigned i=0; i<vect2.size(); i++)
    std::cout << ' ' << vect2[i];
  std::cout << '\n';

  return 0;
}