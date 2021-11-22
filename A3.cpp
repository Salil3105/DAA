#include <iostream>
#include <time.h>
using namespace std;

struct Pair
{
    int min;
    int max;
};

struct Pair getMinMax(int arr[], int n)
{
    struct Pair minmax;
    int i;

    if (n == 1)
    {
        minmax.max = arr[0];
        minmax.min = arr[0];
        return minmax;
    }

    if (arr[0] > arr[1])
    {
        minmax.max = arr[0];
        minmax.min = arr[1];
    }
    else
    {
        minmax.max = arr[1];
        minmax.min = arr[0];
    }

    for (i = 2; i < n; i++)
    {
        if (arr[i] > minmax.max)
            minmax.max = arr[i];

        else if (arr[i] < minmax.min)
            minmax.min = arr[i];
    }
    return minmax;
}

int main()
{
    clock_t tStart = clock();
    int i, len;
    cout << "Enter the Array length: ";
    cin >> len;
    int arr[len];
    cout << "\n";
    cout << "Enter the Number for array :";
    for (i = 0; i < len; i++)
    {
        cin >> arr[i];
    }
    int arr_size = len;

    struct Pair minmax = getMinMax(arr, arr_size);

    cout << "Minimum element is "
         << minmax.min << endl;
    cout << "Maximum element is "
         << minmax.max;

    printf("\nTime taken: %.9fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
    return 0;
}