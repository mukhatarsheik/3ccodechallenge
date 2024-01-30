/* to know the arichtech of your device whether it is little endian  or big endian from this program .........................................*/
#include<stdio.h>
void aricheck(unsigned int val);
void main(void)
{
	unsigned int num,ret;
	printf("enter the value to know arichtech in hex decimal\n");
	scanf("%X",&num);
	aricheck(num);
}
void aricheck(unsigned int val)
{
	int seg;
	seg=val&0xff;
	if((val>>24)==seg)
		printf("your arichitecture is big endian %x\n",val>>23);
	else if((val&0xff)==seg)
		printf("your arichitecture is little endian\n");
}
