#include <iostream>
using namespace std;

class nqueen
{
public:
    bool check(int **arr, int row, int col, int n);
    bool solve_nqueen(int **arr, int col, int n);
};

bool nqueen::check(int **arr, int row, int col, int n)
{
    int i, j;

    // Check row on the left side
    for (i = 0; i < col; i++)
    {
        if (arr[row][i])
        {
            return false;
        }
    }

    // Check upper diagonal on the left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (arr[i][j])
        {
            return false;
        }
    }

    // Check lower diagonal on the left side
    for (i = row, j = col; j >= 0 && i < n; i++, j--)
    {
        if (arr[i][j])
        {
            return false;
        }
    }

    cout << "Placed queen q" << col + 1 << " at row " << row + 1 << "\n";
    return true;
}

bool nqueen::solve_nqueen(int **arr, int col, int n)
{
    // To check if all queens are placed
    if (col >= n)
    {
        cout << "===============================================================\n";
        cout << "ALL QUEENS ARE PLACED\n";
        cout << "===============================================================\n";
        return true;
    }

    for (int i = 0; i < n; i++)
    {
        if (check(arr, i, col, n))
        {
            arr[i][col] = 1;

            // Displaying placed queens
            cout << "===============================================================\n";
            for (int k = 0; k < n; k++)
            {
                for (int l = 0; l < n; l++)
                {
                    if (arr[k][l] == 1)
                    {
                        cout << "q" << l + 1 << "\t";
                    }
                    else
                    {
                        cout << "0\t";
                    }
                }
                cout << "\n";
            }
            cout << "===============================================================\n";

            // Iterate to the next column
            if (solve_nqueen(arr, col + 1, n))
            {
                return true;
            }

            cout << "===============================================================\n";
            cout << "Backtrack queen q" << col + 1 << "\n";
            cout << "===============================================================\n";
            arr[i][col] = 0; // Backtrack
        }
    }

    return false;
}

int main()
{
    nqueen q1;
rep:
    int n;
    cout << "Enter the chessboard size (size should be greater than 3):\n";
    cin >> n;
    cout << "===============================================================\n";

    if (n <= 3)
    {
        cout << "Please enter a size greater than 3:\n";
        cout << "===============================================================\n";
        goto rep;
    }

    int **arr = new int *[n];

    cout << "Initially the board is:\n";
    // Initially setting value to 0
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
            cout << "0\t";
        }
        cout << "\n";
    }

    cout << "===============================================================\n";
    // Solve the problem
    q1.solve_nqueen(arr, 0, n);
    cout << "===============================================================\n";

    cout << "AFTER PLACING THE QUEEN: \n";
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n; k++)
        {
            if (arr[i][k] == 1)
            {
                cout << "q" << k + 1 << "\t";
            }
            else
            {
                cout << "0\t";
            }
        }
        cout << "\n";
    }

    cout << "===============================================================\n";

    return 0;
}