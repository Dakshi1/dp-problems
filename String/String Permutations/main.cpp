#include<bits/stdc++.h>
using namespace std;
int xcount=0;
void swap(char *a, char *b)
{
	char *temp=a;
	a=b;
	b=a;
}
void str_per(string s, int start, int end)
{
	if(start==end)
	{
		cout << s << endl;
		xcount++;
	}
	else
	{
		for(int j=start;j<=end;j++)
		{
			swap(s[j], s[start]);
			str_per(s, start+1, end);
			swap(s[j], s[start]);
		}
	}
}
int main()
{
	string s="AABC";
	str_per(s, 0, 3);
	 cout << xcount << endl;
	return 0;
} 
