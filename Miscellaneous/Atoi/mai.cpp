#include<bits/stdc++.h>
using namespace std;
int _bbbatoi(const string A) {
    
    int n=A.length();
    long long int temp=0;
    int ans=0;
    int st, end;
    bool isNegative=false;
    int i=0;
    while(i<n && A[i]==32)
        {
            i++;
        }
        if(A[i]==43 || A[i]==45)
            i++;
        if(i<n && A[i]>=48 && A[i]<=57)
        {
        	//cout << "hello " << endl;
            if(i>0 && A[i-1]==45)
                isNegative=true;
            while(i< n && A[i]>=48 && A[i]<=57)
            {
            	//cout << "happy " << endl;
                int val=A[i]-'0';
                //cout << "val= " << val << endl;
                temp=temp*10 + val;
                ans=ans*10 + val;
                i++;
                //cout << temp << " hello";
                if(temp>=INT_MAX && isNegative)
                {
                	
                    return INT_MIN;
                }
                else if(temp>=INT_MAX)
                    return INT_MAX;
            }
        }
        else 
        {
            return 0; 
        }
        
    
    if(isNegative)
        ans=ans*(-1);
    return ans;
}



int main() 
{
	cout << _bbbatoi("7 U 0 T7165 0128862 089 39 5") << endl;
}
