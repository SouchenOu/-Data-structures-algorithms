#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


int main()
{
    std::vector<int> value1 = {1,2,3,4,5};
    cout << "First method\n";
    for(int i = 0; i < value1.size(); i++)
    {
        cout << value1[i] << "\n";
    }
    cout << "Second method\n";
    for(int i : value1)
    {
        cout << i << "\n";
    }
    cout << "Third method\n";

    for (vector<int>::iterator it= value1.begin(); it != value1.end(); it++)
    {
        cout << *it << "\n";
    }
 /*****unordered_map*/

 std::unordered_map<std::string, int> map;
 map["test1"] = 1;
 map["souchen"] = 2;
 map["hello"] = 3;

 for(std::unordered_map<std::string, int> ::const_iterator t = map.begin(); t != map.end();t++)
 {  
    auto& key = t->first;
    auto& value1 = t->second;
    cout << key << " == " << value1 << "\n";

 }
 cout << "Other method\n";

 for(auto [key, value1] : map)
 {
    cout << key << " == " << "value1" << "\n";
 }
 


}