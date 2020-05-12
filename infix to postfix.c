#include<stdio.h>
#include<string.h>
#include<math.h>
#define max 100
struct stack{
	char info[max];
	int top;
};
typedef struct stack STK;
int is_operand(char );
void push(STK *,char );
char pop(STK *);
void evaluate(char *);
int is_operator(char );
int priority(char);
void main()
{
	int i;
	char infix[max];
	STK stk;
	printf("\nEnter infix expression:");
	scanf("%s",infix);
	i=strlen(infix);
	infix[i]=')';
	infix[++i]='\0';
	stk.top=-1;
	if(stk.top=-1)
		push(&stk,'(');	
	printf("\nResult is:");	
	evaluate(infix);
}
void push(STK *p,char item)
{
	if(p->top==max-1)
		{
			printf("\nStack overflow");
			return;
		}
	p->info[++p->top]=item;	
}
char pop(STK *p)
{
	if(p->top==-1)
		{
			printf("\nStack underflow");
			return(0);
		}
	return(p->info[p->top--]);	
}
void evaluate(char *a)
{
	int i=0;
	char m;
	STK stk;
	stk.top=-1;
	push(&stk,'(');
	while(a[i]!='\0')
	{
		if(is_operand(a[i]))
			printf("%c",a[i]);
		if(a[i]=='(')
			push(&stk,a[i]);
		if(is_operator(a[i]))
			{
			beg:m=pop(&stk);
				if((priority(m)>=priority(a[i]))&&(is_operator(m)!=0))
				  {printf("%c",m);
				   goto beg;}
				else
					push(&stk,m);
			push(&stk,a[i]);		
		    }
		if(a[i]==')')
		 {
		 	beg2:
		 	m=pop(&stk);
		 	if(m=='(')
		 	{
		 	//	printf("%c",m);
		 		exit(0);
			 }
		 	if(is_operator(m))
		 		{printf("%c",m);
		 		 goto beg2;}
		 	else
			 	push(&stk,m);	 
		 }
		i++; 
	 }
	/* int i=0;
	 char x;
	 STK stk;
	 while(a[i]!='\0')
	 {
	 	if(is_operand(a[i]))
	 		printf("%c",a[i]);
	 	else
		 	if(a[i]=='(')
		 	   push(&stk,a[i]);
		 	else
		 		if(a[i]==')')
				 	while((x=pop(&stk))!='(')
					  	printf("%c",x);
				else{
					while(priority(stk.top)>=priority(a[i]))
						printf("%c",pop(&stk));
					push(&stk,a[i]);	
				}
		i++;			  	
	 }
	 while(stk.top!=-1)
	 	printf("%c",pop(&stk));*/
	}		
int is_operand(char c)
{
	return((c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>=0&&c<=9));
}
int is_operator(char c)
{
	if(c=='+'||c=='-'||c=='*'||c=='/'||c=='$')
		return(1);
	return(0);	
}
int priority(char c)
{
	if(c=='+'||c=='-')
		return(1);
	if(c=='(')
		return 0;
	if(c=='*'||c=='/')
		return 2;
	if(c=='$')
		return 3;			
}
