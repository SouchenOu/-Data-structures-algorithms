/**2. Write a C++ program that returns the elements in a vector that are strictly smaller than their adjacent left and right neighbours*/
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector <int> vect1;
    int i = 0;
    vect1.push_back(1);
    vect1.push_back(2);
    vect1.push_back(5);
    vect1.push_back(2);
    vect1.push_back(3);
    vect1.push_back(1);
    vect1.push_back(7);
    while(vect1[i])
    {
        if(vect1[i] < vect1[i -1] && vect1[i] < vect1[i + 1])
        {
            cout << vect1[i] << "\n";
        }
        i++;
    }



}
