#include <iostream>
#include <vector>

using namespace std;

void printMatrix(vector<vector<int>> matrix)
{
    for (vector<int> i : matrix)
    {
        for (int j : i)
        {
            if (j == 1)
                cout << "Q"
                     << " ";
            else
                cout << "_"
                     << " ";
        }
        cout << endl;
    }
    cout << "******" << endl;
}

bool isValid(vector<vector<int>> matrix, int row, int col)
{
    int i = row;
    while (i >= 0)
    {
        if (matrix[i--][col])
            return false;
    }
    int j = col;
    i = row;
    while (i >= 0 && j >= 0)
    {
        if (matrix[i--][j--])
            return false;
    }
    i = row, j = col;
    while (i >= 0 && j < matrix.size())
    {
        if (matrix[i--][j++])
            return false;
    }
    return true;
}

bool n_queens(vector<vector<int>> &matrix, int row)
{
    if (row == matrix.size())
        return true;
    for (int i = 0; i < matrix.size(); i++)
    { // trying different columns
        if (isValid(matrix, row, i))
        {
            matrix[row][i] = 1;
            if (n_queens(matrix, row + 1))
                return true;
        }
        // backtrack
        matrix[row][i] = 0;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    int c;
    cout << "Enter column number of first queen:";
    cin >> c;
    matrix[0][c] = 1;
    if (n_queens(matrix, 1))
    {
        cout << "Solution:" << endl;
        printMatrix(matrix);
    }
    else
        cout << "No solution exists." << endl;
}