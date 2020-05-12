#include<stdio.h>
#include<conio.h>
#define max 5
#define TRUE 1
#define FALSE 0
struct cqueue{
	int info[max];
	int front,rear;
	int flag;
};
typedef struct cqueue cq;
void insert(cq *,int);
void del_ete(cq *);
void display(cq);
void rev_disp(cq);
void main(void)
{
	cq a;
	int i,x;
	a.front=a.rear=0;
	a.flag=FALSE;
	do{printf("\n1:Insert into circular queue.");
	   printf("\n2:Delete from circular queue.");
	   printf("\n3:Display circular queue.");
	   printf("\n4:Display the circular queue reversely.");
	   printf("\n\nEnter your choice:");
	   scanf("%d",&i);
	   switch(i)
	   {case 1:printf("\nEnter an element to insert:");
	    	   scanf("%d",&x);
	    	   insert(&a,x);
	    	   break;
	    case 2:del_ete(&a);
			   break;
	    case 3:display(a);
			   break;
		case 4:rev_disp(a);
			   break;
		case 0:printf("\nThe end.\n");
			   break;
		default:printf("\nInvalid choice.\n\n");			   	   	   		   
	   }}while(i);
}
void insert(cq *p,int item)
{
	if(p->front==p->rear&&p->flag==TRUE)
	{
		printf("\n\nCircular queue overflow.\n\n");
		return;
	}
	p->info[p->rear]=item;
	p->rear=(p->rear+1)%max;
	p->flag=TRUE;
}
void del_ete(cq *p)
{
	if(p->front==p->rear&&p->flag==FALSE)
	{
		printf("\n\nCircular queue underflow\n\n");
		return;
	}
	printf("\nDeleted element: %d",p->info[p->front]);
	p->front=(p->front+1)%max;
	p->flag=FALSE;
}
void display(cq a)
{
	printf("\nCircular queue:");
	if(a.front==a.rear&&a.flag==TRUE)
		printf("%d ",a.info[a.front++]);
	while(a.front!=a.rear)
	  {
		printf("%d ",a.info[a.front]);
	    a.front=(a.front+1)%max;
	  }
}
void rev_disp(cq a)
{
	printf("\nReveresed Circular queue:");
	if(a.rear<=a.front)
	{
		a.rear--;
		while(a.rear>=0)
			printf("%d ",a.info[a.rear--]);
		a.rear=max;	
	}
	while(a.front!=a.rear)
	{
		a.rear=(a.rear-1)%max;		
		printf("%d ",a.info[a.rear]);

	}	
}

