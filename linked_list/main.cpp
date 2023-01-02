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
    std::cout<< "test = " << test2->number << "\n";
    new_one->number = num; 
    test->next =  new_one;
    new_one->next = test2;


    

}
int main()
{
    insert_node(1);
    insert_node(2);
    insert_node(3);
    
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
    return 0;
}
/*int main()
{
    struct Node *new_one = new Node;
    new_one->number = 11;
    new_one->next = NULL;
    struct Node *p ;
    new_one = p;
   
    insert_node(1);
    while(p)
    {
        cout << p->number << "\n";
        p = p->next;
    }


}*/