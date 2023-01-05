#include <iostream>


using namespace std;
/*
******Problems and Solutions******
1: Removing Duplicates
2: Beginning of a Circular List
3: A List Representing the Sum of the Two Lists
4: Making a Sorted List from an Unsorted List
5: Mth-to-Last Element of a Linked List*/


struct Node {
    int num;
    struct Node *prev;
    struct Node *next;

};


struct Node *head = NULL;

void insert_node(int num)
{
    struct Node *newOne = new Node;
    newOne->num = num;
    newOne->prev = NULL;
    newOne->next = head;

    if(head != NULL)
    {
        head->prev = newOne;
    }
    head = newOne;
   
}

void display_list()
{
    struct Node *list = new Node;
    list = head;
    while(list != NULL)
    {
        cout << list->num << "\n";
        list = list->next;
    }
}


//*****ex00
//deleting head element
//inserting an element ahead of the first element of a list 
void delete_head_element()
{
    struct Node* elem = new Node;
    struct Node *tmp;
    tmp = head;
    head = head->next;
    delete tmp;
}

// Removing duplicates numbers 

void removing_dup()
{
    struct Node *first = new Node;
    struct Node *second = new Node;
    struct Node *test = new Node;
    struct Node *list = new Node;
    test = head;
    struct Node *tmp;
    first = head;
    test = test->next;
    second = test;
    while(first != NULL)
    {
      
        second = first->next;
        while(second != NULL)
        {
            if(first->num == second->num)
            {
                second->prev->next = second->next;
                delete second;
                
            }
            second= second->next;
        }
        first = first->next;
    }
    
}
// Sum of two list
void sum_list()
{
    struct Node *list1 = new Node;
    struct Node *list2 = new Node;
    struct Node *listSUM = new Node;
    listSUM = NULL;

    list1 = head;
    list2 = head->next;
    while(list1 != NULL && list2 != NULL)
    {
        //cout << "here\n";
        list1->num = list1->num + list2->num;
        //listSUM = listSUM->next;
        list1 = list1->next;
        list2 = list2->next;
    }
   // head = list1;
}

int main()
{
    insert_node(1);
    insert_node(0);
    insert_node(2);
    insert_node(4);
    insert_node(3);
    insert_node(2);
    insert_node(4);
    insert_node(11);
    insert_node(1);
    cout << "Our list is\n";
    display_list();
    cout << "Delete the first element \n";
    delete_head_element();
    display_list();
    cout << "removing duplicated number\n";
    removing_dup();
    display_list();
    cout << "SUM two lists\n";
    sum_list();
    display_list();
}
