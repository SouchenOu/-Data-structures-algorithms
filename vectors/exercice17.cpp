#include<iostream>
#include<vector>
using namespace std;


int main()
{
    vector <int> vect1;
    vector <int> vect2;
     cout << "capacity here :" << vect1.capacity() << endl;
    cout << "size here :" << vect1.size() << endl;
    vect1.push_back(2);
    vect1.push_back(20);
    vect1.push_back(30);
    vect1.push_back(40);
    vect1.push_back(50);
    vect1.push_back(60);
    cout << "capacity here :" << vect1.capacity() << endl;
    cout << "size here :" << vect1.size() << endl;
   

    cout << "Our vector : " << endl;
    for(auto &i : vect1)
    {
        cout << i << endl;
    }

    vect1.resize(8 , 10);
    cout << "Our vector After resize :" << endl;

    for(auto &i : vect1)
    {
        cout << i << endl;
    }

    
    
}