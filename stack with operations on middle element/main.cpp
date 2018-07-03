#include<bits/stdc++.h>

struct DLLNode
{
	DLLNode *next;
	DLLNode *previous;
	int data;
};
struct Xstack
{
	struct DLLNode *head;
	struct DLLNode *mid;
	int count; 	
};
struct Xstack *createStack()
{
	struct Xstack *st=(struct Xstack*) malloc(sizeof(struct Xstack));
	st->count=0;
	return st;
} 
void push(struct Xstack *stack, int value)
{
	struct DLLNode *node=(struct DLLNode*) malloc(sizeof(struct DLLNode));
	node->data=value;
	node->previous=NULL;
	node->next=stack->head;
	stack->count++;
	if(stack->count==1)
	{
		stack->mid=node;
	}
	else
	{
		stack->head->previous=node;
		if(stack->count & 1)
		{
			stack->mid=stack->mid->previous;
		}
	}
	stack->head=node;
}
int pop(struct Xstack *stack)
{
	if(stack->count!=0)
	{
		struct DLLNode *node=stack->head;
		int data=node->data;
		stack->head=node->next;
		if (stack->head!=NULL)
		{
			stack->head->previous=NULL;
		}
		stack->count--;
		if(stack->count%2==0)
		{
			stack->mid=stack->mid->next;
		}
		free(node);
		return data;
	}
	return -1;
}
int findMid(struct Xstack *stack)
{
	if(stack->count!=0)
	{
		return stack->mid->data;
	}
	return -1;
}

int main()
{
    /* Let us create a stack using push() operation*/
    struct Xstack *ms = createStack();
    push(ms, 11);
    push(ms, 22);
    push(ms, 33);
    push(ms, 44);
    push(ms, 55);
    push(ms, 66);
    push(ms, 77);
 
    printf("Item popped is %d\n", pop(ms));
    printf("Item popped is %d\n", pop(ms));
    printf("Middle Element is %d\n", findMid(ms));
    return 0;
}