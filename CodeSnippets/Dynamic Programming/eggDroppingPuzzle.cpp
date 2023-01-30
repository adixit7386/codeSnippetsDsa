#include <bits/stdc++.h>
using namespace std;
int eggDrop(int eggs, int floors)
{
    // if (floors == 1)
    // {
    //     return 1;
    // }
    // if (eggs == 1)
    // {
    //     return floors;
    // }
    // int res = floors;

    // for (int i = 2; i < floors; i++)
    // {
    //     res = min(res, 1 + max(eggDrop(eggs - 1, i - 1), eggDrop(eggs, floors - i)));
    // }

    vector<vector<int>> dp(eggs + 1, vector<int>(floors + 1, 0));

    for (int i = 1; i <= floors; i++)
    {
        dp[1][i] = i;
        }
    for (int i = 1; i <= eggs; i++)
    {
        dp[i][1] = 1;
        dp[i][0] = 0;
    }
    int res;
    for (int j = 2; j <= floors; j++)
    {
        for (int i = 2; i <= eggs; i++)
        {

            res = INT_MAX;
            for (int k = 1; k <= j; k++)
            {
                res = min(res, 1 + max(dp[i - 1][k - 1], dp[i][j - k]));
            }
            dp[i][j] = res;
        }
    }
    return res;
}
int main()
{
    int n, k;
    cin >> n >> k;
    cout << eggDrop(n, k);
    return 0;
}