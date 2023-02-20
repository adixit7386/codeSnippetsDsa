#include <iostream>
#include <vector>
using namespace std;
int fib(int n, vector<int> &dp)
{
    if (n == 0)
    {
        return -1;
    }
    if (n == 1 || n == 2)
    {
        return n - 1;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
    return dp[n];
}
int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    dp[1] = 0;
    dp[2] = 1;
    cout << fib(n, dp) << endl;

    return 0;
}