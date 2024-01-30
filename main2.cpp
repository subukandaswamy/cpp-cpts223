#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <cstdlib>
#include <ctime>
#include <map>

using namespace std;

int roll()
{
    return rand() % 6 + 1;
}

template <typename T>
T findMax(T a[], int size)
{
    T max = a[0];
    for (int i = 0; i < size; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    return max;
}

template <typename K, typename V>
K findMax(map<K, V> a)
{
    auto it = a.begin();

    K max = it->first;

    for (; it != a.end(); it++)
    {
        if (it->first > max)
        {
            max = it->first;
        }
    }
    return max;
}

// template <typename T, size_t size>
// T findMax(array<T, size> a)
// {
//     T max = a[0];
//     for (int i = 0; i < size; i++)
//     {
//         if (a[i] > max)
//         {
//             max = a[i];
//         }
//     }
//     return max;
// }

// template <typename T>
// T findMax(vector<T> a)
// {
//     T max = a[0];
//     for (int i = 0; i < a.size(); i++)
//     {
//         if (a[i] > max)
//         {
//             max = a[i];
//         }
//     }
//     return max;
// }

template <typename C, typename E = typename C::value_type>
E findMax(C a)
{
    auto it = a.begin();

    E max = *it;

    for (; it != a.end(); it++)
    {
        if (*it > max)
        {
            max = *it;
        }
    }
    return max;
}

// {
//     double max = a[0];
//     for (int i = 0; i < size; i++)
//     {
//         if (a[i] > max)
//         {
//             max = a[i];
//         }
//     }
//     return max;
// }

int main()
{
    srand(time(0));
    int a[]{1, 2, 3, 4, 5};
    cout << "max:" << findMax(a, 5) << endl;

    double d[]{1.2, 2.2, 3.2, 4.2, 5.3};
    cout << "max:" << findMax(d, 5) << endl;

    string ss[]{"Hello", "World"};
    cout << "max:" << findMax(ss, 2) << endl;

    // vector<int> vec{1, 2, 3, 4, 5};
    // vec.push_back(7);
    // cout << vec[1] << endl;
    // cout << vec.back() << endl;

    array<int, 5> ar{1, 2, 3, 4, 5};

    // for (auto x : ar)
    // {
    //     cout << x << endl;
    // }

    cout << "max:" << findMax(ar) << endl;

    vector<int> vec{1, 2, 3, 4, 5};
    vec.pop_back();
    vec.push_back(6);

    cout << "max:" << findMax(vec) << endl;

    list<int> lst{1, 2, 3, 4, 5};
    lst.pop_back();
    lst.pop_front();
    lst.push_back(6);

    cout << "max:" << findMax(lst) << endl;

    vector<string> players = {"subu", "ananth", "florian"};
    map<int, string> mp;

    int max = 0;
    while (max != 6)
    {
        for (auto player : players)
        {
            int r = roll();
            cout << "player " << player << " rolled:" << r << endl;
            mp[r] = player;
        }
        max = findMax(mp);
    }
    cout << "winner:" << mp[max] << endl;

    return 0;
}
