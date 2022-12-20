#include <bits/stdc++.h>
using namespace std;

#define loop(n) for (int i = 0; i < n; i++)
void updateBit(int arr[], int Tree[], int index, int n)
{
    int val = arr[index];
    index = index + 1;

    while (index <= n)
    {
        Tree[index] += val;

        index += index & (-index);
    }

    return;
}
void constructFt(int arr[], int Tree[], int n)
{
    for (int i = 0; i < n; i++)
    {
        updateBit(arr, Tree, i, n);
    }
    return;
}

int getSum(int Tree[], int index, int n)
{
    index = index + 1;
    int sum = 0;

    while (index > 0)
    {

        sum += Tree[index];

        index -= index & (-index);
    }
    return sum;
}

void updateFt(int arr[], int Tree[], int index, int new_val, int n)
{
    int diff = new_val - arr[index];
    index = index + 1;

    while (index <= n)
    {
        Tree[index] += diff;
        index += index & (-index);
    }
    return;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    loop(n)
    {
        cin >> arr[i];
    }
    int Tree[n + 1] = {0};
    constructFt(arr, Tree, n);
    updateFt(arr, Tree, 2, 40, n);
    cout << getSum(Tree, 2, n);
    return 0;
}