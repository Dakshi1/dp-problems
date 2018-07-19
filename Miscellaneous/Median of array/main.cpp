#include<bits/stdc++.h>
using namespace std;
double find_median(std::vector<int> v, std::vector<int> w)
{
	/*std::vector<int> u;
	if(v.size()>w.size())
	{
		u=v;
		v=w;
		w=u;
	}*/
	int start=0, end=v.size();
    int v_length=v.size(), w_length=w.size();
    if(v_length==0 && w_length==0)
    {
        return 0;
    }
    if(v_length==0)
    {
        if(w_length%2!=0)
        {
            double d=w[w_length/2];
            return d;
        }
        else
        {
            double d=(w[w_length/2]+w[w_length/2 + 1])/2;
            return d;
        }
    }
    if(w_length==0)
    {
        if(v_length%2!=0)
        {
            double d=v[v_length/2];
            return d;
        }
        else
        {
            double d=(v[v_length/2]+v[v_length/2 + 1])/2;
            return d;
        }
    }
    int position_X, position_Y;
    int val_pos_x, val_pos_y;
    double ans;
    while(start<=end)
    {
        cout << start << " " << end << "  ";
        position_X=start+(end-start)/2;
        position_Y=(v_length+w_length+1)/2 - position_X;
        if(position_X==0)
        {
            val_pos_x=INT_MIN;
        }
        else
        {
            val_pos_x=v[position_X-1];
        }
        if(position_Y==0)
        {
            val_pos_y=INT_MIN;
        }
        else
        {
            val_pos_y=w[position_Y-1];
        }
        if(val_pos_x<=w[position_Y] && val_pos_y<=v[position_X])
            break;
        else if(v[position_X-1]>w[position_Y])
            end=position_X-1;
        else
            start=position_X+1;
        //break;
    }
    if((v_length+w_length)%2!=0)
    {
        ans=max(val_pos_x, val_pos_y)/(1.00);
    }
    else
    {
    	cout << val_pos_x << " " << val_pos_y << "  " << w[position_Y] << " " << v[position_X] << endl;
        ans=(max(val_pos_x, val_pos_y) + min(w[position_Y], v[position_X]))/(2.00);    
    }
    cout << position_X << " " << position_Y << endl;
    return ans;
}
int main()
{
	std::vector<int> v, w;
	v.push_back(-28);//v.push_back(26);v.push_back(31);v.push_back(35);//v.push_back(15);
	w.push_back(-49);w.push_back(6);w.push_back(7);w.push_back(14);w.push_back(34);w.push_back(40);w.push_back(41);

	cout << find_median(v,w) << endl;
} 
