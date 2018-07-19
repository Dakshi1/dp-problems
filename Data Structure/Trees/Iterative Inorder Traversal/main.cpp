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
void in_order_traversal(struct Node *head)
{
	stack<Node*> st;
	Node* temp=head;
	while(temp!=NULL || !st.empty())
	{
		while(temp!=NULL)
		{
			st.push(temp);
			temp=temp->left;
		}
		temp=st.top();
		st.pop();
		cout << temp->data << " ";
		temp=temp->right;
	}
}
int main()
{
	struct Node *head=create_Node('A');
	head->left=create_Node('B');head->right=create_Node('C');
	head->left->left=create_Node('D');head->left->right=create_Node('E');head->right->right=create_Node('F');
	head->left->right->left=create_Node('G');head->right->right->left=create_Node('H');head->right->right->right=create_Node('I');
	head->right->right->right->left=create_Node('J');
	in_order_traversal(head);
} 
 
