#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int *array = new int[n];

    int min = 1000000, max = -1000000;
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
        if (array[i] < min)
        {
            min = array[i];
        }
        if (array[i] > max)
        {
            max = array[i];
        }
    }

    cout << min << " " << max << '\n';

    delete[] array;
    return 0;
}
