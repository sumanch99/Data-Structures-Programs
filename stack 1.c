#include<stdio.h>
#define max 10
struct stack{
	int info[max];
	int top;
};
typedef struct stack stk;
void push(stk *,int);
void pop(stk *);
void display(stk *);
void reverse(stk *);
void main()
{
	stk a;
	int i,x;
	a.top=-1;
	do{
		printf("\n1:Push on to stack");
		printf("\n2.Pop from stack");
		printf("\n3.Display the stack");
		printf("\n4.Display the stack reversely");
		printf("\n0.to exit");
		printf("\n\nYour choice:");
		scanf("%d",&i);
		switch(i){
			case 1: printf("\nEnter an element:");
					scanf("%d",&x);
					push(&a,x);
					break;
			case 2: pop(&a);
					break;
			case 3: display(&a);
					break;
			case 4: reverse(&a);
					break;
			case 0: printf("\nThe End.");
					break;
			default: printf("\nInvalid choice");
	             }
	 }while(i);
}
void push(stk *p,int item)
{
	if(p->top==max-1)
		{
			printf("\nStack overflow\n");
			return;
		}
	p->info[++p->top]=item;	
}
void pop(stk *p)
{
	if(p->top==-1)
	{
		printf("\nStack underflow\n");
		return;
	}
	printf("\nPopped element is: %d",p->info[p->top--]);
}
void display(stk *p)
{
	int k=p->top;
	if(p->top==-1)
	{
		printf("\nStack underflow");
		return;
	}
	while(k>-1)
	{printf("%d ",p->info[k--]);
		}	
}
void reverse(stk *p)
{
	int i=0;
	if(p->top==-1)
	{
		printf("\nStack underflow");
		return;
	}
	while(i<=p->top)
	{
		printf("%d ",p->info[i++]);
	}
	
}
