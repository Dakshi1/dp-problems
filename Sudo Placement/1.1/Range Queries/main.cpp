#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll find_combinations(int rem_pos, int r)
{
	ll temp=1;
    for(int m=r;m>=1;m--)
    {
        if(rem_pos<m)
        {
            temp=0;
            break;
        }
        temp*=(rem_pos-r+m);
        temp/=(r-m+1);
    }
    return temp;
}
void calculate_output(ll *ans, vector<int> &arr)
{
    int j=0, rem_pos=0;
    if(arr.size()==0)
    	return;
    // will run at max 3 times as at max 3 bits have to be set
    for(int i=0;i<3 && j<arr.size();i++)
    {
        while(j < arr.size() && arr[j]==0)
            j++;
        j++;
       rem_pos=arr.size()-j;
       // (i) bits have been set, so we have to set (3-i) bits  
       for(int k=3-i;k>=0 && rem_pos>=0;k--)
       {
           *ans+=find_combinations(rem_pos, k);
       }
    }
    // to include the case of 0s at the remaining positions after setting the maximum possible bits
    *ans+=1;
}
void find_bit_arr(ll l, ll r, vector<int> &l_arr, vector<int> &r_arr)
{
    while(l>0)
    {
        l_arr.push_back(l & 1);
        l= l >> 1;
    }
    while(r>0)
    {
        r_arr.push_back(r & 1);
        r= r >> 1;
    }
    reverse(l_arr.begin(), l_arr.end());
    reverse(r_arr.begin(), r_arr.end());
}
int main()
 {
 	// vectors to store bit representations of l and r
	vector<int> l_arr, r_arr;
	// count of possible numbers of 3 bits  
    ll l_ans=0, r_ans=0;
	ll l, r;
	cin >> l >> r;
	if(l>r)
	{
	    ll temp=l;
	    l=r;
	    r=temp;
	}
	// function to get bitwise representation
	find_bit_arr(l-1,r, l_arr, r_arr);

	//find count for l-1 and r
	calculate_output(&l_ans, l_arr);
	calculate_output(&r_ans, r_arr);
	        
	cout << (r_ans - l_ans) << endl;
	   
	return 0;
}