#include <bits/stdc++.h>

using namespace std;
int egg_drop(int n, int k)
{
    if(k==0 || k==1)
        return k;
    if(n==1)
        return k;
    int res, minx=INT_MAX;

    for(int i=1;i<=k;i++)
    {
        res=max(egg_drop(n-1, i-1), egg_drop(n, k-i));
        if(res<minx)
            minx=res;
    }
    return 1+minx;
}

int main()
{
    int n=2, k=10;

    cout << egg_drop(n, k);

    return 0;
}
