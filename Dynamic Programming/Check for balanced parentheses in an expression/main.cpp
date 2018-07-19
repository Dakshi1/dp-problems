#include<bits/stdc++.h>
using namespace std;

int main()
{
	string exp;
	cin >> exp;
	stack<char> st;
	for(int i=0;i<exp.length();i++)
	{
		if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
			st.push(exp[i]);
		else if(st.empty() && (exp[i]=')' || exp[i]=='}' || exp[i]==']'))
		{
			cout << "Irregular expression " << endl;
			break;
		}
		else if((exp[i]=='}' && st.top()!='{') || (exp[i]==')' && st.top()!='(') || (exp[i]==']' && st.top()!='['))
		{
			cout << "Irregular expression " << endl;
			break;	
		}
		else
		{
			st.pop();
		}
	}
	if(!st.empty())
	{
		cout << "Irregular expression " << endl;
	}
	return 0;
} 
