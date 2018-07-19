#include<bits/stdc++.h>
using namespace std;

int calc_area()
{
	int arr[][15]={
  {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
  {1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  {0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},
  {1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
  {1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0},
  {1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1},
  {1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1},
  {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1}
};
	int m=15;
    int n=15;
    
    int max_area=0;
    
    int helper[m][n][6];
    
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            max_area=max(arr[i][j], max_area);
            if(arr[i][j]==0)
            {
                for(int k=0;k<6;k++)
                {
                    helper[i][j][k]=0;
                }
            }
            else
            {
                
                for(int k=0;k<6;k++)
                {
                    helper[i][j][k]=1;
                }
                if(j>0 && arr[i][j-1]!=0)
                {
                    helper[i][j][1]=helper[i][j-1][1]+1;
                    max_area=max(max_area, helper[i][j][0]*helper[i][j][1]);
                    cout << "i = " << i << " j = " << j << " left max_area " << max_area << " area " << (helper[i][j][0]*helper[i][j][1]) << endl;
                }
                if(i>0 && arr[i-1][j]!=0)
                {
                    helper[i][j][2]=helper[i-1][j][2]+1;
                    max_area=max(max_area, helper[i][j][2]*helper[i][j][3]);
                    cout << "i = " << i << " j = " << j << " top max_area " << max_area << " area " << (helper[i][j][2]*helper[i][j][3]) << endl;
                    
                }
                if(j>0 && arr[i][j-1]!=0 && i>0 && arr[i-1][j]!=0 && arr[i-1][j-1]!=0)
                { 
                	int xmin=min(min(helper[i-1][j-1][4], helper[i-1][j][4]), helper[i-1][j][4]);
                	//int xxmin=min(min(helper[i-1][j-1][5], helper[i-1][j][5]), helper[i-1][j][5]);
                    helper[i][j][4]=xmin+1;
                    helper[i][j][5]=xmin+1;
                    max_area=max(max_area, helper[i][j][4]*helper[i][j][5]);
                  
                    cout << "i = " << i << " j = " << j << " diagonal max_area " << max_area << " area " << (helper[i][j][4]*helper[i][j][5]) << endl;
                }
            }
        }
    }
	return max_area;
}
int main()
{
	

	cout << calc_area() << endl;

	return 0;
	
} 
