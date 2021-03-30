#include <iostream>

using namespace std;

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(const int array[], const int length)
{
    for (int index = 0; index < length; index++)
    {
        cout << array[index] << " ";
    }
    cout << endl;
}

int main()
{
    const int n = 5;
    int arr[n]{};
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Your Array: ";
    printArray(arr, n);

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
        printArray(arr, n);
    }

    return 0;
}