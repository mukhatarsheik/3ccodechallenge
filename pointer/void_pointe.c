// how to use void pointer and how to typecast it 
#include<stdio.h>
#include<stdlib.h>
#define NO 5
void display(void *,int);
void read(void *, int);
void  main(void)
{
	void *ptr=malloc(5*sizeof(int));
	read(ptr,NO);
	display(ptr,NO);
	free(ptr);
}
void display(void *ptr,int a)
{
	int i;
	for(i=0;i<a;i++)
		printf("the value is %x add is %p\n",((int*)ptr)[i],&((int*)ptr)[i]);
}
void read(void *ptr,int a)
{
	int i;
	for(i=0;i<a;i++)
	{
		printf("enter the value for element %d\n",i+1);
		scanf("%x",&((int*)ptr)[i]);
	}
}
