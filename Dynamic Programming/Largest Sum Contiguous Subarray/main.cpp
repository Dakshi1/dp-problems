#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n=8;
	int arr[]={-2, -3, 4, -1, -2, 1, 5, -3};
	int sum=arr[0], max_sum=arr[0];
	for(int i=1;i<n;i++)
	{
		if(sum<0)
		{
			sum=arr[i];
		}
		else
		{
			sum+=arr[i];
		}
		if(sum>max_sum)
		{
			max_sum=sum;
		}
	}
	cout << max_sum << endl;
	return 0;
} 
