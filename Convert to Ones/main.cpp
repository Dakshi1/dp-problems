#include <iostream>
#define ll long long
using namespace std;
ll min_cost(string arr, ll n, ll cost_reverse, ll cost_inversion)
{
    ll zero_grp=0;
    for(ll i=0;i<n;i++)
    {
        if(arr[i]=='0')
        {
            zero_grp++;
            while(i<n && arr[i]=='0')
            {
                i++;
            }
        }
    }
    if(zero_grp==0)
        return 0;

    return min((zero_grp-1)*cost_reverse+cost_inversion, zero_grp*cost_inversion);
}
int main()
{
    ll n, cost_reverse, cost_inversion;
    cin >> n >> cost_reverse >> cost_inversion;
    string arr;

    cin >> arr;
    cout << min_cost(arr, n, cost_reverse, cost_inversion);
    return 0;
}
