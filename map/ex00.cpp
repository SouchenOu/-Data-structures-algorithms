#include <iostream>
#include <map>

using namespace std;

int main()
{
    std::map<std::string, int> map;
    

    //insert map value

    map["one"] = 1;
    map["two"] = 2;
    map["three"] = 300;
    map["four"] = 100;
    map["five"] = 200;
    map["twelve"] = 400;
    map["eleven"] = 500;
   

    //get an iterator pointing to the first element in the map


    std::map<std::string, int>::iterator it = map.begin();


    while(it != map.end())
    {
        std::cout << "key: " << it->first << "\n" <<"value: " << it->second << endl;
        it++;
    }


}

