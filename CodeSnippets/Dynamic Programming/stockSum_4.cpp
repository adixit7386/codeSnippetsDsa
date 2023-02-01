#include <bits/stdc++.h>
using namespace std;
int stock(vector<int> &arr, int i, int j)
{
    int ans = 0;

    for (int k = i + 1; k <= j; k++)
    {
        if (arr[k] > arr[k - 1])
        {
            ans += (arr[k] - arr[k - 1]);
        }
    }

    return ans;
}
int stockSum(vector<int> &arr, int i, int j, int k)
{
    if (k == 0)
    {
        return 0;
    }
    if (j <= i)
    {
        return 0;
    }
    if (i + 1 == j)
    {
        return arr[j] > arr[i] ? arr[j] - arr[i] : 0;
    }
    int res = 0;

    for (int ii = i; ii <= j; ii++)
    {
        for (int jj = i + 1; jj <= j; jj++)
        {
            res = max(res, stock(arr, i, j) + stockSum(arr, i, ii - 1, k - 1) + stockSum(arr, jj + 1, j, k - 1));
        }
    }
    return res;
}
int main()
{
    int x;
    cin >> x;
    while (x--)
    {
        int n;
        cin >> n;
        vector<int> arr(0, n);
        for (int i = 0; i < n; i++)
        {
            int t;
            cin >> t;

            arr.push_back(t);
        }
        cout << stockSum(arr, 0, n - 1, 2) << endl;
    }
    return 0;
}