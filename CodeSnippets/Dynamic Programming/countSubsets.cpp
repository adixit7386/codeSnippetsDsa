#include <bits/stdc++.h>
using namespace std;

#define loop(n) for (int i = 0; i < n; i++)
int countSubsets(vector<int> &arr, int n, int sum)
{
    if (sum == 0)
    {
        return 1;
    }
    if (n == 0)
    {
        return 0;
    }

    int res = countSubsets(arr, n - 1, sum);
    if (arr[n - 1] <= sum)
    {
        res += countSubsets(arr, n - 1, sum - arr[n - 1]);
    }

    return res;
}
int main()
{
    int n, sum;
    cin >> n >> sum;
    vector<int> arr(n, 0);
    loop(n)
    {
        cin >> arr[i];
    }
    cout << countSubsets(arr, n, sum);

    return 0;
}