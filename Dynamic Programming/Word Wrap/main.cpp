#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int printSolution (int p[], int n)
{
    int k;
    if (p[n] == 1)
        k = 1;
    else
        k = printSolution (p, p[n]-1) + 1;
    printf ("Line number %d: From word no. %d to %d \n", k, p[n], n);
    return k;
}
int word_wrap(int arr[], int n, int m)
{
	// shows least count to put words i to j in a single line
	int lc[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			if(i==j)
				lc[i][j]=m-arr[i];
			else
			{
				lc[i][j]=lc[i][j-1] - arr[j] - 1;
			}
			//cout << "cost " << lc[i][j] << endl;
		}
	}
	for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (lc[i][j] < 0)
                lc[i][j] = INT_MAX;
            else if (j == n-1 && lc[i][j] >= 0)
                lc[i][j] = 0;
            else
                lc[i][j] = lc[i][j]*lc[i][j];
            //cout << "cost " << lc[i][j] << endl;
        }
    }
	int c[n+1], p[n+1];
	c[0]=0;
	
	for(int i=1;i<=n;i++)
	{
		c[i]=INT_MAX;
		for(int j=1;j<=i;j++)
		{
			if(lc[j-1][i-1]!=INT_MAX && c[j-1]!=INT_MAX && (c[j-1]+lc[j-1][i-1])<c[i])
			{
				c[i]=c[j-1]+lc[j-1][i-1];
				p[i]=j;
			}
		}
		
	}
	for(int i=1;i<=n;i++)
	{
		cout << "line " << p[i] << " cost " << c[i] << endl; 
	}
	printSolution(p, n);
	return c[n];
}

int main()
{
	int arr[]={3,2,2,5};
	int n=4;
	int m=6;
	cout << word_wrap(arr, n, m) << endl;
}