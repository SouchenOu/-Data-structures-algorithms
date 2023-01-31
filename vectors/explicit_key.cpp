#include <iostream>
using namespace std;

/*Examples of C++ Explicit
In the below example, we shall see how implicit conversion takes place and how we can avoid it using the C++ explicit keyword.

We create a class demo. The constructor for Demo takes in an integer and assigns it to demo1. There is a get demo() function that returns the value of this integer. We also create another function outside this class which takes in a parameter, an object of the class demo, and prints the value returned by the member function getDemo on that object.

// C++ program to illustrate implicit conversions*/

 
class Demo{

    /**/
    public:
        Demo(int n){
            demo1 = n;
        }
        int getDemo(){
            return demo1;
        }
    private:
        int demo1;
};
 
void getDemoExternally(Demo demo){
    cout << demo.getDemo();
}
// Driver Code
int main()
{
    getDemoExternally(10);
    return 0;
}


/*Output:

10
Explanation:

We see that the getDemoExternally function takes in an object of the class demo as a parameter. However we pass an integer to it from our driver code, and it still works fine. This is because the compiler has implicitly converted the integer to the demo class since the demo class has a constructor that takes in an integer. Thus, our program runs successfully.

Let us now see how to prevent the above implicit conversion with the help of the C++ explicit constructor.

To achieve this, we add the C++ explicit keyword before the constructor.

// C++ program to illustrate implicit conversions



--------------------With eexplicit keyword-----------------------


#include <iostream>
using namespace std;
 
class Demo{
    public:
        explicit Demo(int n){
            demo1 = n;
        }
        int getDemo(){
            return demo1;
        }
    private:
        int demo1;
};
 
void getDemoExternally(Demo demo){
    cout << demo.getDemo();
}
// Driver Code
int main()
{
    getDemoExternally(10);
    return 0;
}


-------------------------------------------


Output:

prog.CPP: In function ‘int main()’:
prog.cpp:23:23: error: could not convert ‘10’ from ‘int’ to ‘Demo’
   23 |     getDemoExternally(10);
      |                       ^~
      |                       |

*/