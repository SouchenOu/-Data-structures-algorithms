
#include <iostream>
#include <map>
using namespace std;
 
int main()
{
 
    // initialize container
    map<int, int> mp;
    map<int, int>::iterator i;
 
    // insert elements in random order
    mp.insert({ 2, 30 });
    mp.insert({ 1, 40 });
    mp.insert({ 3, 60 });
 
    // does not inserts key 2 with element 20
    mp.insert({ 2, 20 });
    mp.insert({ 5, 50 });
 
    // prints the elements

    for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
        cout << itr->first << '\t' << itr->second << '\n';
    }

    return 0;
}