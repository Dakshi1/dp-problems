#include <bits/stdc++.h>

using namespace std;
void check(int arr[], int n)
{
    pair<int, int> p[n];
    int k;
    if(n<=1)
    {
        cout << -1;
        return;
    }
    else if(n==2 && arr[0]==arr[1])
    {
        cout << -1;
        return;
    }
    else if(n==2)
    {
        cout << 1 << endl;
        cout  << 1;
    }
    else
    {

        for(int i=0;i<n;i++)
        {
            p[i]=make_pair(arr[i], i);
        }
        sort(p, p+n);
        if(n%2==0)
            k=n/2-2;
        else
            k=(n/2)-1;
        cout << k+1 << endl;
        for(int i=0;i<=k;i++)
        {
            int val=p[i].second +1;
            cout << val << " ";
        }
    }
}
int main()
{
    int n, k;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>> arr[i];
    }
    check(arr, n);
    return 0;
}
