#include <iostream>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

/******ex01*/



/***Binary Numbers
In your study of computer science, you have probably been exposed in one way or 
another to the idea of a binary number. Binary representation is important in 
computer science since all values stored within a computer exist as a string of 
binary digits, a string of 0s and 1s. Without the ability to convert back and forth 
between common representations and binary numbers, we would need to interact with 
computers in very awkward ways.

Integer values are common data items. They are used in computer programs and computation 
all the time. We learn about them in math class and of course represent them using the 
decimal number system, or base 10. The decimal number  and its corresponding binary equivalent  
are interpreted respectively as

But how can we easily convert integer values into binary numbers? The answer is an algorithm 
called “Divide by 2” that uses a stack to keep track of the digits for the binary result.

The Divide by 2 algorithm assumes that we start with an integer greater than 0. A simple iteration 
then continually uses integer division to divide the decimal number by 2 and to keep track of the 
remainder. The first division by 2 gives information as to whether the value is even or odd. An even 
value will have a remainder of 0. It will have the digit 0 in the 1s place. An odd value will have a 
remainder of 1 and will have the digit 1 in the 1s place. We think about building our binary number 
as a sequence of digits; the first remainder we compute will actually be the last digit in the sequence. 
As shown in Figure 5, we again see the reversal property that signals that a stack is likely */

//converts a given decimal number into binary.



string divideBy2(int decNumber) {
  //performs the conversion process.
  stack<int> remstack;

  while (decNumber > 0) {
          //gets the remainder of division by 2
          //and adds the remainder to a stack.
          int rem = decNumber % 2;
          remstack.push(rem);
          decNumber = decNumber / 2;
  }

  string binString = "";
  while (!remstack.empty()) {
          //adds the remainder numbers in the stack into a string.
          binString.append(to_string(remstack.top()));
          remstack.pop();
  }

  return binString;
}

int main() {
  cout << divideBy2(42) << endl;

  return 0;
}

