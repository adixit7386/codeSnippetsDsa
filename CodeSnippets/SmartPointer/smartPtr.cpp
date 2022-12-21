#include <bits/stdc++.h>
using namespace std;

#define loop(n) for (int i = 0; i < n; i++)

class smartPtr
{
    int *ptr;

public:
    smartPtr(int *p = NULL)
    {
        ptr = p;
    }
    ~smartPtr()
    {
        delete ptr;
    }
    int &operator*()
    {
        return *ptr;
    }
};
int main()
{
    smartPtr ptr(new int());
    *ptr = 20;
    cout << *ptr;
    return 0;
}