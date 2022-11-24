#include <iostream>
using namespace std;

int knapsack(vector<int> val, vector<int> weights, int c)
{
    int n = val.size();
    vector<vector> dp(n + 1, vector<int>(c + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        for (intj = 0; j <= c; i++)
        {
            dp[i][j] = dp[i - 1][j];
            if (weights[i - 1] <= j)
            {
                dp[i][j] = max(dp[i][j], val(i - 1) + dp[i - 1][j - weights[i - 1]]);
            }
        }
    }
}

int main()
{

    return 0;
}