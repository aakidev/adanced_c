#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *a1,*a2,*a3;
	int i,j;

	a1=(int *)malloc(5*sizeof(int));
	a2=(int *)malloc(5*sizeof(int));
	a3=(int *)malloc(10*sizeof(int));
	printf("enter sorted array 1:\n");
	for(i=0;i<5;i++)
		scanf("%d",&a1[i]);
	printf("enter sorted array 2:\n");
        for(i=0;i<5;i++)
                scanf("%d",&a2[i]);
	i=0;
	j=0;
	int k=0;
	while((i<5&&j<5))
	{
		
		if(a1[i]<a2[j])
	{	a3[k]=a1[i];
		k++;
		i++;
		if(a1[i]==a2[j])
		{	a3[k]=a1[i];
		k++;
		i++;
		//j++;
		}
	}	else
	{		a3[k]=a2[j];
		k++;j++;
	}}		
	while(i<5)
	{	a3[k]=a1[i];
	k++;i++;
	}
	while(j<5)
	{       a3[k]=a2[j];
        k++;j++;
        }
	

	for(i=0;i<10;i++)
		printf("result is %d\n",a3[i]);
}
	
