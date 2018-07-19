#include<bits/stdc++.h>
using namespace std;
bool order(pair<pair<int, int>, pair<int, int> > p, pair<pair<int, int>, pair<int, int> > q)
{
	return (p.second.second < q.second.second);
}
int main()
{
	int n=3;
	int arr[n][3]={ {1, 2, 3}, {4, 5, 6}, {3, 4, 1} };
	pair<pair<int, int>, pair<int, int> > p[n*3];

	for(int i=0;i<n;i++)
	{
		sort(arr[i], arr[i]+3);
		p[3*i]=make_pair(make_pair(arr[i][0],arr[i][1]), make_pair(arr[i][2], arr[i][0]*arr[i][1]));
		p[3*i+1]=make_pair(make_pair(arr[i][1],arr[i][2]), make_pair(arr[i][0], arr[i][1]*arr[i][2]));
		p[3*i+2]=make_pair(make_pair(arr[i][0],arr[i][2]), make_pair(arr[i][1], arr[i][0]*arr[i][2]));
	}
	sort(p, p+n*3, order);
	int l=0, b=0, h=0;
	for(int i=0;i<n*3;i++)
	{
		//cout << p[i].first.first << " " << p[i].first.second << " " << p[i].second.first << " " << p[i].second.second;
		if(p[i].first.first > l && p[i].first.second > b)
		{
			l=p[i].first.first;
			b=p[i].first.second;
			//cout << " choosen";
			h+=p[i].second.first;
		}
		//cout << endl;
	}
	cout << h << endl;
	return 0;
} 
