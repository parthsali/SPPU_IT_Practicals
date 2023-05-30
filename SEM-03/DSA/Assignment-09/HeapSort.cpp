#include <bits/stdc++.h>
using namespace std;

void maxHeapify(int arr[], int n, int i)
{
    int rootIndex = i;
    int leftIndex = i * 2 + 1;
    int rifgtIndex = i * 2 + 2;

    if (leftIndex < n && arr[leftIndex] > arr[rootIndex])
    {
        rootIndex = leftIndex;
    }
    if (rifgtIndex < n && arr[rifgtIndex] > arr[rootIndex])
    {
        rootIndex = rifgtIndex;
    }
    if (rootIndex != i)
    {
        swap(arr[rootIndex], arr[i]);
        maxHeapify(arr, n, rootIndex);
    }
}

void minHeapify(int arr[], int n, int i)
{
    int rootIndex = i;
    int leftIndex = i * 2 + 1;
    int rifgtIndex = i * 2 + 2;

    if (leftIndex < n && arr[leftIndex] < arr[rootIndex])
    {
        rootIndex = leftIndex;
    }
    if (rifgtIndex < n && arr[rifgtIndex] < arr[rootIndex])
    {
        rootIndex = rifgtIndex;
    }
    if (rootIndex != i)
    {
        swap(arr[rootIndex], arr[i]);
        minHeapify(arr, n, rootIndex);
    }
}

void heapSort(int arr[], int n, int choice)
{
    if (choice == 1)
    {
        for (int i = (n / 2 - 1); i >= 0; i--)
        {
            maxHeapify(arr, n, i);
        }
        for (int i = n - 1; i >= 0; i--)
        {
            swap(arr[0], arr[i]);
            maxHeapify(arr, i, 0);
        }
    }
    else
    {
        for (int i = (n / 2 - 1); i >= 0; i--)
        {
            minHeapify(arr, n, i);
        }
        for (int i = n - 1; i >= 0; i--)
        {
            swap(arr[0], arr[i]);
            minHeapify(arr, i, 0);
        }
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {

        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter Size of the Array : ";
    cin >> n;
    int arr[n];
    cout << "Enter Array Elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << endl;

    while (true)
    {
        cout << "Choose any one " << endl;
        cout << "1. Max Heap." << endl;
        cout << "2. Min Heap." << endl;
        cout << "3. Exit." << endl;
        cout << endl;

        int choice;
        cout << "Enter Your Choice : ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Initial Array : ";
            printArray(arr, n);
            heapSort(arr, n, 1);
            cout << "Sorted Array : ";
            printArray(arr, n);
        }
        else if (choice == 2)
        {
            cout << "Initial Array : ";
            printArray(arr, n);
            heapSort(arr, n, 2);
            cout << "Sorted Array : ";
            printArray(arr, n);
        }
        else if (choice == 3)
        {
            cout << "Exiting the Program..." << endl;
            break;
        }
        else
        {
            cout << "Please Enter Valid Input..." << endl;
        }
    }

    return 0;
}
