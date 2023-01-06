# -Data-structures


What are C++ data structures?
-----------------------------

Data structures are formats used to organize, store, and manage data. You can use data structures to access and modify data efficiently. There are various types of data structures. The type you use will depend on the application you’re using.


Data structures generally fall under these two categories:

Linear data structures: Elements are arranged sequentially (e.g. arrays, linked lists, stacks, queues)
Non-linear data structures: Elements are not arranged sequentially, but are stored within different levels (e.g. trees, graphs)


1: Arrays

2: Graphs

3: Linked lists

4: Hash tables

5: Stacks and queues

6: Strings

7: Trees

    1: Binary trees
  
    2: Binary search trees
  
    3: Tries






1: vectors :
-----------


Vectors use a dynamically allocated array to store their elements, so they can change size, and they have other friendly features as well. Because they use a dynamically allocated array, they use contiguous storage locations which means that their elements can be accessed and traversed, and they can also be accessed randomly using indexes. However, vectors are dynamically sized, so their size can change automatically. A new element can be inserted into or deleted from any part of a vector, and automatic reallocation for other existing items in the vector will be applied. Vectors are homogeneous, so every element in the vector must be of the same type.

Vectors are a class that is available through a library called the Standard Template Library (STL), and one uses a < > notation to indicate the data type of the elements. In order to use vectors, One needs to include the vector library.

#include<vector>
    
    
<img width="874" alt="Screen Shot 2023-01-06 at 1 53 31 PM" src="https://user-images.githubusercontent.com/87101785/211016254-f930baf7-f980-4de4-b080-5bdb98399ec6.png">
    
    
    
    
                using namespace std;

                int main()
                {

                    vector<int> intvector;
                    intvector.reserve(50);

                    for (int i=0; i<50; i++)
                    {
                        intvector.push_back(i*i);
                        cout << intvector[i] << endl;
                    }
                    return 0;
                }






