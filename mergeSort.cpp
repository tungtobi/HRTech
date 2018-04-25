#include <iostream>

int* getArray(int n);
void merge(int arr[], int pos, int l, int r);
void mergeSort(int arr[], int l, int r);
void printArray(int n, int arr[]);

int main(int argc, char* argv[])
{
    int number;
    std::cin >> number;
    int* arr = getArray(number);

    printArray(number, arr);

    mergeSort(arr, 0, number - 1);

    printArray(number, arr);

    return 0;
}

int* getArray(int n)
{
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    return arr;
}

void merge(int arr[], int pos, int l, int r)
{
    int size1 = pos - l + 1;
    int size2 = r - pos;

    int leftArr[size1], rightArr[size2];

    for (int i = 0; i < size1; i++)
    {
        leftArr[i] = arr[l + i];
    }
    for (int i = 0; i < size2; i++)
    {
        rightArr[i] = arr[pos + i + 1];
    }

    int i = 0, j = 0, k = l;

    while (i < size1 && j < size2)
    {
        int tmp;

        if (leftArr[i] <= rightArr[j])
        {
            tmp = leftArr[i];
            i++;
        }
        else
        {
            tmp = rightArr[j];
            j++;
        }

        arr[k] = tmp;
        k++;
    }

    while (i < size1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < size2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int pos = l + (r - l) / 2;

        mergeSort(arr, l, pos);
        mergeSort(arr, pos + 1, r);

        merge(arr, pos, l, r);
    }
}

void printArray(int n, int arr[])
{
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
