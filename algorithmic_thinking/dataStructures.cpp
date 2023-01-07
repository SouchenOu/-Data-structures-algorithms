#include <iostream>
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

/****Objectives
 * 
To review the key ideas of computer science, programming, and problem-solving using the C++ language.

To understand abstraction and the role it plays in the problem-solving process.

To develop understanding of Big O notation and other important techniques of algorithm analysis.

To develop comfort with standard data structures including queues, stacks, and trees.

To become conversant with sorting algorithms, including the advantages and disadvantages of each.

To learn to write and analyze recursive programs, functions, and methods.

To learn to traverse and to implement linked data structures such as linked lists and trees.

*/

//shows how to iterate through a hash table in C++


int main() {
    
    unordered_map<string, string> spnumbers;

    spnumbers = { {"one","uno"},{"two","dos"},{"three","tres"},{"four","cuatro"},{"five","cinco"} };

    for (auto i=spnumbers.begin(); i!=spnumbers.end(); i++ ){
        cout << i->first << ":";
        cout << i->second << endl;
    }
}
