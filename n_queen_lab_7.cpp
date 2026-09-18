#include <iostream>
using namespace std;

int n;
int board[20][20];

bool isSafe(int row, int col)
{
    // Check left side of the same row
    for (int j = 0; j < col; j++)
    {
        if (board[row][j] == 1)
            return false;
    }

    // Check upper-left diagonal
    for (int i = row - 1, j = col - 1;
         i >= 0 && j >= 0;
         i--, j--)
    {
        if (board[i][j] == 1)
            return false;
    }

    // Check lower-left diagonal
    for (int i = row + 1, j = col - 1;
         i < n && j >= 0;
         i++, j--)
    {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

bool solveNQueen(int col)
{
    // All queens are placed
    if (col == n)
        return true;

    // Try every row
    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col))
        {
            // Place queen
            board[row][col] = 1;

            // Recursively place next queen
            if (solveNQueen(col + 1))
                return true;

            // Backtrack
            board[row][col] = 0;
        }
    }
    return false;
}
int main()
{
    cout << "Enter the value of N: ";
    cin >> n;

    // Initialize board
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i][j] = 0;
        }
    }

    if (solveNQueen(0))
    {
        cout << "\nOne Solution:\n";

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "\nNo solution exists.\n";
    }
    return 0;
}