#include <iostream>

using namespace std;
int cut_rod(int n, int length[], int price[])
{
    int table[n+1][n+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0 || j==0)
                table[i][j]=0;
            else if(i-length[j-1]<0)
                table[i][j]=table[i][j-1];
            else
                table[i][j]=max(price[j-1]+table[i-length[j-1]][j], table[i][j-1]);
            cout << "table[ " << i << " ][ " << j << " ] = " << table[i][j] << endl;
        }
    }
    return table[n][n];
}
int main()
{
    int n=8;
    int length[]={1, 2, 3, 4, 5, 6, 7, 8};
    int price[]={1, 5, 8, 9, 10, 17, 17, 20};
    cout << cut_rod(n, length, price);
    return 0;
}
