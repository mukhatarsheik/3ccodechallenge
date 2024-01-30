#include<stdio.h>
void main(void)
{
	int x=98;
	int *ptr=&x,**dptr=&ptr;
	printf("the add of x is %p \n",&x);
	printf("ptr val is %p and it add is %p\n",ptr,&ptr);
	printf("dptr val is %p and it add is %p\n",dptr,&dptr);
	printf("deference dptr for 1 time %p\n",*dptr);
	printf("deference dptr for 2 time %d\n",**dptr);



}
