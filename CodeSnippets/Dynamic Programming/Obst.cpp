
#include <bits/stdc++.h>
using namespace std;

int sum(int freq[], int i, int j);

int optCost(int freq[], int n)
{
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int k = 0; k < n; k++)
    {
        dp[k][k] = freq[k];
    }

    for (int gap = 1; gap < n; gap++)
    {
        int j;
        for (int i = 0; i + gap < n; i++)
        {
            j = i + gap;
            int sums = sum(freq, i, j);
            int mins = INT_MAX;
            for (int r = i; r <= j; r++)
            {
                int sum = 0;
                if (r > i)
                {
                    sum += dp[i][r - 1];
                }
                if (r < j)
                {
                    sum += dp[r + 1][j];
                }
                mins = min(mins, sum);
            }
            dp[i][j] = sums + mins;
        }
    }
    return dp[0][n - 1];
}

int optimalSearchTree(int keys[],
                      int freq[], int n)
{

    return optCost(freq, n);
}

int sum(int freq[], int i, int j)
{
    int s = 0;
    for (int k = i; k <= j; k++)
        s += freq[k];
    return s;
}

int main()
{
    int keys[] = {10, 12, 20};
    int freq[] = {34, 8, 50};
    int n = sizeof(keys) / sizeof(keys[0]);
    cout << "Cost of Optimal BST is "
         << optimalSearchTree(keys, freq, n);
    return 0;
}

// This is code is contributed
// by rathbhupendra
