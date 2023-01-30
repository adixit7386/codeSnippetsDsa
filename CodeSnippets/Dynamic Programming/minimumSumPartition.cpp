#include <bits/stdc++.h>
using namespace std;
int minSum(int arr[], int n, int currSum, int arrSum)
{
    if (n == 0)
    {
        return abs((arrSum - currSum) - currSum);
    }

    return min(minSum(arr, n - 1, currSum + arr[n - 1], arrSum), minSum(arr, n - 1, currSum, arrSum));
}
int main()
{
    int n;
    cin >> n;

    int arr[n];

    int arrSum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        arrSum += arr[i];
    }
    cout << minSum(arr, n, 0, arrSum);
    return 0;
}