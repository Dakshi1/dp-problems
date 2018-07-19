#include<bits/stdc++.h>
using namespace std;
int sqrt(int A) {
    
    if(A==0)
        return 0;
    int low=1, high=A, mid;
    int last_small=1;
    while(low<=high)
    {
        mid=low+(high-low)/2;
        //cout << mid << " ";
        if(mid*mid==A)
            return mid;
        else if(mid<=(A/mid))
        {
            low=mid+1;
            last_small=mid;
        }
        else
            high=mid-1;
    }
    
    return last_small;
}
int main()
{
	cout << "ans "<< sqrt(5) << endl;
	return 0;
}