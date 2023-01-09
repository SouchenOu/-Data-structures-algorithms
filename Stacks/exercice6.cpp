//How to Reverse a String using Stack

/**The idea is to create an empty stack and push all the characters from the string into it. Then pop each character one by one from the stack and put them back into the input string starting from the 0’th index. As we all know, stacks work on the principle of first in, last out. After popping all the elements and placing 
 * them back to string, the formed string would be reversed.*/



/*Create an empty stack.
One by one push all characters of string to stack.
One by one pop all characters from stack and put them back to string.*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void func()
{

    stack<char> stk;
    string str = "souchen";
    int i =0;

    while(str[i] != '\0')
    {
        stk.push(str[i]);
        i++;
    }
    i = 0;
    while(i < str.size())
    {
        cout << stk.top();
        stk.pop();
        i++;
    }

}
int main()
{
    func();
    return 0;
}

