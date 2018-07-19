#include <iostream>
#include <string>
using namespace std;

int main()
{
    int Vj[]={1, 3, 5, 7};
    int s=21;
    int n=4;
    int minx[22];
    minx[0]=0;

    for(int i=1;i<=s;i++)
    {
        minx[i]=999999;
    }

    for(int i=1;i<=s;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(Vj[j]<=i && (minx[i-Vj[j]] + 1) < minx[i])
                minx[i]=minx[i-Vj[j]] + 1;
        }
    }

    for(int i=0;i<=s;i++)
    {
        //cout << minx[i] << endl;
        cout << "minimum number of coins required for sum " + to_string(i) + " " + to_string(minx[i]) << endl;
    }

    return 0;
}
