#include<bits/stdc++.h>
using namespace std;
int check_divi(int a, int b, int check[])
{
	while(a%b==0)
	{
		a=a/b;
		if(check[a]==1)
		{
			a==1;
		}
	}
	return a;
}
int find_no(int n)
{
	if(n==1)
		return 1;
	int ugly_no[n];
	ugly_no[0]=1;
	int w=1000000;
	int check[w];
	for(int i=0;i<w;i++)
		check[i]=0;
	int ugly_count=0, i=1;
	while(ugly_count<n)
	{
		if(check_divi(check_divi(check_divi(i,2, check),3, check),5, check)==1)
		{
			ugly_no[ugly_count]=i;
			cout << ugly_no[ugly_count] << endl;
			ugly_count++;
			check[i]=1;
		}
		i++;
	}
	return ugly_no[n-1];
}
int main()
{
	int res=1;
	int a=2, b=3,c=5;
	//int ar=1000000000;
	//cout << ar << endl;
	find_no(150);

	return 0;
} 
