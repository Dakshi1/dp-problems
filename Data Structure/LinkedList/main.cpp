#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int val;
	struct Node *next;
};
void insertNode(int val, Node *head)
{
	Node *temp=(Node *)malloc(sizeof(Node));
	temp->val=val;
	temp->next=(head);
	(head)=temp;
}
void fun(int **a, int **b)
{
	
	(*a)=(*b);
	cout << (a) << " " << b << endl;
}
int main()
{
	int *a, *b;
	//(*a)=5;
	cout << (a) << " " << b << endl;
	fun(&a, &b);
	cout << (a) << " " << b << endl;
	/*Node *head=(Node *)malloc(sizeof(Node));
	head->val=1;
	head->next=(Node *)malloc(sizeof(Node));
	head->next->val=2;
	head->next->next=(Node *)malloc(sizeof(Node));
	head->next->next->val=3;
	insertNode(5, head);
	while(head!=NULL)
	{
		cout << head->val << endl;
		head=head->next;
	}*/
	return 0;
}

