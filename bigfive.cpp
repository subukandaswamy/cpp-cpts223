#include <iostream>
#include <vector>
#include <set>

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
    bool contains(int query)
    {
        for (int i = 0; i <= top; i++)
        {
            if (data_array[i] == query)
            {
                return true;
            }
        }
        return false;
    }
};

class IntSet
{
private:
    IntStack is;

public:
    bool contains(int element)
    {
        return is.contains(element);
    }
    void add(int element)
    {
        if (!is.contains(element))
            is.push(element);
        else
            cout << "duplicate -- not pushing" << endl;
    }
    friend ostream &operator<<(ostream &os, const IntSet &iset)
    {
        os << iset.is;
        return os;
    }
};

int main(int argc, char const *argv[])
{
    IntSet is;
    is.add(1);
    is.add(2);
    is.add(3);
    is.add(1);
    is.add(2);
    is.add(3);

    cout << is;

    set<int> iss{1, 2, 3};

    for (auto &x : iss)
    {
        cout << x << endl;
    }

    return 0;
}
