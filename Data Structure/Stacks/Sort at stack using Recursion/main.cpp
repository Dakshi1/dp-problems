#include<bits/stdc++.h>
using namespace std;
void insertInOrder(stack<char> *st, char element)
{
	
	if(st->empty())
	{
		st->push(element);
		return;
	}
	char val=st->top();
	if(element>val)
	{
		st->pop();
		insertInOrder(st, element);
		st->push(val);	
	}
	else
	{
		st->push(element);
	}
	
}
void fun(stack<char> *st)
{
	if(st->empty())
		return;
	char element=st->top();
	st->pop();
	fun(st);
	insertInOrder(st, element);
	//cout << element << endl;

}
int main()
{
	stack<char> st;
	st.push('d');st.push('a');st.push('k');st.push('s');st.push('h');st.push('i');
	fun(&st);

	while(!st.empty())
	{
		cout << st.top() << " " ;
		st.pop();
	}
} 
 
