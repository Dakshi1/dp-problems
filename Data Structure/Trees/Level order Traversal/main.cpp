#include<bits/stdc++.h>
using namespace std;

struct Node
{
	char data;
	struct Node *left, *right; 	
}; 

struct Node* create_Node(char data)
{
	struct Node *node=(struct Node*)malloc(sizeof(struct Node));
	node->data=data;
	node->left=node->right=NULL;
}
void level_order_traversal(struct Node *head)
{
	queue<struct Node *> q;
	if(head==NULL)
		return;
	struct Node *temp=head;
	q.push(temp);q.push(NULL);
	while(!q.empty())
	{
		temp=q.front();q.pop();
		if(temp==NULL)
		{
			cout << endl;
			if(!q.empty())
				q.push(NULL);
		}
		else
		{
			cout << temp->data << " ";
			if(temp->left!=NULL)
				q.push(temp->left);
			if(temp->right!=NULL)
				q.push(temp->right);
		}
		
		
	}
}
int main()
{
	struct Node *head=create_Node('A');
	head->left=create_Node('B');head->right=create_Node('C');
	head->left->left=create_Node('D');head->left->right=create_Node('E');head->right->right=create_Node('F');
	head->left->right->left=create_Node('G');head->right->right->left=create_Node('H');head->right->right->right=create_Node('I');
	head->right->right->right->left=create_Node('J');
	level_order_traversal(head);
}