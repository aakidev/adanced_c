#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int info ;
	struct node *link;
};
struct node *create(struct node *start);
void disp(struct node *start);
void count(struct node *start);
struct node *addbeg(struct node *start,int data);
struct node *addend(struct node *start,int data);
struct node *addbefore(struct node *start,int data,int item);
struct node *addafter(struct node *start,int data,int item);
struct node *addatpos(struct node *start,int data,int pos);
struct node *sort(struct node *start);
struct node *del(struct node *start,int data);
struct node *rev(struct node *start);
void swap(struct node *a1,struct node *a2);
int main()
{
	struct node *start=NULL;
	int choice,data,item,position;
	while(1)
	{
		printf("\n1.Create list \n");
		printf("2.Display \n");
		printf("3.Search \n");
		printf("4.Add to empty list (beginning)\n");
		printf("5.Add at end \n");
		printf("6.Add after Node\n");
		printf("7.Add before Node\n");
		printf("8.Add at position \n");
	       	printf("9.Delete \n");
		printf("10.Reverse\n");
		printf("11.Count \n");
		printf("12.Sort \n");
		printf("13.Quit \n");
		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{	
			case 1:	start=create(start);	
				break;
			case 2: disp(start);
				break;

			case 3: 
				break;
			case 4: printf("Enter element to be inserted: ");
				scanf("%d",&data);
				start=addbeg(start,data);

				break;

			case 5: printf("Enter element to be inserted: ");
                                scanf("%d",&data);
                                start=addend(start,data);
				break;

			case 6: printf("Enter element to be inserted: ");
                                scanf("%d",&data);
				printf("Enter the element after which to insert\n");
				scanf("%d",&item);
                                start=addafter(start,data,item);
				break;

			case 7: printf("Enter element to be inserted: ");
                                scanf("%d",&data);
                                printf("Enter element before  which to insert\n");
                                scanf("%d",&item);
                                start=addbefore(start,data,item);
 
				break;

			case 8: printf("Enter element to be inserted: ");
                                scanf("%d",&data);
                                printf("Enter element position at  which to insert\n");
                                scanf("%d",&position);
                                start=addatpos(start,data,position);

				break;

			case 9: printf("Enter the element to be deleted\n");
				scanf("%d",&data);
				start=del(start,data);	
				break;

			case 10: start=rev(start);

				break;
				
			case 11:
				 count(start);

				break;
			case 12: 
				start=sort(start);
				break;

			case 13:exit(1); 

				break;

			default:
				printf("Wrong choice\n");
		}
	}
	return 0;
}
struct node *create(struct node*start)
{
	int i=1,n,data;
	printf("enter no. of nodes: ");
	scanf("%d ", &n);
	start=NULL;
	if(n==0)
	{return start;}
	printf("enter the element to be inserted : ");
	scanf("%d",&data);
	start= addbeg(start,data);
	for(i=2;i<=n;i++)
	{printf("enter the element to be inserted: ");
		scanf("%d",&data);
		if(data==-1)
		{	i=0;
			return start;}
		start=addend(start,data);
	}
	return start;
}
struct node *addbeg(struct node *start,int data)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	tmp->link=start;
	start=tmp;
	return start;
}
struct node *addend(struct node *start,int data)
{
        struct node *p, *tmp;
        tmp=(struct node *)malloc(sizeof(struct node));
        tmp->info=data;
	p=start;
	while(p->link)
		p=p->link;
	p->link=tmp;
        tmp->link=NULL;
        return start;
}
void disp(struct node *start)
{
	struct node *p;
	if(start == NULL){
		printf("list is empty\n");
		return ;
	}
	p=start;
	printf("list is :");
	while(p)
	{printf("%d\t",p->info);
		p=p->link;
	}
}
void count(struct node *start)
{	int c;
	struct node *p;
	while(p)
	{p=p->link;
		c++;}
	printf("total elements are : %d ",c);
}
struct node *sort(struct node *start)
{
	int f,a;
	struct node *p1,*p2=NULL;
	if(start == NULL)
		return start;
	do
	{
		f=0;
		p1=start;
		while(p1->link !=p2)
		{
			if(p1->info > p1->link->info)
			{
			swap(p1,p1->link);	
					f=1;
			}
			p1=p1->link;
			
		}
	}		while(f);
	return start;
}
void swap(struct node *s1, struct node *s2)
{
	int t=s1->info;
	s1->info=s2->info;
	s2->info=t;
}
struct node *del(struct node *start,int data)
{
       
        struct node *p,*tmp;
	if(start==NULL)
	{
		printf("list is empty\n");
		return start;
	}
	if(start->info==data)
	{
		tmp=start;
		start=start->link;
		free(tmp);
		return start;
	}
	        p=start;
                while(p->link)
  		{
                        if(p->link->info==data)
                        {	tmp=p->link;
				p->link=tmp->link;
				free(tmp);
                                return start;
                        }
                        p=p->link;

                }
                 printf("element not found\n");      
        return start;
}

struct node *rev(struct node *start)
{
	struct node *pre,*ptr,*next;
	pre=NULL;
	ptr=start;
	while(ptr)
	{
		next=ptr->link;
		ptr->link=pre;
		pre=ptr;
		ptr=next;
	}
	start=pre;
	return start;
}
struct node *addafter(struct node *start,int data,int item)
{
	struct node *tmp,*p;
	p=start;
	while(p)
	{if(p->info==item)
		{
			tmp=(struct node *)malloc(sizeof(struct node));
			if(tmp==NULL)
				printf("memory not available\n");
			else
			{
				tmp->info=data;
				tmp->link=p->link;
				p->link=tmp;
				return start;
			}
			
		}
		p=p->link;
	}
	printf("%d not present in the list \n",item);
	return start;
}
struct node *addbefore(struct node *start,int data,int item)
{
        struct node *tmp,*p;
	if(start==NULL)
	{printf("List is empty\n");
		return start;
	}
	if(item==start->info)
	{   tmp=(struct node *)malloc(sizeof(struct node));
        tmp->info=data;
        tmp->link=start;
        start=tmp;
        return start;}
        p=start;
        while(p)
        {if(p->info==item)
                {
                        tmp=(struct node *)malloc(sizeof(struct node));
                        if(tmp==NULL)
                                printf("memory not available\n");
                        else
                        {
                                tmp->info=data;
                                tmp->link=p->link;
                                p->link=tmp;
                                return start;
                        }

                }
                p=p->link;
        }
        printf("%d not present in the list \n",item);
        return start;
}
struct node *addatpos(struct node *start,int data,int pos)
{
	struct node *tmp,*p;
	int i;
	p=start;
	for(i=1;i<pos-1 && p!=NULL;i++)
		p=p->link;
	if(p==NULL)
	printf("there are than %d elements \n",pos);
	else
		tmp=(struct node *)malloc(sizeof(struct node));
                        if(tmp==NULL)
                                printf("memory not available\n");
                        else
                        {	tmp->info=data;
			 	if(pos==1)
				{	tmp->link=start;
					start=tmp;
				}
				else
				{
                                	tmp->link=p->link;
                                	p->link=tmp;
				}
			}
                                return start;
}

