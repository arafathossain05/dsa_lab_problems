#include <iostream>
using namespace std;

void merge(int a[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = 0;
    int temp[100];

    cout << "\nMerging: ";

    for (int x = low; x <= high; x++)
        cout << a[x] << " ";

    cout << "\nComparison: ";

    while (i <= mid && j <= high)
    {
        cout << "(" << a[i] << " vs " << a[j] << ") ";

        if (a[i] <= a[j])
        {
            temp[k] = a[i];
            i++;
        }
        else
        {
            temp[k] = a[j];
            j++;
        }

        k++;
    }

    while (i <= mid)
    {
        temp[k] = a[i];
        i++;
        k++;
    }

    while (j <= high)
    {
        temp[k] = a[j];
        j++;
        k++;
    }

    for (i = low, k = 0; i <= high; i++, k++)
    {
        a[i] = temp[k];
    }

    cout << "\nAfter Merge: ";

    for (i = low; i <= high; i++)
        cout << a[i] << " ";

    cout << endl;
}

void mergeSort(int a[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        cout << "\nDivide: ";

        for (int i = low; i <= high; i++)
            cout << a[i] << " ";

        cout << "\nLeft : ";

        for (int i = low; i <= mid; i++)
            cout << a[i] << " ";

        cout << "\nRight: ";

        for (int i = mid + 1; i <= high; i++)
            cout << a[i] << " ";

        cout << endl;

        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);

        merge(a, low, mid, high);
    }
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int a[100];
    cout << "Enter the elements: ";

    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "\n========== MERGE SORT PROCESS ==========\n";

    mergeSort(a, 0, n - 1);

    cout << "\n========== FINAL RESULT ==========\n";

    cout << "Sorted Array: ";

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << endl;
    return 0;
}