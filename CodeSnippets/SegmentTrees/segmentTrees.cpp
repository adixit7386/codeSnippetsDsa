#include <bits/stdc++.h>
using namespace std;
#define loop(n) for (int i = 0; i < n; i++)
int segmentTree(int tree[], int arr[], int ss, int se, int si, int n)
{
    if (ss == se)
    {
        tree[si] = arr[ss];
        return tree[si];
    }
    int mid = (ss + se) / 2;

    tree[si] = segmentTree(tree, arr, ss, mid, 2 * si + 1, n) + segmentTree(tree, arr, mid + 1, se, 2 * si + 2, n);

    return tree[si];
}

int getSum(int tree[], int ss, int se, int qs, int qe, int si)
{
    if (se < qs || ss > qe)
    {
        return 0;
    }
    if (ss >= qs && qe >= se)
    {
        return tree[si];
    }

    int mid = (ss + se) / 2;
    return getSum(tree, ss, mid, qs, qe, 2 * si + 1) + getSum(tree, mid + 1, se, qs, qe, 2 * si + 2);
}

void updateSegmentTree(int tree[], int ss, int se, int i, int si, int diff)
{

    if (i < ss || i > se)
    {
        return;
    }

    tree[si] += diff;
    if (se > ss)
    {
        int mid = (ss + se) / 2;
        updateSegmentTree(tree, ss, mid, i, 2 * si + 1, diff);
        updateSegmentTree(tree, mid + 1, se, i, 2 * si + 2, diff);
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
    int tree[4 * n] = {0};
    segmentTree(tree, arr, 0, n - 1, 0, n);
    int k = 4 * n;
    loop(k)
    {
        cout << tree[i] << " ";
    }
    cout << getSum(tree, 0, n - 1, 2, 3, 0);
    updateSegmentTree(tree, 0, n - 1, 2, 0, 20);
    cout << getSum(tree, 0, n - 1, 2, 3, 0);
    return 0;
}
