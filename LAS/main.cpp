 #include<bits/stdc++.h>
using namespace std;
int solve(const vector<int> &A) {
    
    int n=A.size();
    int helper[n][n];
    int helper_dif[n][n];
    for(int i=0;i<n;i++)
    {
        helper[i][i]=1;
        helper[i][i+1]=2;
        helper_dif[i][i+1]=A[i+1]-A[i];
    }
    for(int k=0;k<n;k++)
    {
        for(int i=k+2;i<n;i++)
        {
            helper[k][i]=0;
            for(int j=i-1;j>k;j--)
            {
            	//cout << "k= " << k << " j= " << j <<"  main is " <<helper[k][j] << endl;
                if(helper_dif[k][j]==(A[i]-A[j]) && (1+helper[k][j])>helper[k][i])
                {
                    helper[k][i]=1+helper[k][j];
                    helper_dif[k][i]=helper_dif[k][j];
                    //cout << "k= " << k << " j= " << j <<"  diff is " <<helper_dif[k][i] << endl;
                }
            }  
            if(helper[k][i]==0)
            {
                helper[k][i]=2;
                helper_dif[k][i]=A[i]-A[k];
            }
        }
    }
    int max=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            cout << helper_dif[i][j] << " ";
            if(helper[i][j]>max)
                max=helper[i][j];
        }
        cout << endl;
    }
    return max;
}

int main(int argc, char const *argv[])
 {
 	std::vector<int> v(8);
 	v[0]=10;
 	v[1]=2;
 	v[2]=1;
 	v[3]=4;
 	v[4]=5;
 	v[5]=6;
 	v[6]=8;
 	v[7]=10;
 	cout << solve(v);
 	return 0;
 } 
