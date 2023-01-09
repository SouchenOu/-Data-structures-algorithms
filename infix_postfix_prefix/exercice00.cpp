#include <iostream>
#include <stack>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;



/**In order to code the algorithm in C++, we will use a hash map called prec to hold the precedence 
 * values for the operators which will be implemented with an unordered map. This hash map will map 
 * each operator char to an integer that can be compared against the precedence levels of other operators 
 * (we have arbitrarily used the integers 3, 2, and 1). The left parenthesis will receive the lowest value possible.
 *  This way any operator that is compared against it will have higher precedence and will be placed on top of it. 
 * Line 18 defines the operands to be any upper-case character or digit*/


//Converts an infix expression to a postfix expression.


// our token here A * B + C * D
string infixToPostfix(string infixexpr) {
    //performs the postfix process.
    unordered_map <char,int> prec;
    prec['*']=3;
    prec['/']=3;
    prec['+']=2;
    prec['-']=2;
    prec['(']=1;
    stack<char> opStack;
    vector<char> postfixVector;
    string letsnums = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    for (char token:infixexpr) 
    {
        //for each character in infixexpr
        if (token == ' ') {
            continue;
        }
        else if (letsnums.find(token)<=letsnums.length()) //finds if the token is inside of letsnums
        { 
            // here in postfixvector we find just alpha and number that is exist in our infixExpr
            postfixVector.__emplace_back(token); // appends to the end of the container.
        } 
       /* else if (token == '(') 
        {
            opStack.push(token);
        } 
        else if (token == ')') 
        {
            char topToken;
            topToken = opStack.top();
            opStack.pop();
            while (topToken != '(') 
            {
                postfixVector.__emplace_back(topToken);
                topToken=opStack.top();
                opStack.pop();
            }
        } 
        else 
        { //if the token is not inside of letsnums.
            while (!opStack.empty() && (prec[opStack.top()]>=prec[token])) //while the stack is not empty and
                                                                           //the top item of the stack is on a
                                                                           //higher level of PEMDAS than token.
            {
                postfixVector.__emplace_back(opStack.top());
                opStack.pop();
            }
            opStack.push(token);
        }*/

        for(int i = 0; i < postfixVector.size();i++)
        {
            cout << "here "<<postfixVector.at(i) << "\n";
        }
        break ;
    }
   /* while (!opStack.empty()) {
        postfixVector.__emplace_back(opStack.top());
        opStack.pop();
    }*/

    string s(postfixVector.begin(),postfixVector.end());

    return s;
}

int main() {
    cout <<"infix: A * B + C * D\n" << "postfix: ";
    cout << infixToPostfix("A * B + C * D") << endl;
    cout << "infix: ( A + B ) * C - ( D - E ) * ( F + G )\n" << "postfix: ";
    cout << infixToPostfix("( A + B ) * C - ( D - E ) * ( F + G )") << endl;

    return 0;
}
