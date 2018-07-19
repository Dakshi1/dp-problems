// You can do it bro
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int edit_distance(string str1, string str2, int n1, int n2)
{
    int ED[n1+1][n2+1];
    for(int i=0;i<=n1;i++)
    {
        for(int j=0;j<=n2;j++)
        {
            if(i==0)
                ED[i][j]=j;
            else if(j==0)
                ED[i][j]=j;
            else if(str1[i-1]==str2[j-1])
                ED[i][j]=ED[i-1][j-1];
            else
                ED[i][j]=1+ min(ED[i][j-1], ED[i-1][j], ED[i-1][j-1]);
        }
    }
    return ED[n1][n2];
}
int main()
 {
	//code
	int t;
	cin >> t;
	while(t>0)
	{
	    int n1, n2, result;
	    string str1, str2;
	    cin >> n1 >> n2;
	    cin >> str1 >> str2;
	    result=edit_distance(str1, str2, n1, n2);
	    cout << result << endl;
	    t--;
	}
	return 0;
}
