/*1.
 *
 * writeCreate a dynamic array of integers. Take input from user , sort the array and display the output. Use bubble sort (compare every pair of adjacent elements and swap them if they are not in ascending order, repeat until the entire array is sorted in ascending order)*/

#include<stdio.h>
#include<stdlib.h>
int main()
{	int i,j;
	int *ptr=(int *)malloc(10 *sizeof(int));//initialized array of size 10
	for(i=0;i<10;i++)	//loop for user input
	{
	scanf("%d",&ptr[i]);
	}

	for(j=0;j<10;j++)		//outer loop 
	{for(i=0;i<10-j;i++)	//inner loop for run till last unsorted array
		{if(ptr[i]>ptr[i+1]) //checking two adjacent value &compare
		{int t;
			t=ptr[i];
			ptr[i]=ptr[i+1];
			ptr[i+1]=t;
		}
		}
	}
	for(i=0;i<10;i++)		//loop for printing
	{
		printf("re:%d\t",ptr[i]);
	}

}
