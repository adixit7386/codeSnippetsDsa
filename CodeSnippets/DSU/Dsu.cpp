#include <bits/stdc++.h>
using namespace std;
int find(int x, int parent[])
{
    if (x == parent[x])
    {
        return x;
    }
    return parent[x];
}
bool areFriends(int x, int y, int parent[])
{
    return find(x, parent) == find(y, parent);
}
void unions(int x, int y, int parent[], int rank[])
{
    if (x == y)
    {
        return;
    }
    int x_rep = find(x, parent);
    int y_rep = find(y, parent);
    if (x_rep == y_rep)
    {
        return;
    }
    if (rank[x_rep] > rank[y_rep])
    {
        parent[y_rep] = x_rep;
    }
    else if (rank[x_rep] < rank[y_rep])
    {
        parent[y_rep] = x_rep;
    }
    else
    {
        parent[y_rep] = x_rep;
        rank[x_rep]++;
    }
    return;
}

int main()
{
    int n;

    cin >> n;
    int parent[n], rank[n];
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 1;
    }

    unions(1, 4, parent, rank);
    unions(1, 5, parent, rank);
    cout << areFriends(3, 5, parent);

    return 0;
}