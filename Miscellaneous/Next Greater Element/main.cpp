#include<bits/stdc++.h>
using namespace std;

int main()
{
	int arr[]={1,3,2,4 };
	int helper[4];
	stack<int> st;
	st.push(0);
	for(int i=1;i<4;i++)
	{
		while(!st.empty() && arr[i]>arr[st.top()])
		{
			int el=st.top();st.pop();
			helper[el]=arr[i];
		}
		st.push(i);
	}
	while(!st.empty())
	{
		helper[st.top()]=-1;
		st.pop();
	}
	for(int i=0;i<4;i++)
	{
		cout << helper[i] << endl;
	}
} 
