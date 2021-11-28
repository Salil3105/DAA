// Merge sort in C++

#include <iostream>
using namespace std;

int b[] = {};
void merge(int a[], int l, int mid, int r)
{
    int i = l;
    int j = mid + 1;
    int k = l;
    while (i <= mid && j <= r)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            i++;
        }
        else
        {
            b[k] = a[j];
            j++;
        }
        k++;
    }
    if (i > mid)
    {
        while (j <= r)
        {
            b[k] = a[j];
            k++;
            j++;
        }
    }
    else
    {
        while (i <= mid)
        {
            b[k] = a[i];
            k++;
            i++;
        }
    }
    for (k = l; k <= r; k++)
    {
        a[k] = b[k];
    }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // m is the point where the array is divided into two subarrays
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted subarrays
        merge(arr, l, m, r);
    }
}

// Print the array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver program
int main()
{
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 1, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Given Array is  : " << endl;
    printArray(arr, size);
    mergeSort(arr, 0, size - 1);

    cout << "Sorted array: \n";
    printArray(arr, size);

    return 0;
}