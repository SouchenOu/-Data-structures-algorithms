#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int check_sign(char c)
{
    if(c == '+' || c == '-')
    {
        return 1;
    }else if(c == '/' || c == '*')
    {
        return 2;
    }else if(c == '^')
    {
        return 3;
    }else
        return -1;
}

void postfixSufix(string word)
{
    string str;
    stack <char> stk;
    int i = 0;

    for(i = 0; i < word.size(); i++)
    {
        if((word[i] >= 'a' && word[i] <= 'z') || (word[i] >= 'A' && word[i] <= 'Z') || (word[i] >= 0 && word[i] <= 9))
        {
            str = str + word[i];
        }
        else if(check_sign(word[i]) != -1)
        {
            if(!stk.empty() && check_sign(stk.top()) >= check_sign(word[i]))
            {
                str = str + stk.top();
                stk.pop();
                //stk.push(word[i]);
            }
            stk.push(word[i]);
        }
        else if(word[i] == '(')
        {
            stk.push('(');
        }

        else if (word[i] == ')') 
        {
            while (stk.top() != '(') {
                str += stk.top();
                stk.pop();
            }
            stk.pop();
        }
   
    }
    while(!stk.empty())
    {
        str = str + stk.top();
        stk.pop();
    }

        cout << str << "\n";
  
}

int main()
{
    string word = "a+b *(c^d - e)";
    postfixSufix(word);
    return 0;

}