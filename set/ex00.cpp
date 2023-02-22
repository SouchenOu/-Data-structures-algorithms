#include "iostream"
#include "set"

using namespace std;
int main()
{
    std::set<char>set1;
    set1.insert('s');
    set1.insert('o');
    set1.insert('u');
    set1.insert('c');

    std::set<char>::iterator it1;

    for(it1= set1.begin(); it1!= set1.end(); it1++)
    {
        std::cout << *it1 << endl;
    }


}