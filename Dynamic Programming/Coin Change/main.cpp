#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> helper(11);
void countx(int S[], int n)
{

}
int main()
{
    int S[]={2, 5, 3, 6};
    int n=10;
    int m=4;
    for(int i=0;i<=n;i++)
    {
        //helper[i]=new vector<int>;
        for(int j=0;j<=m;j++)
        {
            helper[i].push_back(-1);
        }
    }
    countx(S, n);

    return 0;
}
