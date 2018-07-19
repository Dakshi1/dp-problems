 
#include<bits/stdc++.h>
using namespace std;
void subseq(string input, string output, int i)
{
	if(input.length()==i)
	{
		cout << output << endl;
		return;
	}
	
	output+=input[i];
	subseq(input, output, i+1);
	
	subseq(input, output, i+1);
}
int main()
{
	string s="abc";
	string output="";
	subseq(s, output, 0);
	return 0;
} 
