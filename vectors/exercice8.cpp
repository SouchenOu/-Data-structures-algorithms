#include <iostream>
#include <vector>
using namespace std;


/** Write a C++ program to capitalize the first character of each element of a given string vector. Return the new vector.*/

int main()
{
    vector <string> vect;
    int i = 0;
    int j = 0;
    vect.push_back("red");
    vect.push_back("green");
    vect.push_back("black");
    vect.push_back("white");
    vect.push_back("Pink");


    while(vect[0][i] != '\0')
    {
         if(vect[0][i] > 'a' && vect[0][i] < 'z')
         {
            vect[0][i] = vect[0][i] - 32;
         }
         i++;
    }
   
    for(j = 0; j < vect.size(); j++)
    {
        cout << vect[j] << "\n";
    } 


}