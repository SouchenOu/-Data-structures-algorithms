#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


int main()
{
    std::vector<int> value = {1,2,3,4,5};
    cout << "First method\n";
    for(int i = 0; i < value.size(); i++)
    {
        cout << value[i] << "\n";
    }
    cout << "Second method\n";
    for(int i : value)
    {
        cout << i << "\n";
    }
    cout << "Third method\n";

    for (vector<int>::iterator it= value.begin(); it != value.end(); it++)
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
    auto& value = t->second;
    cout << key << " == " << value << "\n";

 }
 cout << "Other method\n";

 for(auto [key, value] : map)
 {
    cout << key << " == " << "value" << "\n";
 }
 


}