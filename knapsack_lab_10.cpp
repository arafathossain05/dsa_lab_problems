#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n = 4;
    int C = 20;

    int profit[] = {15, 25, 13, 23};
    int weight[] = {2, 6, 12, 9};

    int dp[n + 1][C + 1];

    // Initialize DP table
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= C; w++)
        {
            if (i == 0 || w == 0)
                dp[i][w] = 0;

            else if (weight[i - 1] <= w)
            {
                dp[i][w] = max(
                    dp[i - 1][w],
                    profit[i - 1] + dp[i - 1][w - weight[i - 1]]
                );
            }

            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Print DP Table
    cout << "\nDP Table:\n\n";

    cout << setw(6) << "i/w";

    for (int w = 0; w <= C; w++)
        cout << setw(4) << w;

    cout << endl;

    for (int i = 0; i <= n; i++)
    {
        cout << setw(6) << i;

        for (int w = 0; w <= C; w++)
            cout << setw(4) << dp[i][w];

        cout << endl;
    }

    // Maximum profit
    cout << "\nMaximum Profit = " << dp[n][C] << endl;

    // Find selected items
    int w = C;

    cout << "Selected Items: ";

    for (int i = n; i > 0; i--)
    {
        if (dp[i][w] != dp[i - 1][w])
        {
            cout << "Item " << i << " ";
            w = w - weight[i - 1];
        }
    }

    cout << endl;

    // Calculate total weight
    int totalWeight = 0;

    for (int i = n; i > 0; i--)
    {
        if (dp[i][C] != dp[i - 1][C])
        {
            totalWeight += weight[i - 1];
            C -= weight[i - 1];
        }
    }

    cout << "Total Weight = " << totalWeight << endl;

    return 0;
}