#include <cassert>
#include "IntStack.h"
#include "TestStack.h"
#include <iostream>

using namespace std;

void testPush()
{
    IntStack is;
    is.push(1);
    assert((1 == is.peek()));
    is.push(2);
    assert((2 == is.peek()));
    std::cout << "Push tests completed" << endl;
};

void testPeek()
{
    IntStack is;
    is.push(1);
    assert((1 == is.peek()));
    is.push(2);
    assert((2 == is.peek()));
    is.pop();
    assert((1 == is.peek()));
    std::cout << "Peek tests completed" << endl;
}

void testPop()
{
    IntStack is;
    is.push(1);
    is.push(2);
    is.push(3);
    assert((3 == is.pop()));
    assert((2 == is.pop()));
    assert((1 == is.pop()));
    std::cout << "Pop tests completed" << endl;
}