#include <iostream>

using namespace std;
int max_sum(int arr[], int n)
{
    int helper[n];
    for(int i=0;i<n;i++)
    {
        helper[i]=arr[i];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[j]<arr[i] && (helper[j]+arr[i])>helper[i])
            {
                helper[i]=arr[i]+helper[j];
            }
        }
    }
    int maxx=helper[0];
    for(int i=1;i<n;i++)
    {
        if(helper[i]>maxx)
            maxx=helper[i];
    }
    return maxx;
}
int main()
{
    int n=7;
    int arr[]={1, 101, 2, 3, 100, 4, 5};
    cout << max_sum(arr, n);
    return 0;
}
