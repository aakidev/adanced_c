#include<stdio.h>
#include<stdlib.h>
#define size 5
int main()
{void push(int [],int *);
int pop(int [],int *);
	int s[size];
	int top=-1;
	int choice,a;
	while(1){
	printf("1.push\n");
	printf("2.pop\n");
	printf("3.display\n");
	printf("4.quit\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1: push(s,&top);
			break;
		case 2: a=pop(s,&top);
			printf("poped element is : %d\n",a);
			break;
		case 3: //disp();
			break;
		case 4: exit(1);
			break;

		default: printf("enter correct choice\n");
	}}
}
void push(int s[],int *top)
{	int n;
	if(*top==size-1)
		printf("stack is full\n");
	else
	{	printf("enter data : ");
		scanf("%d",&n);
		++*top;
		s[*top]=n;
	}
}
int pop(int s[],int *top)
{
	int a;
	if(*top==-1)
		printf("stack is empty\n");
	else
	{	a=s[*top];
		--*top;
	}
	return a;
}
