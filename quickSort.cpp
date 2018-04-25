#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void splitByKey(int arr[], int key, int& i, int& j);
void quickSort(int arr[], int l, int r);
void printArr(int n, int arr[]);

int main()
{
    srand(time(0));

    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    printArr(n,arr);

    quickSort(arr, 0, n - 1);

    printArr(n, arr);

    return 0;
}

void splitByKey(int arr[], int key, int& i, int& j)
{
    while (i <= j)
    {
        while (arr[i] < key)
        {
            i++;
        }
        while (arr[j] > key)
        {
            j--;
        }

        if (i <= j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
}

void quickSort(int arr[], int l, int r)
{
    if (l <= r)
    {
        int i = l, j = r;

        int pos = rand() % (r - l) + l;

        int key = arr[pos];

        splitByKey(arr, key, i, j);

        if (l < j)
        {
            quickSort(arr, l, j);
        }
        if (i < r)
        {
            quickSort(arr, i, r);
        }
    }
}

void printArr(int n, int arr[])
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
