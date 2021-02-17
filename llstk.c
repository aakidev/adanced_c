#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *link;
};
struct node *push(struct node *top,int data);
struct node *pop(struct node *top);
int main()
{
	struct node *top=NULL;
	int choice,ele,data;
	printf("enter element to create a stack\n");
	scanf("%d",&ele);
	top=push(top,ele);
	while(1)
	{
		printf("1.push\n");
		printf("2.pop\n");
		printf("3.display\n");
		printf("4.quit\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1: printf("enter element to be stacked\n");
				scanf("%d",&data);
				top=push(top,data);
				break;

			case 2: printf("deletion in process\n");
				top=pop(top);
				break;

			case 4: exit(1);
				break;

			default: printf("enter correct choice\n");
				 break;
		}
	}
}
struct node *push(struct node *top,int data)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	if(tmp==NULL)
		printf("stack is full\n");
	else
	{
		tmp->info=data;
		tmp->link=top;
		top=tmp;
	}
	return top;
}
struct node *pop(struct node *top)
{
	struct node *tmp;
	if(top==NULL)
		printf("stack is empty\n");
	else
	{tmp=top;
	top=top->link;
	free(tmp);
	printf("deletion done\n");}
	return top;
}

