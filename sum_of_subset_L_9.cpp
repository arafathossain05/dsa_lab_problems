#include <iostream>
using namespace std;

int n, d;
int set[100], subset[100];

void subsetSum(int index, int currentSum, int pos)
{
    // Target sum found
    if (currentSum == d)
    {
        cout << "{ ";

        for (int i = 0; i < pos; i++)
        {
            cout << subset[i] << " ";
        }

        cout << "}" << endl;
        return;
    }

    // All elements checked
    if (index == n)
    {
        return;
    }

    // Include current element
    if (currentSum + set[index] <= d)
    {
        subset[pos] = set[index];

        subsetSum(index + 1,
                  currentSum + set[index],
                  pos + 1);
    }

    // Exclude current element
    subsetSum(index + 1, currentSum, pos);
}

int main()
{
    cout << "Enter number of elements of the set: ";
    cin >> n;

    cout << "Enter the elements of the set: ";

    for (int i = 0; i < n; i++)
    {
        cin >> set[i];
    }

    cout << "Enter target sum: ";
    cin >> d;

    cout << "\nSubsets with sum " << d << " are:\n";

    subsetSum(0, 0, 0);

    return 0;
}