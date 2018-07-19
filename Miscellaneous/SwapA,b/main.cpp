// You can do it bro
#include<iostream>
using namespace std;
void swaps(int *a, int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void shuffle_int(int arr[], int n, int st, int en)
{
    if(st > en)
        return;
    //cout << st << " " << en << endl;
    int mid=(st+en)/2;
    for(int i=st;i<=mid;i++)
    {
    	//cout << "hello " << arr[i] << " " << arr[mid + 1 + i - st] << endl;
        swaps(&arr[i], &arr[mid+1 + i - st]);
    }
    shuffle_int(arr, n, st+1, en-1);
}
int main()
 {
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    int n, m;
	    cin >> n;
	    m=n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	        cin >> arr[i];
	    if(n%2)
	    	m--;
	    shuffle_int(arr, n, 1, m-2);
	    for(int i=0;i<n;i++)
	        cout << arr[i] << " ";
	    cout << endl;
	}
	return 0;
}