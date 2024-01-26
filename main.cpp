#include <iostream>

using namespace std;

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

// double findMax(double a[], int size)
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
    int a[]{1, 2, 3, 4, 5};
    cout << "max:" << findMax(a, 5) << endl;

    double d[]{1.2, 2.2, 3.2, 4.2, 5.3};
    cout << "max:" << findMax(d, 5) << endl;

    string ss[]{"Hello", "World"};
    cout << "max:" << findMax(ss, 2) << endl;

    return 0;
}
