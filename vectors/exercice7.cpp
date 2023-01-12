#include <iostream>
#include<vector>
using namespace std;

/**Write a C++ program to create an n x n matrix by taking an 
 * integer (n) as input from the user.*/

int main()
{
    int n;
    int ligne;
    int colone;
    cout << "Input your integer value\n";
    cin >> n;
    ligne = n;
    colone = n;
    while(ligne != 0)
    {
        cout << n << " " ;
        ligne--;
    }
    cout << "\n";
    while(colone != 1)
    {
        ligne = n;
        while(ligne != 0)
        {
             cout << n << " " ;
             ligne--;
        }
        cout << "\n";
        colone--;
    }
}