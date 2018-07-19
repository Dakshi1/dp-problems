 
// You can do it bro
#include<iostream>
using namespace std;
int main()
 {
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    int n, m;
	    cin >> n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    {
	        cin >> arr[i];
	    }
	    cin >> m;
	    int helper[m+1][n];
	    
	    for(int i=0;i<=m;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            if(arr[j]>i)
	            {
	                if(j==0)
	                    helper[i][j]=0;
	                else
	                    helper[i][j]=helper[i][j-1];
	            }
	            else if((i-arr[j])==0)
	            {
	                if(j==0)
	                    helper[i][j]=1;
	                else
	                    helper[i][j]=1+helper[i][j-1];
	            }
	            else
	            {
	                if(j==0)
	                    helper[i][j]=helper[i-arr[j]][j];
	                else
	                    helper[i][j]=helper[i-arr[j]][j]+helper[i][j-1];
	            }
	            cout << helper[i][j] << " ";
	        }
	        cout << endl;
	    }
	    for(int i=0;i<=m;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            cout << helper[i][j] << " ";
	        }
	        cout << endl;
	    }
	}
	return 0;
}