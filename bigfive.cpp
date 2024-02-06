#include <iostream>
#include <vector>

using namespace std;

class IntStack
{
private:
    int *data_array = new int[100];
    int top = -1;

public:
    IntStack() {}
    IntStack(const IntStack &rhs)
    {
        cout << "copy constructor called " << endl;
        this->top = rhs.top;
        this->data_array = new int[100];
        for (int i = 0; i <= rhs.top; i++)
        {
            this->data_array[i] = rhs.data_array[i];
        }
    }
    IntStack(IntStack &&rhs) noexcept
    {
        cout << "move constructor called " << endl;
        this->top = rhs.top;
        this->data_array = rhs.data_array;
        rhs.data_array = nullptr;
    }
    IntStack operator=(IntStack &&rhs) noexcept
    {
        cout << "move assignment called " << endl;
        this->top = rhs.top;
        this->data_array = rhs.data_array;
        rhs.data_array = nullptr;
        return *this;
    }
    IntStack &operator=(const IntStack &rhs)
    {
        cout << "copy assignment called " << endl;
        this->top = rhs.top;
        this->data_array = new int[100];
        for (int i = 0; i <= rhs.top; i++)
        {
            this->data_array[i] = rhs.data_array[i];
        }
        return *this;
    }
    void push(int i)
    {
        data_array[++top] = i;
    }
    int peek() const
    {
        return data_array[top];
    }
    int pop()
    {
        return data_array[top--];
    }
    ~IntStack()
    {
        cout << "destructor called" << endl;
        delete[] data_array;
    }
    IntStack operator+(const IntStack &rhs)
    {
        IntStack temp;
        for (int i = 0; i <= top; i++)
        {
            temp.push(data_array[i]);
        }
        for (int i = 0; i <= rhs.top; i++)
        {
            temp.push(rhs.data_array[i]);
        }
        return temp;
    }

    friend ostream &operator<<(ostream &os, const IntStack &is)
    {
        os << "bottom of stack" << endl;
        for (int i = 0; i <= is.top; i++)
        {
            os << is.data_array[i] << endl;
        }
        os << "top of stack\n"
           << endl;
        return os;
    }
};

int main(int argc, char const *argv[])
{
    IntStack is;
    is.push(1);
    is.push(2);
    is.push(3);
    cout << is;

    IntStack is1;
    is1.push(4);
    is1.push(5);
    is1.push(6);
    cout << is1;

    IntStack is3;

    is3 = is + is1;

    // cout << is3;
    //  cout << is.peek() << endl;
    //  IntStack is1{is};
    //  IntStack is2 = is;
    //  IntStack is3;
    //  is3 = is;
    //  // is1 = is;
    //  cout << is1.peek() << endl;
    //  vector<IntStack> vec;
    //  vec.push_back(IntStack());
    //  vec.push_back(IntStack());

    return 0;
}
