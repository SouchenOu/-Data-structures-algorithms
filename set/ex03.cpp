#include <iostream>
#include <set>


using namespace std;
int main ()
{
  std::set<int> myset;
  std::set<int>::iterator it;
  std::pair<std::set<int>::iterator,bool> ret;

  // set some initial values:
  for (int i=1; i<=5; ++i) 
    myset.insert(i*10);  
std::cout << " first myset contains:\n";
  for (it=myset.begin(); it!=myset.end(); ++it)
    std::cout << ' ' << *it << endl;;
// no new element inserted because 20 is alrighdy exist
  ret = myset.insert(20);    

// "it" now points to element 20
  if (ret.second==false) 
    it = ret.first;  

  myset.insert (it,25); // max efficiency inserting
  myset.insert (it,24); // max efficiency inserting
  myset.insert (it,26); // no max efficiency inserting

  int myints[]= {5,10,15}; // 10 already in set, not inserted
  myset.insert (myints,myints+3);

  std::cout << "myset contains:";
  for (it=myset.begin(); it!=myset.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}