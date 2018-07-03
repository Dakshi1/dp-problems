#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> A;
    A.push_back(52);
    A.push_back(319);
    A.push_back(695);
    vector<int>::iterator it, t;
    t=A.begin();
    int temp=A[0];
    while(t!=A.end() && find(t, A.end(), temp)!=A.end())
    {
        it=find(t, A.end(), temp);
        cout << temp <<" ";
        t=it+1;
    }
    return 0;
}
