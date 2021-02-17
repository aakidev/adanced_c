#include<stdio.h>
#include<stdlib.h>
void strcatt(char *s1,char *s2,int n,int m)
{	int i,j;
	for(i=0;i<n;i++)
		s1++;
	for(j=0;j<m;j++)
	{*s1=*s2;
		s1++;
		s2++;
	}
	*s1=0;
}
int main()
{	int n=2;
	int m=3;
	char *p1,*p2;
	p1=(char *)malloc(10);
	p2=(char *)malloc(10);
	printf("enter s1\n");
	scanf("%s",p1);
	printf("enter s2\n");
	scanf("%s",p2);
        printf("s1:%s\n",p1);
        printf("s2:%s\n",p2);
        strcatt(p1,p2,n,m);
        printf("after: %s",p1);
}

