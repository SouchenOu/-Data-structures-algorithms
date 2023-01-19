#include <iostream>
#include <vector>
using namespace std;

int main ()
{
  std::vector<int> vect1;
  std::vector<int> vect2;
  std::vector<int> vect3;

  vect1.assign (7,100);             // 7 ints with a value of 100

  std::vector<int>::iterator it;
  it=vect1.begin()+ 1;

  vect2.assign (it,vect1.end()-1); // the 5 central values of vect1

  int myints[] = {1776,7,4};
  vect3.assign (myints,myints+3);   // assigning from array.

    cout << "print the vect1 vector ()" << endl;
    for (int i = 0; i< vect1.size(); i++)
    {
        cout << vect1[i] << endl;
    }
    cout << "print the second vector" << endl;
    for(int j = 0; j < vect2.size(); j++)
    {
        cout << vect2[j] << endl;
    }
    cout << "print the third vector" << endl;
    for(int k = 0; k < vect3.size(); k++)
    {
        cout << vect3[k] << endl;
    }



}