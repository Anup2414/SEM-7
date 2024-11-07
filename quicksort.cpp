#include <bits/stdc++.h>
using namespace std;

// Function to swap two elements
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Partition function for deterministic quick sort

int partitionDeterministic(int arr[], int low, int high)
{
    int pivot = arr[high]; // Pivot is chosen as the last element (deterministic)
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Deterministic quick sort
void quickSortDeterministic(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partitionDeterministic(arr, low, high);
        quickSortDeterministic(arr, low, pi - 1);
        quickSortDeterministic(arr, pi + 1, high);
    }
}

// Partition function for randomized quick sort
int partitionRandomized(int arr[], int low, int high)
{
    int randomPivotIndex = low + rand() % (high - low); // Random pivot selection
    swap(arr[randomPivotIndex], arr[high]);             // Swap random pivot to end
    return partitionDeterministic(arr, low, high);      // Reuse partition
}

// Randomized quick sort
void quickSortRandomized(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partitionRandomized(arr, low, high);
        quickSortRandomized(arr, low, pi - 1);
        quickSortRandomized(arr, pi + 1, high);
    }
}

// Function to print the array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Main function
int main()
{
    cout << rand() << endl;
    cout << rand() << endl;
    cout << rand() << endl;
    cout << rand() << endl;
    int arr1[] = {10, 7, 8, 9, 1, 5};
    int arr2[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr1) / sizeof(arr1[0]);

    // Perform deterministic quick sort
    cout << "Deterministic Quick Sort:" << endl;
    quickSortDeterministic(arr1, 0, n - 1);
    printArray(arr1, n);

    // Perform randomized quick sort
    cout << "Randomized Quick Sort:" << endl;
    quickSortRandomized(arr2, 0, n - 1);
    printArray(arr2, n);

    return 0;
}
