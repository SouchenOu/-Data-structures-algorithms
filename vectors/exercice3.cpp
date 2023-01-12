#include <iostream>
#include <vector>

using namespace std;

struct elt {
    int a, b, c;
};

int main()
{

    vector<elt> myvector;
    vector <elt> myvector2;
    elt elt1 = {1,3,3};

    myvector.push_back(elt1);
    elt *elt2 = &elt1;
    myvector2.push_back(*elt2);

    myvector[0].a=7;
    myvector2.push_back(*elt2);
    cout << myvector[0].a << endl;
    cout << myvector[0].b << endl;
    cout << myvector[0].c << endl; //7
    cout << myvector2[0].a << endl;
    cout << myvector2[0].b << endl;
    cout << myvector2[0].c << endl; //1

    return 0;
}