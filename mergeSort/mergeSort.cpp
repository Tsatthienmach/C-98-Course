#include <iostream>
using namespace std;


void printArray(int arr[], int length)
{
    cout << "Length: "<< length << endl;
    cout << "[";
    for (int i = 0; i < length - 1; i ++)
    {
        cout << arr[i] << ", ";
    }
    cout << arr [length-1]<< "]"<< endl;
}

int cal_size(int * arr)
{
    return sizeof(arr);
}

void merge(int arr[], int left_idx, int middle_idx, int right_idx)
{
    cout << "Left index: " << left_idx << endl;
    cout << "Right index: " << right_idx << endl;
    // cals length of left array and right array
    int left_length = middle_idx - left_idx + 1;
    int right_length = right_idx - middle_idx;
    cout << "-----> left l" << left_length << "\tR l: "<< right_length << endl;
    // Creates two subarrays
    int left_array[left_length];
    int right_array[right_length];
    for (int i = 0; i < left_length; i++)
    {
        cout << "Element : "<< arr[left_idx + i] << "\t";
        left_array[i] = arr[left_idx + i]; 
    }
    for (int i = 0; i < right_idx; i++)
    {
        right_array[i] = arr[middle_idx + 1 + i];
    }
    // Merges two sorted array
    cout << "Left array: "<<endl;
    printArray(left_array, cal_size(left_array));
    cout << "Right array: "<<endl;
    printArray(right_array, cal_size(right_array));
    int i = 0, j = 0, k = left_idx;
    while (i < left_length && j < right_length)
    {
        if (left_array[i] < right_array[j])
        {
            arr[k] = left_array[i];
            i++;
        }
        else
        {
            arr[k] = right_array[j];
            j++;
        }
        k ++;
    }
    while (i < left_length)
    {
        arr[k] = left_array[i];
        i++;
        k++;

    }
    while (j < right_length)
    {
        arr[k] = right_array[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left_idx, int right_idx)
{
    if (left_idx >= right_idx)
        return;
    // cals middle index
    int middle_idx = left_idx + (right_idx - left_idx) / 2;
    mergeSort(arr, left_idx, middle_idx);
    mergeSort(arr, middle_idx + 1, right_idx);
    merge(arr, left_idx, middle_idx, right_idx);
    printArray(arr, cal_size(arr));
}

int main()
{
    // Init
    int arr[] = {12, 67, 1, 56, 234, 906, 234, 0, 45};
    printArray(arr, cal_size(arr));
    int length = cal_size(arr);
    mergeSort(arr, 0, length - 1);
    return 0;
}