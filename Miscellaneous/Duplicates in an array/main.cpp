#include<bits/stdc++.h>
using namespace std;
int repeatedNumber(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n=A.size();
    //int n=A.size();
    int result,temp;
    for (int i = 0; i < n; i++)
    {
        if (A[abs(A[i])] >= 0)
        {
            temp=-1 * A[abs(A[i])];
            A[abs(A[i])] = temp;
        }
            
        else
        {
            result=abs(A[i]);
            break;
        }
    
	}
	return result;
}

int main()
{
	vector<int> v={3,4,1,4,1};
	cout << repeatedNumber(v);
}
