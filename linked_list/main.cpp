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
        
        //cout << "next next current" << prev->next->number << "\n";

    }
    head = prev;

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