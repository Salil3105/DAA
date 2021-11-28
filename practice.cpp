#include <iostream>
using namespace std;

int partition(int arr[], int low, int high)
{
}

int QuickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);
        QuickSort(arr, low, pivot - 1);
        QuickSort(arr, pivot + 1, high);
    }
}

int main()
{
    int len;
    cout << "Enter the length of the array ?" << endl;
    cin >> len;
    int n = len;
    int arr[len];
    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];
    }
    QuickSort(arr, 0, (n - 1));
    return 0;
}