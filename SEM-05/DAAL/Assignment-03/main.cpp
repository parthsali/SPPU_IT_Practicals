#include <bits/stdc++.h>

using namespace std;

bool isSafe(vector<vector<int>> v, int x, int y, int n)
{

    for (int row = 0; row < x; row++)
    {
        if (v[row][y] == 1)
        {
            return false;
        }
    }

    int row = x;
    int col = y;

    while (row >= 0 && col >= 0)
    {
        if (v[row][col] == 1)
        {
            return false;
        }
        row--;
        col--;
    }

    row = x;
    col = y;
    while (row >= 0 && col < n)
    {
        if (v[row][col] == 1)
        {
            return false;
        }
        row--;
        col++;
    }

    return true;
}

bool nQueen(vector<vector<int>> &v, int x, int n)
{
    if (x >= n)
    {
        return true;
    }

    for (int col = 0; col < n; col++)
    {
        if (isSafe(v, x, col, n))
        {
            v[x][col] = 1;

            if (nQueen(v, x + 1, n))
            {
                return true;
            }

            v[x][col] = 0; // backtracking
        }
    }

    return false;
}

int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    vector<vector<int>> v(n, vector<int>(n, 0));

    if (nQueen(v, 0, n))
    {
        cout << "Solution exists" << endl;
        for (auto row : v)
        {
            for (auto col : row)
            {
                cout << col << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "Solution does not exist" << endl;
    }
}