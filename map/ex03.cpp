#include <iostream>
#include <map>


// check if the key in the map or not

int main()
{

    std::map<std::string, int> map;
    std::map<std::string, int> map2;

    map["one"] = 1;
    map["two"] = 2;
    map["three"] = 3;
     map["four"] = 1;
    map["five"] = 2;
    map["six"] = 3;
   

    std::map<std::string, int>::iterator iter;
    iter = map.find("one");

    map2.insert(map.begin(), map.find("four"));
    // std::cout << "printing\n";
    for(iter = map.begin(); iter != map.end(); iter++)
    {
        std::cout << iter->first << std::endl;
        std::cout << iter->second << std::endl;
    }
    std::cout << "The result\n";
    for(iter = map2.begin(); iter != map2.end(); iter++)
    {
        std::cout << iter->first << std::endl;
        std::cout << iter->second << std::endl;
    }
    //std::cout << "iter here --> " << *iter << std::endl; 

    // if(map.count("four") > 0)
    // {
    //     std::cout << "This key is in the map" << "\n";
    // }
    // else
    //     std::cout << "This key is not in the map" << "\n";

} 