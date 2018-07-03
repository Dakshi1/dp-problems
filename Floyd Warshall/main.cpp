#include <iostream>

using namespace std;
//int **graph;

void min_dis(int arr[][3], int n)
{
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==k || j==k)
                    continue;
                if((arr[i][k]+arr[k][j])<arr[i][j])
                    arr[i][j]=arr[i][k]+arr[k][j];
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout << arr[i][j] << "  ";
        }
        //cout << endl;
    }
}
int main()
{
    int v=3;
    //graph=new int* [v];
    //for(int i)
    int graph[][3]={{0, 1, 7},
                   {1, 0, 6},
                   {7, 6, 0} };
    min_dis(graph, v);
    return 0;
}
