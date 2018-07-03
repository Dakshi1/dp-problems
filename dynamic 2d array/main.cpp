#include <bits/stdc++.h>

using namespace std;

int **arr;
int main()
{
    int n;
    cin >> n;
    arr=new int* [n];
    for(int i=0;i<n;i++)
    {
        arr[i]=new int[n];
        memset(arr[i], false, n*sizeof(int));
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout << arr[i][j] << "   " ;
        }
        cout << endl;
    }
    return 0;
}
