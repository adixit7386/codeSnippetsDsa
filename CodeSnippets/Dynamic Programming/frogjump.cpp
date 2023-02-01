#include <bits/stdc++.h>
using namespace std;
bool frogJump(vector<int> arr, int n, int i, int l, int prev)
{
    cout << i << endl;
    if (i == n - 1)
    {
        return true;
    }
    if (l <= 0)
    {
        return false;
    }
    if (i > n - 1)
    {
        return false;
    }
    if (arr[i] != l + prev)
    {
        return false;
    }
    if (frogJump(arr, n, i + l - 1, l - 1, arr[i]) || frogJump(arr, n, i + l, l, arr[i]) || frogJump(arr, n, i + l + 1, l + 1, arr[i]))
    {
        return true;
    }
    return false;
}
int main()
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
    cout << frogJump(arr, n, 1, 1, arr[0]);
    cout << arr.size() << endl;
    return 0;
}