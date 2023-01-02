#include <iostream>


/*A linked list is a set of dynamically allocated nodes, 
arranged in such a way that each node contains one value and one pointer. 
The pointer always points to the next member of the list. If the pointer is NULL, then it is the last node in the list.*/

/*Size: Since data can only be stored in contiguous blocks of memory in an array, its size cannot be altered at runtime due to the risk of overwriting other data. 
However, in a linked list, each node points to the next one such that data can exist at scattered (non-contiguous) addresses; this allows for a dynamic size that can change at runtime.*/

using namespace std;

/************** ex1  Write a C++ program to create and display a Singly Linked List***********/

struct Node {
    int number;
    Node *next;
};


//insert node at start
struct Node *head = NULL;
void insert_node(int num)
{
    struct Node *new_node = new Node;
    new_node->number = num;
    new_node->next = head;
    head = new_node;
}
// display all nodes

void display_all_nodes()
{
    struct Node *temp = head;
    while(temp)
    {
        cout<< temp->number << "\n";
        temp = temp->next;
    }
}
/*************Write a C++ program to create a singly linked list of n nodes and display it in reverse order******************/
void reverce_list()
{
    Node* current_node = head;
    Node* prev = NULL, *next = NULL;
    while(current_node != NULL)
    {
        //cout << "times\n";
        next = current_node->next;
        current_node->next = prev;
        prev = current_node;
       // cout << prev->number << "\n";
        current_node = next;
        
        //cout << "next next current" << prev->next->number << "\n"
    }
    head = prev;
}
/************Write a C++ program to create a singly linked list of n nodes and count the number of nodes***************/

void count()
{
    struct Node* p = head;
    int cmp = 0;
    while(p != NULL)
    {
        cmp++;
        p = p->next;
    }
    cout << "number of nodes here is :" << cmp << "\n";
}

/****Write a C++ program to insert a new node at the beginning of a Singly Linked List.**/

void insert_at_first(int num)
{
    struct Node *new_node = new Node;
    new_node->number = num;
    new_node->next = head;
    head = new_node;
    


}
/**************Write a C++ program to insert a new node at the end of a Singly Linked List.****************/
void insert_end(int num)
{
    struct Node *new_node = new Node;
    struct Node *point;
    point = head;
    while(point->next != NULL)
    {
        point = point->next;
    }
    point->next= new_node;
    new_node->number = num;
    new_node->next = NULL;
}
//Write a program in C to insert a new node at the middle of Singly Linked List

void insert_middle(int num)
{
    struct Node * new_one = new Node;
    struct Node *test;
    struct Node *test2;
    int cmp = 0;
    int cpm2 = 1;
    test = head;
    while(test != NULL)
    {
        test= test->next;
        cmp++;
    }
    cmp = cmp/2;
    test = head;
    while(test != NULL)
    {
        if(cpm2 == cmp)
        {
            break ;
        }
        cpm2++;
        test = test->next;
    }
    test2 = test->next;
    new_one->number = num; 
    test->next =  new_one;
    new_one->next = test2;
}

//  Write a C++ program to find the middle element of a given
void find_middle()
{
        struct Node * first = new Node;
        first = head;
        int cmp;
        int cmp2;
        cmp = 0;
        cmp2 = 1;
        while(first != NULL)
        {
            cmp++;
            first= first->next;
        }
        cmp = cmp / 2;
        cout << "here cmp = " << cmp << "\n";
        first = head;
        while(first != NULL)
        {
            if(cmp2 == cmp)
            {
                first = first->next;
                break ;
            }
            first = first->next;
            cmp2++;
        }
        std::cout << "Our middle element is : " << first->number << "\n";

}
//Write a C++ program to get Nth node in a given Singly Linked List.
// get the position of every element in linked list

void search_element(int num)
{
    int cmp;
    cmp = 1;
    struct Node *element = new Node;

    element = head;
    while(element != NULL)
    {
        if(cmp == num)
        {
            cout << "Position: " << num << "\n";
            cout << "Value: " << element->number << "\n";
            break ;
        }
        element= element->next;
        cmp++;
    }
}

//Write a C++ program to delete first node of a given Singly Linked List.

void delete_first_node()
{
    struct Node *test;
    if(head != NULL)
    {
        test = head;
        head = head->next;
        free(test);
    }

}
// Write a C++ program to delete a node from the middle of Singly Linked List

void delete_middle()
{
     int cmp;
     int cmp2;
     cmp = 0;
     cmp2 = 1;
     struct Node *N = new Node;
     struct Node *N2 = new Node;
     struct Node *N3 = new Node;
     N = head;
     while( N != NULL)
     {
        N= N->next;
        cmp++;
     }
     cmp = cmp / 2;
     N = head;
     while(N != NULL)
     {
        if(cmp2 + 1 == cmp)
        {
            N2 = N;
            N = N->next;
            break ;
        }
        N=N->next;
        cmp2++;
     }
     N3 = N->next;
     N2->next = N3;

}
//Write a C++ program to delete the last node of a Singly Linked List

void delete_last()
{
    struct Node *element = new Node;
    int cmp = 0;
    int cmp2 = 1;
    element = head;
    while(element != NULL)
    {
        cmp++;
        element = element->next;
       
    }
    cmp--;
    element = head;
    while(element != NULL)
    {
        if((cmp - 1) == cmp2)
        {
            element = element->next;
            element->next = NULL;
            break ;
        }
        element = element->next;
        cmp2++;
    }
    /*while(head != NULL)
    {
        cout << "head = " << head->number << "\n";
        head=head->next;
    }*/


}

int main()
{
    insert_node(1);
    insert_node(2);
    insert_node(3);
    insert_node(4);
    insert_node(5);
    insert_node(6);
   
    
    display_all_nodes();
    reverce_list();
    cout << "after reverse\n";
    display_all_nodes();
    count();
    cout << "insert in first\n";
    insert_at_first(100);
    display_all_nodes();
    cout << "insert at end\n";
    insert_end(200);
    display_all_nodes();
    cout << "Insert middle\n";
    insert_middle(300);
    display_all_nodes();
    cout<< "Find middle element\n";
    find_middle();
    cout<< "Find the value of this position :\n";
    search_element(7);
    cout << "Delete the first element\n";
    delete_first_node();
    display_all_nodes();
    cout << "Delete middle element\n";
    delete_middle();
    display_all_nodes();
    cout << "Delete the last one \n";
    delete_last();
    display_all_nodes();
    return 0;
}
