#include <bits/stdc++.h>
using namespace std;

#define loop(n) for (int i = 0; i < n; i++)
bool isSubsequence(string s, string t)
{
    int n = s.length();
    int m = t.length();

    int i = 0, j = 0;

    while (i < n)
    {
        if (s[i] == t[j])
        {
            i++;
            j++;
        }
        i++;

        if (j == m)
        {
            return true;
        }
        i++;
    }
    return false;
}
int main()
{

    string s, t;
    cin >> s >> t;
    cout << isSubsequence(s, t);

    return 0;
}