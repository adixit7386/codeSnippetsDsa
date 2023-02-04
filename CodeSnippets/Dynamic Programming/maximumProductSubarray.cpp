#include <bits/stdc++.h>
using namespace std;

#define loop(n) for (int i = 0; i < n; i++)
int maxProduct(vector<int> &nums)
{
    if (nums.size() == 1)
    {
        return nums[0];
    }
    int ans = INT_MIN;
    int sub_res = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        sub_res = nums[i];

        for (int j = i + 1; j < nums.size(); j++)
        {
            ans = max(ans, sub_res);
            sub_res *= nums[j];
        }
        ans = max(ans, sub_res);
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    loop(n)
    {
        cin >> arr[i];
    }
    cout << maxProduct(arr);

    return 0;
}