// You can do it bro
#include<bits/stdc++.h>
using namespace std;
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    string input, output="";
	    cin >> input;
	    int n=input.length();
	    string word="";
	    for(int i=0;i<n;i++)
	    {
	        if(input[i]=='.')
	        {
	            word.insert(0,1,input[i]);
	            cout << word << endl;
	            output.insert(0, word);
	            word="";
	        }
	        else
	        {
	        	word.insert(word.length(),1,input[i]);
	        	if(i==n-1)
	        		output.insert(0, word);
	        }
	    }
	    cout << output << endl;
	}
	return 0;
} 
