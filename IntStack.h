#ifndef IntStack_h
#define IntStack_h

class IntStack
{

public:
    bool empty();
    bool full();
    void push(int data);
    int peek();
    int pop();

private:
    int data_array[100];
    int top{-1};
};

#endif