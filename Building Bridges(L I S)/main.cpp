#include<bits/stdc++.h>
using namespace std;
int max_brd(pair<int, int> p[], int n)
{
	int helper[n];
	for(int i=0;i<n;i++)
	{
		helper[i]=1;
	}
	for(int i=1;i<n;i++)
	{
		for(int j=i-1;j>=0;j--)
		{
			if(p[j].second<p[i].second && (1+ helper[j])>helper[i])
			{
				helper[i]=1+helper[j];
			}
		}
	}
	int maxx=INT_MIN;
	for(int i=0;i<n;i++)
	{
		maxx=max(maxx, helper[i]);
	}
	return maxx;
}
int main(int argc, char const *argv[])
 {
 	int n=8;
 	int a[8]={8, 1, 4, 3, 5, 2, 6, 7};
 	int b[8]={1, 2, 3, 4, 5, 6, 7, 8};
 	pair<int, int> p[8];
 	for(int i=0;i<n;i++)
 	{
 		p[i]=make_pair(a[i], b[i]);
 	}
 	sort(p, p+n);
 	cout << max_brd(p, n) << endl;
 	return 0;
 } 
