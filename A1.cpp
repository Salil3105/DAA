#include <bits/stdc++.h>
#include <time.h>
using namespace std;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    cout << i << endl;
    for (int j = low; j <= high - 1; j++)
    {

        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
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
    int n = len;
    quickSort(arr, 0, n - 1);
    cout << "Sorted array: \n";
    printArray(arr, n);
    printf("\nTime taken: %.9fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
    return 0;
}