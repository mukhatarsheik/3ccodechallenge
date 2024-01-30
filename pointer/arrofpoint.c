#include<stdio.h>
#include<stdlib.h>
#define NM 5
int * read(int x[3]);
void write(int y[3]);
void main(void)
{
	int **dptr,*ptr;
	dptr=(int **)malloc(2*sizeof(int*));
	int x,y,z,a,b,i;
        for(i=0;i<2;i++)
		dptr[i]=(int*)malloc(3*sizeof(int));
	for(a=0;a<2;a++)
	{
	     ptr=read(dptr[a]);
	     write(ptr);
	}




/*	int arr[NM]={5,10,15,20,25},sal[NM]={1,3,5,7,9};
	int *poin[2]={arr,sal};
	int x,y,z,a,b,i;
	/*poin[0]=&x;
	poin[1]=&y;
	poin[2]=&z;
	poin[3]=&a;
	poin[4]=&b;    //manually
        printf("add of x is %p\n",&x);
        printf("add of y is %p\n",&y);
        printf("add of z is %p\n",&z);
        printf("add of a is %p\n",&a);
        printf("add of b is %p\n",&b);*/
	/*for(i=0;i<NM;i++)
	{
		printf("enter the value for %d var\n",i+1);
		scanf("%d",poin[i]);
		__fpurge(stdin);
	}
	for(i=0;i<NM;i++)
		printf("the elemnet %d is %d and the add is %p\n",i+0,poin[i][0],poin[i]);


	for(i=0;i<2;i++)
		for(a=0;a<NM;a++)
			printf("arr no %d element no %d is %d\n",i+1,a+1,poin[i][a]);*/
	for(i=0;i<2;i++)
		free(dptr[i]);
	free(dptr);
	

}
int * read(int x[3])
{
	int a;
	for(a=0;a<3;a++)
	{
		printf("enter element no %d\n",a+1);
		scanf("%d",x+a);
	}
	return x;
}
void write(int y[3])
{
	int a;
	for(a=0;a<3;a++)
		printf("element no %d is %d\n",a+1,y[a]);
}








