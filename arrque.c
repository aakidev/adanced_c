#include<stdio.h>
#include<stdlib.h>
#define size 5
int main()
{void enque(int [],int *);
int deque(int [],int *,int *);
	int s[size];
	int r=-1,f=-1;
	int choice,a;
	while(1){
	printf("1.Enque\n");
	printf("2.Deque\n");
	printf("3.display\n");
	printf("4.quit\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1: enque(s,&r);
			break;
		case 2: a=deque(s,&f,&r);
			printf("poped element is : %d\n",a);
			break;
		case 3: //disp();
			break;
		case 4: exit(1);
			break;

		default: printf("enter correct choice\n");
	}}
}
void enque(int s[],int *r)
{	int n;
	if(*r==size-1)
		printf("Queue is full\n");
	else
	{	printf("enter data : ");
		scanf("%d",&n);
		++*r;
		s[*r]=n;
	}
}
int deque(int s[],int *f,int *r)
{
	int a;
	if(*f==*r)
		printf("Queue is empty\n");
	else
	{	++*f;
		a=s[*f];
		
	}
	return a;
}
