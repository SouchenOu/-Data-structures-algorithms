#include <iostream>

using namespace std;


class stack {
    public:
        int top;
        unsigned capacity;
        char *array;
};

//creat stack

stack *create_stack(unsigned capacity)
{
    stack *stackElem = new stack();
    stackElem->top = -1;
    stackElem->capacity = capacity;
    stackElem->array =  new char[(stackElem->capacity *sizeof(char))];

}
// check if our stack is full or not
int isFull(stack *OurStack)
{
    if(OurStack->top == OurStack->capacity - 1 )
    {
        return 1;
    }else
        return 0;
}
// push to our stack

void PushStack(stack *OurStack, char data)
{
    if(isFull(OurStack) == 1)
        return ;
    OurStack->array[OurStack->top++] = data;
}
//remove an item from stack
int main()
{
    stack *stack = create_stack(10);
    int i = 0;
    PushStack(stack, 10);
    PushStack(stack, 20);
    PushStack(stack, 30);
    while(i < stack->array.size())
    {
        cout << stack->array[i] << "\n";
        i++;
    }

}