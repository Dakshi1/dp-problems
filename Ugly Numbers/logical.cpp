#include<bits/stdc++.h>
using namespace std;
int find_num(int n)
{
	int i2=0, i3=0, i5=0;
	int next_2, next_3, next_5;
	int ugly_no[n];
	ugly_no[0]=1;
	next_2=ugly_no[0]*2;
	next_3=ugly_no[0]*3;
	next_5=ugly_no[0]*5;
	int temp;
	for (int i = 1; i < n; ++i)
	{
		temp=min(min(next_2, next_3), next_5);
		ugly_no[i]=temp;
		if(temp==next_2)
		{
			i2++;
			next_2=ugly_no[i2]*2;
		}
		else if(temp==next_3)
		{
			i3++;
			next_3=ugly_no[i3]*3;
		}
		else
		{
			i5++;
			next_5=ugly_no[i5]*5;
		}
	}
}
int main() 
{
	int n=150;
	cout << find_num(n)<< endl;
} 
