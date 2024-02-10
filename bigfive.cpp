#include <iostream>
#include <vector>

using namespace std;

// class Student
// {
// private:
//     int id;
//     string name;

// public:
//     Student() {}
//     Student(int id, string name) : id{id}, name{name} {}

//     void setName(string new_name)
//     {
//         name = new_name;
//     }

//     friend ostream &operator<<(ostream &os, const Student &student)
//     {
//         os << "\n Name: " << student.name << " ID: " << student.id << endl;
//         return os;
//     }
// };

// int main(int argc, char const *argv[])
// {
//     Student s1{1, "subu"};
//     Student s2{s1};
//     Student s3;
//     s2.setName("Ananth");
//     s3 = s2;
//     s3.setName("Venera");
//     cout << s1;
//     cout << s2;
//     cout << s3;
//     return 0;
// }

class IntStack
{
private:
    int *data_array = new int[100];
    int top = -1;

public:
    IntStack() {}
    // 1. DESTRUCTOR
    ~IntStack()
    {
        cout << "Destructor called" << endl;
        delete[] data_array;
    }
    // 2. COPY CONSTRUCTOR
    IntStack(const IntStack &rhs)
    {
        cout << "copy constructor called" << endl;
        this->top = rhs.top;
        for (int i = 0; i <= rhs.top; i++)
        {
            this->data_array[i] = rhs.data_array[i];
        }
    }
    // 3. COPY ASSIGNMENT OPERATOR
    IntStack &operator=(IntStack &rhs)
    {
        cout << "copy assignment called" << endl;
        this->top = rhs.top;
        for (int i = 0; i <= rhs.top; i++)
        {
            this->data_array[i] = rhs.data_array[i];
        }
        return *this;
    }
    // 4. MOVE CONSTRUCTOR
    IntStack(IntStack &&rhs)
    {
        cout << "move constructor called" << endl;
        this->top = rhs.top;
        this->data_array = rhs.data_array;
        // important step
        rhs.data_array = nullptr;
    }
    // 5. MOVE ASSIGNMENT OPERATOR
    IntStack &operator=(IntStack &&rhs)
    {
        cout << "move assignment called" << endl;
        this->top = rhs.top;
        this->data_array = rhs.data_array;
        // important step
        rhs.data_array = nullptr;
        return *this;
    }

    void push(int data)
    {
        data_array[++top] = data;
    }
    int peek()
    {
        return data_array[top];
    }
    int pop()
    {
        return data_array[top--];
    }
    int at(int i)
    {
        return data_array[i];
    }
    friend ostream &operator<<(ostream &os, IntStack &is)
    {
        cout << "\nBottom of stack" << endl;
        for (int i = 0; i <= is.top; i++)
        {
            cout << is.data_array[i] << endl;
        }
        cout << "Top of stack" << endl;
        return os;
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
    bool contains(int query)
    {
        for (int i = 0; i <= top; i++)
        {
            if (data_array[i] == query)
                return true;
        }
        return false;
    }
};

class MySet
{
private:
    IntStack is;

public:
    void add(int data)
    {
        if (!contains(data))
        {
            is.push(data);
        }
        else
        {
            cout << "duplicate " << data << " not pushed" << endl;
        }
    }
    bool contains(int data)
    {
        return is.contains(data);
    }

    friend ostream &operator<<(ostream &os, MySet &ms)
    {
        os << ms.is;
        return os;
    }
};

int main(int argc, char const *argv[])
{
    // IntStack is1;
    // is1.push(1);
    // is1.push(2);
    // is1.push(3);
    // cout << is1;

    // IntStack is2{is1};
    // is2.push(4);
    // cout << is2;

    // IntStack is3;
    // is3 = is2;
    // is3.push(5);
    // cout << is3 << endl;
    // cout << is2.at(4) << endl;
    // cout << is3.at(4) << endl;

    // vector<IntStack> intStacks;
    // cout << " creating int stack 1" << endl;
    // intStacks.push_back(IntStack{});
    // cout << " creating int stack 2" << endl;
    // intStacks.push_back(IntStack{});
    // cout << " creating int stack 3" << endl;
    // intStacks.push_back(IntStack{});
    // intStacks[0].push(2);
    // cout << intStacks[0];

    // this is where we will use the IntStacks in a game

    // implement a + operator
    //  1 2 3
    //  4 5 6
    // +
    // 1 2 3 4 5 6
    MySet ms;

    ms.add(4);
    ms.add(1);
    ms.add(2);
    ms.add(3);
    ms.add(1);
    ms.add(2);
    ms.add(3);

    cout << ms;

    return 0;
}
