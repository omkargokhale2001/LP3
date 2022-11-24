#include <bits/stdc++.h>
using namespace std;

void display(vector<vector<int>> a)
{
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j])
            {
                cout << "Q ";
            }
            else
            {
                cout << "_ ";
            }
        }
        cout << endl;
    }
}

bool isSafe(vector<vector<int>> a, int row, int col)
{
    int i = row;
    while (i >= 0)
    {
        if (a[i--][col])
        {
            return false;
        }
    }
    int j = col;
    i = row;
    while (i >= 0 && j >= 0)
    {
        if (a[i--][j--])
        {
            return false;
        }
    }
    i = row;
    j = col;
    while (j < a.size() && i >= 0)
    {
        if (a[i--][j++])
        {
            return false;
        }
    }
    return true;
}

bool nqueen(vector<vector<int>> &a, int row)
{
    if (row >= a.size())
    {
        return true;
    }
    for (int i = 0; i < a.size(); i++)
    {
        if (isSafe(a, row, i))
        {
            a[row][i] = 1;
            if (nqueen(a, row + 1))
            {
                return true;
            }
        }
        a[row][i] = 0;
    }
    return false;
}

int main()
{
    cout << "Enter size of board:" << endl;
    int n;
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    cout << "Write column number of first queen:" << endl;
    int col;
    cin >> col;
    board[0][col] = 1;
    if (nqueen(board, 1))
    {
        display(board);
    }
    else
    {
        cout << "Solution is impossible!" << endl;
    }
    return 0;
}