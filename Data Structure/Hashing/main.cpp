#include<bits/stdc++.h>
using namespace std;
#define MAX_SIZE INT_MAX
int hashCode(string str) 
{
    int hash = 0;
    for (int i = 0; i < str.length(); i++) 
    {
        hash = hash * 31 + str[i];
    }
    return hash % MAX_SIZE;
}
int main()
{
	string str="Dakshi";
	cout << hashCode(str) << endl;
} 
