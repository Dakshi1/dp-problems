#include<bits/stdc++.h>
using namespace std;
int dp[100][100];
int optimal_tree(pair<int, int> p[], int st, int en, int level)
{
	if(st>en)
	{
		dp[st][en]=0;
		return dp[st][en];
	}
	if(st==en)
	{
		dp[st][en]=(level*p[st-1].second);
		return dp[st][en];
	}
	int temp;
	int cost=INT_MAX;
	if(dp[st][en]==-1)
	{
		for(int i=st;i<=en;i++)
		{
			temp=optimal_tree(p, st, i-1, level+1) + optimal_tree(p, i+1, en, level+1) + level*p[i-1].second;
			cost=min(cost, temp);
		}
		dp[st][en]=cost;
	}
	
	return dp[st][en];
}
int main()
{
	pair<int, int> p[3];
	int n=sizeof(p)/sizeof(p[0]);
	memset(dp, -1, sizeof(dp));
	p[0].first=10;p[0].second=34;
	p[1].first=12;p[1].second=8;
	p[2].first=20;p[2].second=50;

	cout << optimal_tree(p, 1, n, 1) << endl;
	return 0;
} 
