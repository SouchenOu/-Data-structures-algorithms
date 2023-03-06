#include "iostream"
#include "map"

using namespace std;


int main()
{
std::map<std::string, int> map1;
map1.insert(std::pair<std::string,int>("one",12));
map1.insert(std::pair<std::string,int>("two",13));
map1.insert(std::pair<std::string,int>("three",110));
map1.insert(std::pair<std::string,int>("four",210));
map1.insert(std::pair<std::string,int>("five",310));
map1.insert(std::pair<std::string,int>("twelve",410));
map1.insert(std::pair<std::string,int>("eleven",510));


std::cout << map1.at("one") << endl;;
//std::cout << map1.at("hh") << endl;

}