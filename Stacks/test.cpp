#include <iostream>

using namespace std;



class stack{
    public:
        int data;
        stack *next;
};

// add new node

stack *newNode(int data)
{
    stack *newOne = new stack();
    newOne->data = data;
    newOne->next = NULL;
    return newOne;
}

// check if the stack is empty

int check_empty(stack *root)
{
    if (root != NULL)
    {
        return 1;
    }else
        return 0;
}

// Push in stack

void push_stack(stack **List, int data)
{
    stack *newElement = newNode(data);
    newElement->next = *List;
    *List = newElement;
    //newElement = *List;
}

//delete the first element pop()
void pop(stack **List)
{
    stack *tmp;
    tmp = *List;
    *List = (*List)->next;
    free(tmp);
}

int main(){

    stack *newElem = NULL;
    stack *tmp ;

    push_stack(&newElem, 10);
    push_stack(&newElem, 20);
    push_stack(&newElem, 30);
    push_stack(&newElem, 40);
    tmp = newElem;
    cout << "Our element is :" << "\n";
    while(tmp != NULL)
    {
        cout << tmp->data << "\n";
        tmp= tmp->next;
    }
    pop(&newElem);
    tmp = newElem;
    cout << "Our lement after pop\n";
    while(tmp != NULL)
    {
        cout << tmp->data << "\n";
        tmp= tmp->next;
    }
}


