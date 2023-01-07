# -Data-structures



Polimorphisme:
-------------


Le mot polymorphisme signifie avoir plusieurs formes. En général, le polymorphisme se produit lorsqu’il existe une hiérarchie de classes et qu’elles sont liées par héritage.











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


2: Strings:
-----------
                                                    
     Strings are sequential collections of zero or more characters such as letters, numbers and other symbols. There are actually two types of strings in C++ . The C++ string or just string from the <string> library is the more modern type. The old style C-string which is essentially an array of char type. The char type itself is actually distinct from both types of strings.        
    
    
    <img width="883" alt="Screen Shot 2023-01-06 at 2 32 51 PM" src="https://user-images.githubusercontent.com/87101785/211022498-fb26c89a-e8de-4f95-b568-7e146c33781d.png">

                    
                //shows basic string usage in C++
                #include <iostream>
                #include <string>
                using namespace std;

                int main()
                {

                    string mystring1 = "Hello";
                    string mystring2 = "World!";
                    string mystring3;

                    mystring3 = mystring1 + " " + mystring2;
                    cout << mystring3 << endl;

                    cout << mystring2 << " begins at ";
                    cout << mystring3.find(mystring2) << endl;

                    return 0;
                }

    
    
            Result:
    
            Hello World!
    
            World! begins at 6

3:  Hash Tables:
---------------
    
    
    A hash table is a collection of associated pairs of items where each pair consists of a key and a value. Hash tables are often called the more general term map because the associated hash function “maps” the key to the value. Nevertheless, it is better to use the more precise term, hash table because other kinds of maps are sometimes implemented with a different underlying data structure.

Each hash table has a hash function which given the key as input to the hash function returns the location of the associated value as the output. This makes look up fast.

In C++, the unordered_map implements the hash table, and the <unordered_map> library must be included as follows:

#include <unordered_map>
    

    
                //shows how hash tables can be used in C++
                #include <iostream>
                #include <unordered_map>
                #include <string>
                using namespace std;

                int main() 
                {
                    unordered_map<string, string> spnumbers;

                    spnumbers = { {"one", "uno"}, {"two", "dos"} };
    
                    spnumbers["three"] = "tres";
                    spnumbers["four"] = "cuatro";

                    cout << "one is ";
                    cout << spnumbers["one"] << endl;

                    cout << spnumbers.size() << endl;
                }
    
    
    
                    //shows how to iterate through a hash table in C++
                    #include <iostream>
                    #include <unordered_map>
                    #include <string>
                    using namespace std;

                    int main() 
                    {
                        unordered_map<string, string> spnumbers;

                        spnumbers = { {"one","uno"},{"two","dos"},{"three","tres"},{"four","cuatro"},{"five","cinco"} };

                        for (auto i=spnumbers.begin(); i!=spnumbers.end(); i++ )
                        {
                                 cout << i->first << ":";
                                 cout << i->second << endl;
                        }
                    }

    
            Result:
    
                five:cinco
    
                four:cuatro
    
                three:tres
    
                two:dos
    
                one:uno
                
                
                
                
                
                
 What Are Linear Structures?
 ---------------------------------
 
We will begin our study of data structures by considering four simple but very powerful concepts. Vectors, stacks, queues, deques are examples of data collections whose items are ordered depending on how they are added or removed. Once an item is added, it stays in that position relative to the other elements that came before and came after it. Collections such as these are often referred to as linear data structures.

Linear structures can be thought of as having two ends. Sometimes these ends are referred to as the “left” and the “right” or in some cases the “front” and the “rear.” You could also call them the “top” and the “bottom.” The names given to the ends are not significant. What distinguishes one linear structure from another is the way in which items are added and removed, in particular the location where these additions and removals occur. For example, a structure might allow new items to be added at only one end. Some structures might allow items to be removed from either end.

These variations give rise to some of the most useful data structures in computer science. They appear in many algorithms and can be used to solve a variety of important problems.
    
    
    
    1.1: What is a Stack?
    --------------------
    
A stack (sometimes called a “push-down stack”) is an ordered collection of items where the addition of new items and the removal of existing items always takes place at the same end. This end is commonly referred to as the “top.” The end opposite the top is known as the “base.”

The base of the stack is significant since items stored in the stack that are closer to the base represent those that have been in the stack the longest. The most recently added item is the one that is in position to be removed first. This ordering principle is sometimes called LIFO, last-in first-out. It provides an ordering based on length of time in the collection. Newer items are near the top, while older items are near the base.

Many examples of stacks occur in everyday situations. Almost any cafeteria has a stack of trays or plates where you take the one at the top, uncovering a new tray or plate for the next customer in line. Imagine a stack of books on a desk (Figure 1). The only book whose cover is visible is the one on top. To access others in the stack, we need to remove the ones that are sitting on top of them. Figure 2 shows another stack.
