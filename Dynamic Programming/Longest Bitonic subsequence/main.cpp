#include <iostream>

using namespace std;
int biot_seq(int arr[], int n)
{
    int helper_inc[n], helper_dec[n];
    for(int i=0;i<n;i++)
    {
        helper_inc[i]=1;
        helper_dec[i]=1;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j] && helper_inc[j]+1>helper_inc[i])
                helper_inc[i]=1+helper_inc[j];
        }
    }
    for(int i=n-2;i>=0;i--)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[i] && helper_dec[j]+1>helper_dec[i])
                helper_dec[i]=helper_dec[j]+1;
        }
    }
    int maxx=0;
    for(int i=0;i<n;i++)
    {
        if((helper_inc[i]+helper_dec[i]-1)>maxx)// '-1' to remove duplicacy of i th element
            maxx=helper_dec[i]+helper_inc[i]-1;
    }
    return maxx;
}
int main()
{
    int n=8;
    int arr[n]={1, 11, 2, 10, 4, 5, 2, 1};
    cout << biot_seq(arr, n) << endl;
    return 0;
}
