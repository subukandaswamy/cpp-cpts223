#include <iostream>
#include "IntStack.h"

using namespace std;

int main()
{
    IntStack is;
    is.push(1);
    is.push(2);
    is.push(3);
    for (int i = 0; i < 3; i++)
    {
        cout << "popped: " << is.pop() << endl;
    }
    return 0;
}