#include <bits/stdc++.h>

using namespace std;

int find_cuts(int arr[], int n, int b)
{
    vector<int> v;
    int odd_count=0, even_count=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]%2==0)
            even_count++;
        else
            odd_count++;
        if(even_count==odd_count && i<n-1)
        {
            //cout <<  abs(arr[i+1]-arr[i]) << " " ;
            v.push_back(abs(arr[i+1]-arr[i]));
            //cout << v[0] << endl;
            odd_count=0;even_count=0;
        }
    }
    if(v.size()==0)
        return 0;

    sort(v.begin(), v.begin()+v.size());

    int result=0;
    int i=0;
    while(i<v.size() && (b-v[i])>=0)
    {
        result++;
        b=b-v[i];
        i++;
        //cout << "b= " << b << " " << v[i]  << endl;
    }
    return result;
}
int main()
{
    int n, b;
    cin >> n >> b;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    cout << find_cuts(arr, n, b);
    return 0;
}
