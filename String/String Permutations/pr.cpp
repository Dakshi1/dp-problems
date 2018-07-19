// You can do it bro
#include<bits/stdc++.h>
using namespace std;

bool found_dup=true;
string remove_duplicates(string s)
{

    int n=s.length();
    if(n<2)
        return s;
    int i=0, j=1, f=1;
    while(i< n -1)
    {
        cout << s << endl;
        j=i+1;
        while(j<n && s[i]==s[j])
        {
            j++;
        }
        if(i!=(j-1))
        {
            if(j>=n)
                s=s.substr(0, i);
            else
                s=s.substr(0, i) + s.substr(j, n);
            f=0;
            n=s.length();
            j=i+1;
            if(n<2)
                return s;
            continue;
        }
        i++;
    }
    if(f)
        return s;
    remove_duplicates(s);
}
int main()
 {
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    string s;
	    cin >> s;
	    found_dup=true;
	    s=remove_duplicates(s);
	    
	    cout << s << endl;
	}
	return 0;
}
/*int n=s.length();
    if(n==0 || !found_dup)
    {
        return;
    }
    found_dup=false;
    for(int i=0;i<n;i++)
    {
        int j=i;
        while(i<n-1 && s[i]==s[i+1])
            i++;
        if(i!=j)
        {
            found_dup=true;
            if(i==n-1)
            {
                s=s.substr(0, j);
            }
            else
            {
                s=s.substr(0, j)+s.substr(i+1, n);
            }
            //break;
            i=j-1;
            n=s.length();
        }
            
    }
    remove_duplicates();*/