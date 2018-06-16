// You can do it bro

#include<bits/stdc++.h>
using namespace std;
int lcs(string s1, string s2, int n1, int n2)
{
    int i, j, l[n1+1][n2+1];
    cout << "je";
    for(i=0; i<=n1; i++)
    {
        for(j=0; j<=n2; j++)
        {
            if(i==0 || j==0)
                l[i][j]=0;
            if(s1.at(i-1)==s2.at(j-1))
                l[i][j]=1+l[i-1][j-1];
            else
                l[i][j]=1+max(l[i-1][j], l[i][j-1]);
        }
    }
    return l[n1][n2];
}
int main()
 {
	//code
	int t;
	cin >> t;
	while(t>0)
	{
	    int n1, n2;
	    cin >> n1 >> n2;
	    string s1, s2;
	    cin >> s1 >> s2;
	    cout << lcs(s1, s2, n1, n2) << endl;
	    t--;
	}
	return 0;
}
