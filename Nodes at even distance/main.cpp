#include<bits/stdc++.h>
using namespace std;

int main()
{
	int count=0;
	queue<int> q;
	q.push(1);
	while(!q.empty())
	{
		count=q.size();
		while(count>0)
		{
			int ele=q.front();
			q.pop();
			for(int i=0;i<a[ele].size();i++)
			{
				q.push(a[ele][i]);
			}
			count--;
		}
	}
} 
