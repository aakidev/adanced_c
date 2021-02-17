#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *link;
};
struct node *enque(struct node *top,int data);
struct node *insert(struct node *top,int data);
struct node *deque(struct node *top,struct node *rear);
int main()
{
	struct node *front=NULL,*rear = NULL;
	int choice,ele,data;
	printf("enter element to create a stack\n");
	scanf("%d",&ele);
	rear=insert(rear,ele);
	front=rear;
	while(1)
	{
		printf("1.Enque\n");
		printf("2.Deque\n");
		printf("3.Display\n");
		printf("4.Quit\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1: printf("enter element to be stacked\n");
				scanf("%d",&data);
				rear=enque(rear,data);
				break;

			case 2: printf("deletion in process\n");
				front=deque(front,rear);
				break;

			case 4: exit(1);
				break;

			default: printf("enter correct choice\n");
				 break;
		}
	}
}
struct node *enque(struct node *rear,int data)
{
	struct node *tmp,*p;
	tmp=(struct node *)malloc(sizeof(struct node));
	if(tmp==NULL)
		printf("stack is full\n");
	else
	{
		tmp->info=data;
		p=rear;
		while(p->link!=NULL)
			p=p->link;
		p->link=tmp;
		tmp->link=NULL;
		
	}
	return rear;
}
struct node *deque(struct node *front,struct node *rear)
{
	struct node *tmp;
	if(front==NULL||rear==NULL)
		printf("stack is empty\n");
	else
	{tmp=front;
	front=front->link;
	free(tmp);
	printf("deletion done\n");}
	return front;
}
struct node *insert(struct node *rear,int data)
{
        struct node *tmp,*p;
        tmp=(struct node *)malloc(sizeof(struct node));
        if(tmp==NULL)
                printf("stack is full\n");
        else
        {
                tmp->info=data;
                tmp->link=rear;
		rear=tmp;

        }
        return rear;
}
