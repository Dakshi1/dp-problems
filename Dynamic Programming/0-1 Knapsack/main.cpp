#include <bits/stdc++.h>

using namespace std;
int knapsack(int weight[], int value[], int w, int n)
{
    int helper[w+1][n+1];

    for(int i=0; i<=w; i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0 || j==0)
                helper[i][j]=0;
            else if(i-weight[j-1]<0)
                helper[i][j]=helper[i][j-1];
            else
                helper[i][j]=max(value[j-1]+helper[i-weight[j-1]][j-1], helper[i][j-1]);

            cout << "helper[ " << i << " ]" << "[ " << j << " ] = " << helper[i][j] << endl;
        }
    }
    return helper[w][n];
}
int main()
{
    int weight[]={10, 20, 30};
    int value[]={60, 100, 120};
    int n=3;
    int w=50;
    cout << knapsack(weight, value, w, n);
    return 0;
}
