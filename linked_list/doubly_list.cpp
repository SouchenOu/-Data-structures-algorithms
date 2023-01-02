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
            test1->next = tmp;
            test1 =test1->prev;
            break ;
    }
    if(tmp != NULL)
        head = tmp->prev;

}


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
    DisplayList();
    return 0;
}