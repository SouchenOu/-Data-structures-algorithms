#include <iostream>
#include <stack>
#include <string>

using namespace std;
/******ex00:*/
/**The challenge then is to write an algorithm that will read a 
 * string of parentheses from left to right and decide whether the symbols are 
 * balanced. To solve this problem we need to make an important observation. 
 * As you process symbols from left to right, the most recent opening parenthesis 
 * must match the next closing symbol (see Figure 4). Also, the first opening symbol 
 * processed may have to wait until the very last symbol for its match. Closing symbols
 *  match opening symbols in the reverse order of their appearance; they match from the inside out. 
 * This is a clue that stacks can be used to solve the problem.*/




//simple program that checks for missing parantheses
// returns whether the parentheses in the input are balanced
bool parChecker(string symbolString) 
{
    stack<string> s;
    bool balanced = true;
    int index = 0;
    int str_len = symbolString.length();

    while (index < str_len && balanced == true) 
    {
              string symbol;
              symbol = symbolString[index];
              if (symbol == "(") {
                  s.push(symbol); //pushes the open parentheses to the stack.
              } else 
              {
                  if (s.empty()) { //if there is no open parentheses in the stack,
                                   //the closing parentheses just found makes the string unbalanced.
                        balanced = false;
                  } else { //if there is an open parentheses in the stack,
                           //the closing parentheses just found has a matching open parentheses.
                       s.pop();
                  }
              }
        index = index + 1;
    }

    if (balanced == true && s.empty() == true) 
    { 
        //if the string is balanced and there are no
        //remaining open parentheses.
        return true;
    } else {
        return false;
    }
}


int main() {
    cout << parChecker("((()))") << endl;
    cout << parChecker("(()") << endl;
}
