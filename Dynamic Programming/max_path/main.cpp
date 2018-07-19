// You can do it bro
#include<bits/stdc++.h>
using namespace std;

int max(int x, int y, int z)
{
    return max(max(x, y), z);
}
int max_cost(int n, int cost[][20])
{
    int helper[n+1][n+2];
    for(int i=0;i<n+1;i++)
    {
        helper[i][n+1]=0;
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0 || j==0)
            {
                helper[i][j]=0;
            }
            else
            {
                helper[i][j]=cost[i-1][j-1]+max(helper[i-1][j-1],
                                            helper[i-1][j],
                                            helper[i-1][j+1]);
            }
        }
    }
    int max=0;
    for(int i=0;i<n+2;i++)
    {
        if(helper[n][i]>max)
            max=helper[n][i];
    }
    return max;
}
int main()
 {
	//code
	int t;
	cin >> t;
	while(t>0)
	{
	    int n;
	    cin >> n;
	    int cost[n][20];
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            cin >> cost[i][j];
	        }
	    }
	    cout << max_cost(n, cost) << endl;
	    t--;
	}
	return 0;
}
