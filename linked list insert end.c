#include<stdio.h>
#include<malloc.h>
#include<string.h>
struct record{
	int id;
	char name[20];
};
typedef struct record rd;
struct node{
	rd info;
	struct node *next;
};
typedef struct node nd;
void display(nd *);
void insert_before(nd *,int);
void insert_after(nd **,int);
void insert_end(nd**,rd);
void main()
{
	nd *tail;
	int i,x;
	rd rec;
	tail=NULL;
	do{
		printf("\n1:Insert at the end");
		printf("\n2:To display it");
		printf("\n3.Insert before");
		printf("\n4:Insert after");
		printf("\n0:To exit");
		printf("\nYour choice:");
		scanf("%d",&i);
		switch(i)
		{
			case 1: printf("\nEnter ID:");
					scanf("%d",&rec.id);
					fflush(stdin);
					printf("\nEnter name:");
					gets(rec.name);
					insert_end(&tail,rec);
					break;
			case 2: display(tail);	
					break;		
			case 3: printf("\nEnter particular id:");
					scanf("%d",&x);
					insert_before(tail,x);
					break;
			case 4: printf("\nEnter particular id:");
					scanf("%d",&x);
					insert_after(&tail,x);
					break; 			
			case 0: printf("\nThe End.");
					break;
			default: printf("\nInvalid Choice.");				
		}
	}while(i);
}

void insert_end(nd **p,rd item)
{
	nd *temp;
	temp=(nd*)malloc(sizeof(nd));
	if(!temp)
	{
		printf("\nInsufficient Memory.");
		return;
	}
	temp->info=item;
	if(!(*p))
		{temp->next=temp;
		*p=temp;
		return;
		}
	temp->next=(*p)->next;
	(*p)->next=temp;	
	(*p)=temp;	
}
void display(nd *p)
{
	nd *c;
	if(!p)
		return;
	c=p;
	do{printf("\n%d %s\n",c->next->info.id,c->next->info.name);	
	   c=c->next;}while(c!=p);	
}
void insert_before(nd *p,int id)
{
	int flag=0;
	nd *prev,*temp;
	if(!p)
	{
		printf("\nEmpty linked list");
		return;
	}
	prev=p;
	do
	{
		if(prev->next->info.id==id)
			{
				flag=1;
				break;
			}
		prev=prev->next;	
	}while(prev!=p);
	if(flag==0)
	{
		printf("\nInvalid id %d",id);
		return;
	}
	temp=(nd*)malloc(sizeof(nd));
	printf("\nEnter id:");
	scanf("%d",&temp->info.id);
	fflush(stdin);
	printf("\nEnter name:");
	gets(temp->info.name);
	temp->next=prev->next;
	prev->next=temp;	
}
void insert_after(nd **p,int id)
{
	int flag=0;
nd *temp,*current;
if(!*p)
	{
		printf("\nEmpty linked list");
		return;
	}
current=(*p);
do{
	if(current->info.id==id){
		flag=1;
		break;}
	current=current->next;	
}while(current!=(*p));	
if(flag==0)
	{printf("\nInvalid id %d",id);
	return;}
temp=(nd*)malloc(sizeof(nd));
printf("\nEnter id:");
scanf("%d",&temp->info.id);
fflush(stdin);
printf("\nEnter name:");
gets(temp->info.name);
temp->next=current->next;
current->next=temp;
if((*p)==current)
	(*p)=temp;	
}
