// CPP Program to demonstrate the implementation in Map
// divyansh mishra --> divyanshmishra101010
#include <iostream>
#include <iterator>
#include <map>
using namespace std;
 
int main()
{
 
    // empty map container
    map<int, int> map1;
 
    // insert elements in random order
    map1.insert(pair<int, int>(1, 40));
    map1.insert(pair<int, int>(2, 30));
    map1.insert(pair<int, int>(3, 60));
    map1.insert(pair<int, int>(4, 20));
    map1.insert(pair<int, int>(5, 50));
    map1.insert(pair<int, int>(6, 40));
     map1.insert(pair<int, int>(4, 500));
     
      map1[7]=10;     // another way of inserting a value in a map
    // map1.insert({100,200});
    //  map1.insert({100,300});
    
 
    // printing map map1
    map<int, int>::iterator itr;
    cout << "\nThe map map1 is : \n";
    cout << "\tKEY\tELEMENT\n";
    for (itr = map1.begin(); itr != map1.end(); ++itr) {
        cout << '\t' << itr->first << '\t' << itr->second
             << '\n';
    }
    cout << endl;

    // remove all elements with key 4

    cout << "After removing element tha have key 4\n";
    int num;
    num= map1.erase(4);
    cout << "num here egal -->" << num << "\n";

    for(itr= map1.begin(); itr != map1.end(); itr++)
    {
        cout << itr->first << "\t" << itr->second << "\n";
    }




    //remove all element that his key less than 3

    map1.erase(map1.begin(), map1.find(3));
    cout << "After removing all elements that his key less than  3\n";
    for(itr = map1.begin(); itr != map1.end(); itr++)
    {
        std::cout << itr->first << "\t" << itr->second << "\n";
    }

        // size():
    cout << "Size and max_size of our map \n";
    cout << "size of our map is :" << map1.size() << "\n";
    cout << "Max size is :" << map1.max_size() << "\n";

 

    //upper bound and lower bound 

    cout << "Print upper bound and lower bound :\n";

    cout << "Upper bound for key = 5\n";

    cout << "First ->"<<map1.upper_bound(5)->first << "\tSecond -->" << map1.upper_bound(5)->second << endl;
    
    cout << "Upper bound for key = 8 that is not exist\n";

    cout << "First ->"<<map1.upper_bound(8)->first << "\tSecond -->" << map1.upper_bound(8)->second << endl;



    cout << "Lower bound for key = 5\n";

    cout << "First-->" << map1.lower_bound(5)->first << "\tSecond-->" << map1.lower_bound(5)->second << endl;

    cout << "Lower bound for key = 8 that is not exist\n";

    cout << "First-->" << map1.lower_bound(8)->first << "\tSecond-->" << map1.lower_bound(8)->second << endl;
}