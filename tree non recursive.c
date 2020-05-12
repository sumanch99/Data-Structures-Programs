#include<stdio.h>
#include<stdlib.h>
struct binary_tree{
	struct binary_tree *left;
	struct binary_tree *right;
	int key;
};
typedef struct binary_tree bt;
struct stack{
	bt *info[100];
	int top;
};
typedef struct stack STK;
bt *insert(bt *,int);
void push(STK *,bt *);
bt* pop(STK *);
void display_preorder(bt *);
void display_inorder(bt *);
void display_postorder(bt *);
void main()
{
	int i,x;
	bt *tree;
	tree=NULL;
	do{
		printf("\n1:Insert onto binary tree");
		printf("\n2:Display pre order travers of the binary tree");
		printf("\n3:Display in order travers of the binary tree");
		printf("\n4:Display post order travers of the binary tree");
		printf("\n0:To exit");
		printf("\n\nEnter your choice:");
		scanf("%d",&i);
		switch(i){
			case 1: printf("\nEnter key value:");
					scanf("%d",&x);
					tree=insert(tree,x);
					break;
			case 2: display_preorder(tree);
					break;
			case 3: display_inorder(tree);
					break;
			case 4: display_postorder(tree);
					break;
			case 0: printf("\nThe End");
					break;
			default:printf("\nInvalid choice");										
		}
	}while(i);
}
bt *insert(bt *ptr,int item)
{
	bt *temp;
	if(ptr==NULL)
	{
		temp=(bt*)malloc(sizeof(bt));
		temp->key=item;
		temp->left=NULL;
		temp->right=NULL;
		ptr=temp;
		return ptr;
	}
	if(item>ptr->key)
			ptr->right=insert(ptr->right,item);
	else
			ptr->left=insert(ptr->left,item);	
	return ptr;				
}
void display_preorder(bt *ptr)
{
	if(ptr==NULL)
		return;
	printf("%d ",ptr->key);
	display_preorder(ptr->left);
	display_preorder(ptr->right);
}
void display_inorder(bt *ptr)
{
	if(ptr==NULL)
		return;
	display_inorder(ptr->left);
	printf("%d ",ptr->key);
	display_inorder(ptr->right);
}
void display_postorder(bt *p)
{
	bt *curr;
	STK stk1,stk2;
	stk1.top=stk2.top=-1;
	push(&stk1,p);
	while(stk1.top!=-1)
	{
		curr=pop(&stk1);
		push(&stk2,curr);
		if(curr->left!=NULL)
			push(&stk1,curr->left);
		if(curr->right!=NULL)
			push(&stk1,curr->right);
	}
	while((p=pop(&stk2))!=NULL)
		printf(" %d",p->key);
}
void push(STK *p,bt *item)
{
	p->info[++p->top]=item;
}
bt *pop(STK *p)
{
	if(p->top==-1)
		return(NULL);
		
	return(p->info[p->top--]);	
}
