#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vect1{1,2,3,4};
    vector<int>::iterator iter;

    //print the first element

    iter = vect1.begin();
    cout << "vect1[0] : "<<*iter << "\n";
    // print the third element

    iter = vect1.begin() + 2;
    cout << "The third element is :" << *iter << "\n";
    // print the last element

    iter = vect1.end() - 1;
    cout << "The last element is : "<< *iter << "\n"; 


    // print all the numbers of vectors

    for(iter = vect1.begin(); iter != vect1.end(); iter++)
    {
        cout << *iter << endl;
    }



    

}