#include<bits/stdc++.h>
using namespace std;
int find_in_smaller(int arr[], int n, int b)
{
	if(n==0)
		return -1;
	int low=0;
	int high=n-1;
	bool found=false;
	int last_small=INT_MIN;
	while(low<=high)
	{
		int mid=low+(high-low)/2;
		if(arr[mid]<b)
		{
			last_small=mid;
			low=mid+1;
		}
		else
		{
			high=mid-1;
		}
	}
	return last_small;
}
int find_in_greater(int arr[], int n, int b)
{
	if(n==0)
		return -1;
	int low=0;
	int high=n-1;
	bool found=false;
	int last_greater=INT_MAX;
	while(low<=high)
	{
		int mid=low+(high-low)/2;
		if(arr[mid]>b)
		{
			last_greater=mid;
			high=mid-1;
		}
		else
		{
			low=mid+1;
		}
	}
	return last_greater;
}
int binary_search(int arr[], int n, int b)
{
	if(n==0)
		return -1;
	int low=0;
	int high=n-1;
	//bool found=false;
	while(low<=high)
	{
		int mid=low+(high-low)/2;
		if(arr[mid]==b)
			return mid;
		else if(arr[mid]<b)
			low=mid+1;
		else
			high=mid-1;
	}
	return -1;
}
int main()
{
	int n=7;
	int arr[n]={1,3,5,7,7,8,9};
	int b;
	cin >> b;
	int last_small, last_greater;
	last_small=find_in_smaller(arr, n, b);
	last_greater=find_in_greater(arr, n, b);
	//cout << last_small << endl;
	//cout << last_greater << endl;
	
	if(binary_search(arr, n, b)!=-1)
	{
		if(last_small!=INT_MIN && last_greater!=INT_MAX)
		{
			cout << last_small+1 << " " << last_greater-1 << endl;
		}
		else if(last_small==INT_MIN &&last_greater==INT_MAX)
		{
			cout << "0 " << n-1 <<endl;
		}
		else if(last_greater==INT_MAX)
		{
			cout << last_small+1 << " " << n-1 << endl;
		}
		else
			cout << "0 " << last_greater-1 << endl;
	}
	else
	{
		cout << "-1 -1" << endl;
	}
} 
