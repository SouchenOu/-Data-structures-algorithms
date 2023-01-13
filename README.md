# -Data-structures



Polimorphisme:
-------------


Le mot polymorphisme signifie avoir plusieurs formes. En général, le polymorphisme se produit lorsqu’il existe une hiérarchie de classes et qu’elles sont liées par héritage.

auto keywords:
---------------

The auto keyword is a simple way to declare a variable that has a complicated type. For example, you can use auto to declare a variable where the initialization expression involves templates, pointers to functions, or pointers to members.











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
    
    
    
 1: Stack?
  --------------------
    
A stack (sometimes called a “push-down stack”) is an ordered collection of items where the addition of new items and the removal of existing items always takes place at the same end. This end is commonly referred to as the “top.” The end opposite the top is known as the “base.”

The base of the stack is significant since items stored in the stack that are closer to the base represent those that have been in the stack the longest. The most recently added item is the one that is in position to be removed first. This ordering principle is sometimes called LIFO, last-in first-out. It provides an ordering based on length of time in the collection. Newer items are near the top, while older items are near the base.

Many examples of stacks occur in everyday situations. Almost any cafeteria has a stack of trays or plates where you take the one at the top, uncovering a new tray or plate for the next customer in line. Imagine a stack of books on a desk (Figure 1). The only book whose cover is visible is the one on top. To access others in the stack, we need to remove the ones that are sitting on top of them. Figure 2 shows another stack.

   

   
<img width="883" alt="Screen Shot 2023-01-07 at 11 38 31 AM" src="https://user-images.githubusercontent.com/87101785/211146237-c6cc66ba-49c8-4cd8-acc5-cc7062e80d26.png">

    
    1.1:The Stack Abstract Data Type:
    --------------------------------
    
    
    The stack abstract data type is defined by the following structure and operations. A stack is structured, as described above, as an ordered collection of items where items are added to and removed from the end called the “top.” Stacks are ordered LIFO. The stack operations are given below.

stack<datatype> creates a new stack that is empty. It needs no parameters and returns an empty stack. It can only contain a certain type of data. e.g. int, string etc.

push(item) adds a new item to the top of the stack. It needs the item and returns nothing.

pop() removes the top item from the stack. It needs no parameters and returns nothing. The stack is modified.

top() returns the top item from the stack but does not remove it. It needs no parameters. The stack is not modified.

empty() tests to see whether the stack is empty. It needs no parameters and returns a Boolean value.

size() returns the number of items on the stack. It needs no parameters and returns an integer.

For example, if s is a stack that has been created and starts out empty, then Table 1 shows the results of a sequence of stack operations. Under stack contents, the top item is listed at the far right.
    
<img width="883" alt="Screen Shot 2023-01-07 at 11 47 32 AM" src="https://user-images.githubusercontent.com/87101785/211146453-d782a261-0692-4a9f-8e24-0837863556e7.png">
    
    
    1.2:Using a Stack in C++:
    -----------------------
    
    Now that we have clearly defined the stack as an abstract data type we will turn our attention to using a stack with the help of the Standard Template Library (STL) in C++. Recall that when we give an abstract data type a physical implementation we refer to the implementation as a data structure.

As we described in Chapter 1, in C++, as in any object-oriented programming language, the implementation of choice for an abstract data type such as a stack is the creation of a new class. The stack operations are implemented as methods. However, the STL already has a well written implementation of the Stack class.

The following stack implementation (ActiveCode 1) assumes that the end of the array will hold the top element of the stack. As the stack grows (as push operations occur), new items will be added on the end of the array. pop operations will manipulate that same end.

                //Tests the push, empty, size, pop, and top methods of the stack library.

                
                        #include <iostream>
                        #include <stack>    // Calling Stack from the STL

                        using namespace std;

                        int main() 
                        {
                                stack<int> newStack;
                                newStack.push(3); //Adds 3 to the stack
                                newStack.push(8);
                                newStack.push(15);

                                 // returns a boolean response depending on if the stack is empty or not
                                cout << "Stack Empty? " << newStack.empty() << endl;

                                // returns the size of the stack itself
                                cout << "Stack Size: " << newStack.size() << endl;

                                // returns the topmost element of the stack
                                cout << "Top Element of the Stack: " << newStack.top() << endl;

                                // removes the topmost element of the stack
                                newStack.pop();

                                cout << "Top Element of the Stack: " << newStack.top() << endl;

                                cout << "Stack Size: " << newStack.size() << endl;

                                return 0;
                        }
    
    
                             Result:
    
                                Stack Empty? 0
                                Stack Size: 3
                                Top Element of the Stack: 15
                                Top Element of the Stack: 8
                                Stack Size: 2
                                
                  
                  
 1.3: Infix, Prefix and Postfix Expressions:
 ------------------------------------------
 
Conversion of Infix Expressions to Prefix and Postfix
 
 
<img width="883" alt="Screen Shot 2023-01-07 at 2 42 49 PM" src="https://user-images.githubusercontent.com/87101785/211153771-106814a1-610f-4b79-aa5f-e6e3b5b18d66.png">

2: Vector in C++ STL:
--------------------

Vectors are the same as dynamic arrays with the ability to resize itself automatically when an element is inserted or deleted, with their storage being handled automatically by the container. Vector elements are placed in contiguous storage so that they can be accessed and traversed using iterators. In vectors, data is inserted at the end. Inserting at the end takes differential time, as sometimes the array may need to be extended. Removing the last element takes only constant time because no resizing happens. Inserting and erasing at the beginning or in the middle is linear in time.

1: begin() – Returns an iterator pointing to the first element in the vector
    
2: end() – Returns an iterator pointing to the theoretical element that follows the last element in the vector
    
3: rbegin() – Returns a reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element
    
4: rend() – Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end)
    
5: cbegin() – Returns a constant iterator pointing to the first element in the vector.
    
6: cend() – Returns a constant iterator pointing to the theoretical element that follows the last element in the vector.
    
7: crbegin() – Returns a constant reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element
    
8: crend() – Returns a constant reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse 
    end)
9: size() – Returns the number of elements in the vector.
    
10:max_size() – Returns the maximum number of elements that the vector can hold.
    
11:capacity() – Returns the size of the storage space currently allocated to the vector expressed as number of elements.
    
12:resize(n) – Resizes the container so that it contains ‘n’ elements.
    
13:empty() – Returns whether the container is empty.
    
14:shrink_to_fit() – Reduces the capacity of the container to fit its size and destroys all elements beyond the capacity.
    
15:reserve() – Requests that the vector capacity be at least enough to contain n elements.
    
16: assign() – It assigns new value to the vector elements by replacing old ones
    
17: push_back() – It push the elements into a vector from the back
    
18: pop_back() – It is used to pop or remove elements from a vector from the back.
    
19: insert() – It inserts new elements before the element at the specified position
    
20: erase() – It is used to remove elements from a container from the specified position or range.
    
21: swap() – It is used to swap the contents of one vector with another vector of same type. Sizes may differ.

22: clear() – It is used to remove all the elements of the vector container
    
23: emplace() – It extends the container by inserting new element at position
    
24: emplace_back() – It is used to insert a new element into the vector container, the new element is added to the end of the vector


<img width="1451" alt="Screen Shot 2023-01-12 at 4 41 54 PM" src="https://user-images.githubusercontent.com/87101785/212112452-ddd9534a-02fe-4740-ba5c-2b97610605fe.png">

     
Iterators:
----------
     
An iterator is an object that can iterate over elements in a C++ Standard Library container and provide access to individual elements. The C++ Standard Library containers all provide iterators so that algorithms can access their elements in a standard way without having to be concerned with the type of container the elements are stored in.
     
An iterator is an object (like a pointer) that points to an element inside the container. We can use iterators to move through the contents of the container. They can be visualized as something similar to a pointer pointing to some location and we can access the content at that particular location using them. 
     
