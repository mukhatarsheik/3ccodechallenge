// basic to every trick of pointer
#include<stdio.h>
void main()
{
	int x=40;
	/*int *ptr=&x;
	printf("add-%p val-%d sizeadd-%d sizeval-%d\n",&x,x,sizeof(&x),sizeof(x));
	printf("ptradd-%p sizeptr-%d \n",ptr,sizeof(ptr));
	printf("drfptr-%d sizedrfptr-%d \n",*ptr,sizeof(*ptr));
	printf("ptraddptr-%p ptrsizeptr-%d \n",&ptr,sizeof(&ptr));
	printf("the val %d add %p\n",*ptr,ptr);
	(*ptr)++;
	printf("the val %d add %p\n",*ptr,ptr);
	printf("the val %d add %p",++*ptr,++*ptr);
	printf("the val %d add %p",++(*ptr),++(*ptr));
	printf("the val %d add %p",*(ptr++),*(ptr++));*/


	unsigned int y=0x41424344,*vptr=100;
        unsigned int *iptr=&y;
	unsigned char *cptr =&y;
	unsigned short int *sptr=&y;
	/*printf("%d-%x-%d\n",*ptr,*ptr,*ptr);
	printf("the val of z is %d\n",vptr);
	//printf("the val of z is %d\n",*vptr); you will get error*/
	/*printf("the val is %x add is %p\n",*cptr,cptr);
	printf("4th is %p-%x\n",cptr+(4-1),*(cptr+(4-1)));
	cptr++;
	//sptr=sptr+1;
	printf("the val is %x add is %p\n",*cptr,cptr);*/
	++*sptr;
        ++*cptr;
	printf("the char in short is %x\n",*sptr);
	printf("add of si is %p\n",sptr);
	printf("the char in char is %x\n",*cptr);
	printf("add of char is %p\n",cptr);
	*sptr++;
	*cptr++;
	printf("the char in short is %x\n",*sptr);
	printf("add of si is %p\n",sptr);
	printf("the char in char is %x\n",*cptr);
	printf("add of char is %p\n",cptr);
	

}

