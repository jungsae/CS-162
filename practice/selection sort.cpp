#include <iostream>
using namespace std;

// void swap(int *a, int *b)
// {
//     int temp;
//     temp = *a;
//     *a = *b;
//     *b = temp;
// }

// int main()
// {
//     int a = 13;
//     int b = 111;
//     cout << a << " " << b << endl;

//     swap(&a, &b);

//     cout << a << " " << b << endl;

//     return 0;
// }

int main()
{
    const int length = 5;
    int array[length]{};
    for (int i = 0; i < length; i++)
    {
        cin>>array[i];
    }
    
    int min;

    for (int i = 0; i < length - 1; i++)
    {
        min = i;

        for (int j = i + 1; j < length; j++)
        {
            if (array[min] > array[j])
            {
                min = j;
            }
        }

        int temp = array[i];
        array[i] = array[min];
        array[min] = temp;
    }

    for (int i = 0; i < length; i++)
    {
        cout << array[i] << " ";
    }

    return 0;
}