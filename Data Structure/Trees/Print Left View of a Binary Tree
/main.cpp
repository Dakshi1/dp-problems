#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	struct Node *left, *right;
};
struct Node *newNode(int data)
{
	struct Node *node=(struct Node*)malloc(sizeof(struct Node));
	node->data=data;
	node->left=node->right=NULL;
}
void leftViewUtil(struct Node *root, int level, int *maxlevel)
{
	if(root==NULL)
		return;
	if(*maxlevel<level)
	{
		cout << root->data << " ";
		*maxlevel=level;
	}
	// leftview gives the leftmost node on each level, to get right view simply interchange the last two recursive codes
	leftViewUtil(root->left, level+1, maxlevel);
	leftViewUtil(root->right, level+1, maxlevel);
	
}
void leftView(struct Node *root)
{
	int maxlevel=0;
	leftViewUtil(root, 1, &maxlevel);
}
int main()
{
	struct Node *root = newNode(4);
    root->left = newNode(5);
    root->right = newNode(2);
    root->right->left = newNode(3);
    root->right->right = newNode(1);
    root->right->left->left = newNode(6);
    root->right->left->right = newNode(7);
 
 	leftView(root);
} 
