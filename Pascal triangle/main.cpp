#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	std::vector<int> v[n];
	v[0].push_back(1);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(j==0 || j==i)
			{
				v[i].push_back(1);
			}
			else
			{
				v[i].push_back(v[i-1][j]+v[i-1][j-1]);
			}
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
} 
