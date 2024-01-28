#include "IntStack.h"
#include <stdexcept>

bool IntStack::empty()
{
    return top < 0;
}
bool IntStack::full()
{
    return top >= 100;
}
void IntStack::push(int data)
{
    if (full())
        throw std::overflow_error("Stack full!");
    data_array[++top] = data;
}
int IntStack::peek()
{
    return data_array[top];
}
int IntStack::pop()
{
    if (empty())
        throw std::underflow_error("Stack empty!");
    return data_array[top--];
}