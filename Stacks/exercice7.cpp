#include <iostream>
#include <bits/stdc++.h>

using namespace std;


class stackClass {
    public:
        int top;
        unsigned capacity;
        char *array;
};

//creat stack

stackClass *create_stack(unsigned capacity)
{
    stackClass *stackElem = new stackClass();
    stackElem->top = -1;
    stackElem->capacity = capacity;
    stackElem->array =  new char[(stackElem->capacity *sizeof(char))];
    return stackElem;

}
// check if our stack is full or not
int isFull(stackClass *OurStack)
{
    if(OurStack->top == OurStack->capacity - 1 )
    {
        return 1;
    }else
        return 0;
}
// push to our stack

void PushStack(stackClass *OurStack, char data)
{
    if(isFull(OurStack) == 1)
        return ;
    OurStack->array[++OurStack->top] = data;
}
// function pop (return the first element means the last one that i push)
char pop(stackClass *stackElem)
{
    return stackElem->array[stackElem->top - 1];
}


//reverse our stack
void reverse_our_stack(stackClass *stackElement)
{
    stack <char> stk;
    int i = 0;
    while(stackElement->array[i] != '\0')
    {
        stk.push(stackElement->array[i]); 
        i++;
    }
    while(!stk.empty())
    {
        cout << stk.top();
        stk.pop();
    }

}
//remove an item from stack
int main()
{
    stackClass *stackEleme = create_stack(10);
    int i = 0;
    PushStack(stackEleme, 'a');
    PushStack(stackEleme, 'b');
    PushStack(stackEleme, 'c');
    while(stackEleme->array[i] != '\0')
    {
        cout << stackEleme->array[i] << "\n";
        i++;
    }
    cout << "After reverse\n";
    reverse_our_stack(stackEleme);

    

}