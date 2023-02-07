#include <iostream>
#include <map>


// check if the key in the map or not

int main()
{

    std::map<std::string, int> map;

    map["one"] = 1;
    map["two"] = 2;
    map["three"] = 3;

    if(map.count("four") > 0)
    {
        std::cout << "This key is in the map" << "\n";
    }
    else
        std::cout << "This key is not in the map" << "\n";

} 