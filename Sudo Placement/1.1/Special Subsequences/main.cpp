#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s="abc";
	int n=s.length();
	int total_count=pow(2,n)-1;
	vector<string> v_s;
	for(int i=1;i<=total_count;i++)
	{
		string temp="";
		for(int j=0; ; j++)
		{
			int p=pow(2, j);
			if(p>i)
				break;
			if(p & i)
				temp.insert(0, 1, s[n-1-j]);
		}
		int l=temp.length();
		v_s.push_back(temp);
		string temp1=temp;
		for(int k=1;k<pow(2, l);k++)
		{
			for(int m=0;;m++)
			{
				int p=pow(2, m);
				if(p > k)
					break;
				if(p & k)
					temp1[l-1-m]=temp1[l-1-m]-32;
			}
			v_s.push_back(temp1);
			temp1=temp;
		}
		
		//cout << temp << endl;
	}
	sort(v_s.begin(), v_s.end());
	cout << v_s.size() << endl;
	for(int i=0;i<v_s.size();i++)
	{
		cout << v_s[i] << endl;
	}
} 
