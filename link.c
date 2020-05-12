#include<stdio.h>
#include<stdlib.h>
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
void display(nd*);
void insert_end(nd**,int);
void main()
{
	nd *tail,*start;
	int i,x;
	rd rec;
	tail=start=NULL;
	do{
		printf("\n1:Insert at the end");
		printf("\n2:Insert before a particular node");
		printf("\n3:Insert after a particular node");
		printf("\n4:To display it");
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
					insert_end(&start,rec);
					break;
			case 4: display(start);
					break;
			case 0: printf("\nThe End.");
					break;
			default: printf("\nInvalid Choice.");
		}
	}while(i);
}

void insert_end(nd **p,rd item)
{
	nd *temp,*current;
	temp=(nd*)malloc(sizeof(nd));
	if(!temp)
	{
		printf("\nInsufficient Memory.");
		return;
	}
	temp->info=item;
	temp->next=NULL;
	if(!p)
	 {
	 	*p=temp;
	 	return;
	 }
	current=*p;
	while(current->next!=NULL)
		current=current->next;
	current->next=temp;
	main();
}
void display(nd *p)
{
	printf("\n%d %s",p->info.id,p->info.name);
	if(!p)
		return;
	display(p->next);
}
