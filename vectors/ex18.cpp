#include <iostream>
#include <vector>


using namespace std;
int main ()
{
  std::vector<int> first;
  std::vector<int> second;
  std::vector<int> third;
first.push_back(10);
first.push_back(20);
first.push_back(30);
first.push_back(40);
first.push_back(50);
first.push_back(60);
first.push_back(100);
first.push_back(200);
first.push_back(300);
first.push_back(400);
first.push_back(500);
first.push_back(600);

 std::vector<int>::iterator i;
std::cout << "Befaure assign \n";
for(i = first.begin(); i != first.end(); i++)
{
    std::cout << *i << std::endl;
}
cout << "capacity befaure assign -->" << first.capacity() << endl;
cout << "size befaure assign -->" << first.size() << endl;

first.assign (7,100);             // 7 ints with a value of 100

std::cout << "After assign \n";
for(i = first.begin(); i != first.end(); i++)
{
    std::cout << *i << std::endl;
}
cout << "capacity after assign -->" << first.capacity() << endl;
cout << "size after assign -->" << first.size() << endl;

//   second.assign (it,first.end()-1); // the 5 central values of first

//   int myints[] = {1776,7,4};
//   third.assign (myints,myints+3);   // assigning from array.

  std::cout << "Size of first: " << int (first.size()) << '\n';
//   std::cout << "Size of second: " << int (second.size()) << '\n';
//   std::cout << "Size of third: " << int (third.size()) << '\n';
  return 0;
}