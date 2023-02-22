#include "iostream"
#include "map"


int main()
{
    std::map<char, int> mymap;
    std::map<char,int>::iterator it;

    mymap['a'] = 10;
    mymap['b'] = 20;
    mymap['c'] = 30;
    mymap['d'] = 40;
    mymap['e'] = 50;
    mymap['j'] = 60;
    mymap['f'] = 70;


        // remove c element
    it = mymap.find('c');
    mymap.erase(it);
     
    

    std::map<char,int>::iterator t1;

    for(t1 = mymap.begin(); t1 != mymap.end(); t1++)
    {
        std::cout<< t1->first << std::endl;
        std::cout<< t1->second << std::endl;
    }

    //remove from e element to the end of our map
    it = mymap.find('e');
    mymap.erase(it,mymap.end());
    for(t1 = mymap.begin(); t1 != mymap.end(); t1++)
    {
        std::cout<< t1->first << std::endl;
        std::cout<< t1->second << std::endl;
    }


}