#include<bits/stdc++.h>
using namespace std;
void subseq(string input, char output[], int i, int j)
{
	if(input.length()==i)
	{
		output[j]='\0';
		cout << output << endl;
		return;
	}
	
	output[j]=input[i];
	subseq(input, output, i+1, j+1);
	
	subseq(input, output, i+1, j);
}
int main()
{
	string s="abc";
	char output[100];
	subseq(s, output, 0, 0);
	return 0;
} 
