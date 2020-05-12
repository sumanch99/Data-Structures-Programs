#include<stdio.h>
#define max 10
struct stack{
	int info[max];
	int left;
	int right;
};
typedef struct stack stk;
void left_push(stk *,int);
void left_pop(stk *);
void right_push(stk *,int);
void right_pop(stk *);
void main()
{
	stk a;
	int i,x,y;
	a.left=-1;
	a.right=max;
	do{
		printf("\n1:push on to left stack.");
		printf("\n2:push on to right stack.");
		printf("\n3:pop from left stack.");
		printf("\n4:pop from right stack.");
		printf("\n0:To exit.");
		printf("\n\nYour choice:");
		scanf("%d",&i);
		switch(i){
			case 1: printf("\nEnter an element");
					scanf("%d",&x);
					left_push(&a,x);
					break;
			case 2: printf("\nEnter an element");
					scanf("%d",&y);
					right_push(&a,y);
					break;					
			case 3: left_pop(&a);		
					break;
			case 4: right_pop(&a);
					break;		
			case 0: printf("\nThe End.\n");
					break;
			default:printf("\nInvalid choice.\n");
					break;			
		}
	}while(i);
}
void left_push(stk *p,int item)
{
	if((p->left)+1==(p->right))
	{
		printf("\nStack overflow\n");
		return;
	}
	p->info[++p->left]=item;
}
void right_push(stk *p,int item)
{
	if((p->left)+1==(p->right))
	{
		printf("\nStack overflow\n");
		return;
	}
	p->info[--p->right]=item;
}
void left_pop(stk *p)
{
	if(p->left==-1)
	{
		printf("\nStack underflow.\n");
		return;
	}
	printf("\nPopped Element:%d",p->info[p->left--]);
}
void right_pop(stk *p)
{
	if(p->right==max)
	{
		printf("\nStack underflow.\n");
		return;
	}
	printf("\nPopped Element:%d",p->info[p->right++]);
}
