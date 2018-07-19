 
#include<bits/stdc++.h>
using namespace std;

pair<vector<int>, int> cal_cost(pair<int, int> p[], int st, int en)
{
	int cost=INT_MAX;
	int low, high;
	vector<int> v;
	if(st==en)
	{
		return make_pair(v, 0);
	}
	else if(en-st==1)
	{
		//cout << p[st-1].first << " " << p[st-1].second << " " << p[en-1].second << " " << p[st-1].first*p[st-1].second*p[en-1].second << endl;
		v.push_back(st);
		v.push_back(en);
		return make_pair(v, (p[st-1].first*p[st-1].second*p[en-1].second));
	}
	
	
	
	for(int k=st;k<en;k++)
	{
		int temp=0;
		vector<int> v_temp;
		if(k-st>1)
		{
			v_temp.push_back(st);
			v_temp.push_back(k);
		}
		if(en-(k+1)>1)
		{
			v_temp.push_back(k+1);
			v_temp.push_back(en);
		}
		//v.clear();
		pair<vector<int>, int> x=cal_cost(p, st, k);
		v_temp.insert(v_temp.end(), x.first.begin(), x.first.end());
		temp=x.second;
		x=cal_cost(p, k+1, en);
		v_temp.insert(v_temp.end(), x.first.begin(), x.first.end());
		temp += x.second + p[st-1].first*p[k-1].second*p[en-1].second;
		//cout << "temp " << temp << endl;
		//cost=min(cost, temp);
		if(temp<cost)
		{
			v=v_temp;
			cost=temp;
		}
		//cout << low << "   " << high << endl;
	}
	return make_pair(v, cost);
}
int main()
{
	//{40, 20, 30, 10, 30}
	pair<int, int> p[4];
	int n=sizeof(p)/sizeof(p[0]);
	if(n==2)
	{
		cout << "(AB)";
		return 0;
	}
	int output_size;
	
	p[0].first=40;p[0].second=20;
	p[1].first=20;p[1].second=30;
	p[2].first=30;p[2].second=10;
	p[3].first=10;p[3].second=30;

	pair<vector<int>, int> x=cal_cost(p, 1, 4);
	cout << x.second << endl;  
	for(int i=0;i<x.first.size();i++)
	{
		cout << x.first[i] << "  ";
	}
	cout << endl;
	
	output_size=2+n+x.first.size();
	vector<char> v(output_size, 'a');
	v[0]='(';v[output_size-1]=')';
	for(int i=0;i<x.first.size()/2;i++)
	{
		v[x.first[2*i]]='(';
		v[x.first[2*i+1]]=')';
	}
	int count=0;
	for(int i=0;i<v.size();i++)
	{
		if(v[i]=='a')
		{
			v[i]=(char)('A' + count);
			count++;
		}
	}
	int st=0;
	int en=1;
	for(int i=0;i<n;i++)
	{
		while(st<n && x.first[st]==i+1)
		{
			cout << "(";
			st +=2;
		}
		cout << ((char)('A' + i));
		while(en < n && x.first[en]==i+1)
		{
			cout << ")";
			en +=2;
		}
	}
	
	cout << endl;
	return 0;
}