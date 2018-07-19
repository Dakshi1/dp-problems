#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long int l=0,r=2361;
	long long int ans=0;
	bool isincluded;
	for(long long int i=l; i<=r;i++)
	{
		int count=0;
		isincluded=true;
		for(long long int j=0;;j++)
		{
			long long int p=pow(2,j);
			if(p>i)
				break;
			if(p & i)
			{
				count++;
			}
			if(count > 3)
			{
				isincluded=false;
				break;
			}
		}
		if(isincluded)
			ans++;
	}
	cout << ans << endl;
	return 0;
} 
