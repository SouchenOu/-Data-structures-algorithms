#include <iostream>


using namespace std;
/*****A Doubly Linked List (DLL) contains an extra pointer, typically called the previous pointer,
 *  together with the next pointer and data which are there in the singly linked list.*/

////Write a C++ program to create and display a doubly linked list

struct Node{
    string data;
    struct Node* next;
    struct Node* prev;
};

struct Node *head = NULL;

void create_double_list(string data)
{
    struct Node *newOne = new Node;
    newOne->data = data;
    newOne->prev = NULL;
    newOne->next = head;

    if(head != NULL)
    {
        head->prev = newOne;
    }
    head = newOne;
}

void DisplayList()
{
    struct Node *test = new Node;
    test = head;
    while(test!= NULL)
    {
        cout << test->data << "\n";
        test = test->next;

    }
}

// Write a C++ program to create a doubly linked list of n nodes and display it in reverse order
void reverse_order()
{
    struct Node *test1 = new Node;
    struct Node *tmp;
    test1 = head;
    while(test1 != NULL)
    {
            tmp = test1->prev;
            test1->prev = test1->next;
            //cout << "next test1" << test1->next->data << "\n";
            test1->next = tmp;
            test1 =test1->prev;     
    }
    if(tmp != NULL)
        head = tmp->prev;

}
//other method
/*void reverse()
{
    struct Node *test1 = new Node;
    struct Node *test2 = new Node;
    struct Node * tmp = new Node;
    struct Node *tmp2 = new Node;
    test1 = head;
    test2 = head;
    while(test2->next != NULL)
    {
        test2 = test2->next;
    }
    while(test1 != NULL)
    {
        tmp = test2;
        test2 = test1;
        test1 = tmp;
        cout << "test1 = " << test1->data << "\n";
        cout << "test2 = " << test2->data << "\n";
        test1 = test1->next;
        test2 = test2->prev;
        
        break ;
    }
}*/
//Write a C++ program to insert a new node at the beginning of a Doubly Linked List.

void insert_at_beginning(string num)
{
    struct Node *test = new Node;
    struct Node *newElement = new Node;
    test = head;
    newElement->data = num;
    newElement->next = test;
    newElement->prev = NULL;
    head = newElement;

}
//Write a C++ program to insert a new node at the end of a Doubly Linked List.

int main()
{
    create_double_list("souka");
    create_double_list("Ahmed");
    create_double_list("fati");
    create_double_list("1337");
    create_double_list("64");
    DisplayList();
    cout << "****After reverse :\n";
    reverse_order();
    //reverse();
    DisplayList();
    cout << "Insert at beginning :\n";
    insert_at_beginning("ouchen");
    DisplayList();
    return 0;
}