#include <iostream>
#include <time.h>
using namespace std;

void merge(int arr[], int left, int mid, int right)
{
    int subarr1 = mid - left + 1;
    int subarr2 = right - mid;

    int *leftarr = new int[subarr1];
    int *rightarr = new int[subarr2];

    for (int i = 0; i < subarr1; i++)
    {
        leftarr[i] = arr[left + i];
    }
    for (int j = 0; j < subarr2; j++)
    {
        rightarr[j] = arr[mid + 1 + j];
    }

    int indexofsubarr1 = 0;
    int indexofsubarr2 = 0;
    int indexofmergedarr = left;

    while (indexofsubarr1 < subarr1 && indexofsubarr2 < subarr2)
    {
        if (leftarr[indexofsubarr1] <= rightarr[indexofsubarr2])
        {
            arr[indexofmergedarr] = leftarr[indexofsubarr1];
            indexofsubarr1++;
        }
        else
        {
            arr[indexofmergedarr] = rightarr[indexofsubarr2];
            indexofsubarr2++;
        }
        indexofmergedarr++;
    }
    while (indexofsubarr1 < subarr1)
    {

        arr[indexofmergedarr] = leftarr[indexofsubarr1];
        indexofsubarr1++;
        indexofmergedarr++;
    }
    while (indexofsubarr2 < subarr2)
    {

        arr[indexofmergedarr] = rightarr[indexofsubarr2];
        indexofsubarr2++;
        indexofmergedarr++;
    }
}

void mergesort(int arr[], int begin, int end)
{
    if (begin >= end)
    {
        return;
    }
    int mid = begin + (end - begin) / 2;
    mergesort(arr, begin, mid);
    mergesort(arr, mid + 1, end);
    merge(arr, begin, mid, end);
}

void printarr(int arr[], int arr_size)
{
    for (int i = 0; i < arr_size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main()
{
    clock_t tStart = clock();
    int i, len;
    cout << "Enter the Array length: ";
    cin >> len;
    int arr[len];
    cout << "\n";
    cout << "Enter the Numbers for array :";
    for (i = 0; i < len; i++)
    {
        cin >> arr[i];
    }
    int arr_size = len;
    cout << "\nArray given is :\t";
    printarr(arr, arr_size);
    mergesort(arr, 0, arr_size - 1);
    cout << "\nSorted array is :\t";
    printarr(arr, arr_size);

    printf("\nTime taken: %.9fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);

    return 0;
}