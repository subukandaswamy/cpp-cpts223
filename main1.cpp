#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class Stack
{

public:
    bool empty()
    {
        return top < 0;
    }
    bool full()
    {
        return top >= 100;
    }
    void push(T data)
    {
        if (full())
            throw overflow_error("Stack full!");
        data_array[++top] = data;
    }
    T peek()
    {
        return data_array[top];
    }
    T pop()
    {
        if (empty())
            throw underflow_error("Stack empty!");
        return data_array[top--];
    }

private:
    T data_array[100];
    int top{-1};
};

int main()
{
    Stack<int> is;
    is.push(1);
    is.push(2);
    is.push(3);
    for (int i = 0; i < 3; i++)
    {
        cout << "popped: " << is.pop() << endl;
    }
    Stack<string> ss;
    ss.push("world");
    ss.push("hello");
    for (int i = 0; i < 2; i++)
    {
        cout << "popped: " << ss.pop() << endl;
    }
    return 0;
}
