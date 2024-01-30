#include<stdio.h>
#include<stdlib.h>
void read(int **,int,int);
void write(int **,int,int);
void main(void)
{
	int **dptr=(int **)malloc(2*sizeof(int*));
	 int x,y,z,a,b,i;
        for(i=0;i<2;i++)
                dptr[i]=(int*)malloc(3*sizeof(int));
	read(dptr,2,3);
	write(dptr,2,3);
for(i=0;i<2;i++)
                free(dptr[i]);
        free(dptr);


}
void read(int **dptr,int na,int ne)
{
	int a,i;
	for(a=0;a<na;a++)
	{
		for(i=0;i<ne;i++)
		{
			printf("enetr the element for arr %d and element is %d\n",a+1,i+1);
			scanf("%d",(*(dptr+a)+i));
		}

	}

}
void write(int **dptr,int na,int ne)
{
	int a,i;
	for(a=0;a<na;a++)
		for(i=0;i<ne;i++)
			printf(" the element enter for arr %d and element is %d\n value is %d\n",a+1,i+1,*(*(dptr+a)+i));

}
