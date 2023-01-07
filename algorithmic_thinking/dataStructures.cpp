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




/**We will begin our study of data structures by considering four simple but very powerful concepts. Vectors, stacks, queues, deques are examples of data collections whose items are ordered depending on how they are added or removed. Once an item is added, it stays in that position relative to the other elements that came before and came after it. Collections such as these are often referred to as linear data structures.

Linear structures can be thought of as having two ends. Sometimes these ends are referred to as the “left” and the “right” or in some cases the “front” and the “rear.” You could also call them the “top” and the “bottom.” The names given to the ends are not significant. What distinguishes one linear structure from another is the way in which items are added and removed, in particular the location where these additions and removals occur. For example, a structure might allow new items to be added at only one end. Some structures might allow items to be removed from either end.

These variations give rise to some of the most useful data structures in computer science. They appear in many algorithms and can be used to solve a variety of important problems.*/
int main() {
    
    unordered_map<string, string> spnumbers;

    spnumbers = { {"one","uno"},{"two","dos"},{"three","tres"},{"four","cuatro"},{"five","cinco"} };

    for (auto i=spnumbers.begin(); i!=spnumbers.end(); i++ ){
        cout << i->first << ":";
        cout << i->second << endl;
    }
};
