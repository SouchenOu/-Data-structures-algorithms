
/**The C++ Standard Library vector class is a class template for sequence containers, it stores elements of a given type in a linear arrangement, and allows fast random access to any element.

1. Write a C++ program to check whether numbers in a vector can be rearranged so that each number appears exactly once in a consecutive list of numbers. Return true otherwise false.*/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
    vector <int> vect1;
    int j = 0;
    int swap;
    vect1.push_back(1);
    vect1.push_back(2);
    vect1.push_back(5);
    vect1.push_back(7);
    vect1.push_back(4);
    vect1.push_back(3);
    vect1.push_back(6);
    cout << "befaure sorting our vector" << "\n";
    for(auto i = vect1.begin(); i != vect1.end(); i++)
    {
        cout << *i << "\n";
    }
    int m = 1;
    cout <<"After sorting our vector" << "\n";
    while(vect1[j] != '\0')
    {
        m = j + 1;
        while(vect1[m] != '\0')
        {
            //cout << "Here" <<vect1[j] <<"-->"<< vect1[m] << "\n";
          
                if(vect1[j] > vect1[m])
                {
                    cout << "here why" << "\n";
                    swap = vect1[j];
                    vect1[j] = vect1[m];
                    vect1[m] = swap;
                }
                m++;
        }
        cout << "Here 7 times\n";
        j++;
    }
    for(int k = 0; k < vect1.size(); k++)
    {
        cout << vect1[k] << "\n";
    }

    cout << "Check if our numbers are consecutive list of numbers\n";

    j=0;
    m=0;
    int cmp = 1;
    while(vect1[j] != '\0')
    {
        if(vect1[j] + 1 == vect1[j + 1]) 
        {
            cmp++;
        }
        j++;
    }
    if (cmp == vect1.size())
    {
        cout << "Our list is consecutive\n";
    }else
        cout << "Our list not consecutive\n";


    
}



