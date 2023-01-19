#include <iostream>
#include <vector>

using namespace std;



int main()
{
    vector<int> vect{1,2,3,4};
    // ranged loop

    for(const int & i : vect)
    {
        cout << i << "\n";
    }
    cout << "**************\n" << endl;
    // add new element
    vect.push_back(23);
    vect.push_back(24);
    vect.resize(2);
    // After updating

    for(int j = 0; j < vect.size(); j++)
    {
        cout << vect[j] << "\n";
    }
    /*Access Elements of a Vector
    cout << "Give me the element at position 3 --->" << vect.at(3) << endl;
    cout << "size of this vect is : " << vect.size() << endl;
    cout << "max size of this vect is :" << vect.max_size() << endl;
    cout << "Impliment function at :" << vect.at(2) << endl;*/


}