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
void insert_at_end(string data)
{
    struct Node * elemen = new Node;
    struct Node *newElement = new Node;
    elemen = head;
    while(elemen->next != NULL)
    {
        elemen = elemen->next;
    }
    cout << "last one is :" << elemen->data << "\n";
    elemen->next = newElement;
    newElement->prev = elemen;
    newElement->data = data;
    newElement->next = NULL;

}
//Write a C++ program to find the middle element of a given Doubly Linked List.
void find_middle_element()
{
    int cmp ;
    int cmp2 = 1;
    cmp = 0;
    struct Node * elem = new Node;
    elem = head;
    while(elem != NULL)
    {
        elem = elem->next;
        cmp++;
    }
    cmp = cmp / 2;
    elem = head;
    while(elem != NULL)
    {
        if(cmp2 == cmp)
        {
            cout << "Middle element is :" << elem->data << "\n";
            break ;
        }
        elem = elem->next;
        cmp2++;
    }

}
//Write a C++ program to insert a new node at the middle of a given Doubly Linked List.
void insert_at_middle(string data)
{
    struct Node *elem = new Node;
    struct Node *tmp = new Node;
    struct Node *newElement = new Node;
    int cmp = 0;
    int cmp2 = 1;
    elem = head;
    while(elem != NULL)
    {
        elem = elem->next;
        cmp++;
    }
    cmp = cmp / 2;
    elem = head;
    while(elem != NULL)
    {
        if(cmp2 == cmp)
        {
            tmp = elem->next;
            newElement->data = data;
            elem->next = newElement;
            newElement->prev = elem;
            newElement->next = tmp;
            break ;
        }
        elem = elem->next;
        cmp2++;
    }



}

int main()
{
    create_double_list("souka");
    create_double_list("Ahmed");
    create_double_list("fati");
    create_double_list("1337");
    create_double_list("64");
    create_double_list("42");
    DisplayList();
    cout << "****After reverse :\n";
    reverse_order();
    //reverse();
    DisplayList();
    cout << "Insert at beginning :\n";
    insert_at_beginning("ouchen");
    DisplayList();
    cout << "insert at the end :\n";
    insert_at_end("soukaina ouchen");
    DisplayList();
    cout << "Find middle element \n";
    find_middle_element();
    DisplayList();
    cout << "insert_at_middle\n";
    insert_at_middle("finish");
    DisplayList();
    return 0;
}