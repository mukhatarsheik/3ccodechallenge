#include<stdio.h>
#include<stdlib.h>
/* in this program we will write 
 * a program to display the int value in bitformat
 * a program to clear the right most 1 bit in the given int value
 * a program to where if you left shifted the value which are deleted from left most end should be added to right most end if we right shifted the value    which are delted from rightmost end need to be added at the leftmost end like circular shifting
 * a program to swap two bit from different position in the same int
 * a program to check the given int is exactly  the power of 2 or not 
 * a program to check bitfiled operation by giving the int val which will assign to different bitfiled of different range */
struct tags{
	unsigned int a:3;
	unsigned int b:5;
	unsigned int c:2;
};
void display(int);
void circular(int);
void leftshift(void);
void rightshift(void);
int rightbit(int);
int powerof2(int);
void bitfield(int);
void main(void)
{
	while(1)
	{
		char opt;
	       int no,ret,p1,p2;
		printf("the option for the bitwise operation.....\n for 0 exit the process....\n 1 for clearing the right most 1 bit....\n 2 for display the int value in bit pattern....\n 3. for powerof 2...\n 4.bitswapper for the given value and positions....\n 5.perform circular shift opeartion...\n 6. perform bitfiled operation.....\n");
		printf("the enter the opt for the respective operaton\n");
		scanf("%c",&opt);
		__fpurge(stdin);
		switch(opt)
		{
			case '0':exit(0);
			case '1':printf("entered the value to cleared it rightmost bit\n");
				 scanf("%d",&no);
		                 __fpurge(stdin);
				 display(no);
				 ret=rightbit(no);
				 printf("after clearing rightmost 1 bit\n");
				 display(ret);
				 break;
			case '2':printf("enter the no to get it bit pattern\n");
				 scanf("%d",&no);
				 display(no);
			case '3':printf("enter the val to chk it exactly power of 2 or not\n");
				 scanf("%d",&no);
				 ret=powerof2(no);
		                 __fpurge(stdin);
				 if(ret==0)
					 printf("no is exactly power of 2\n");
				 else
					 printf("power of 2\n");
				 break;
			case '4':printf("enter int value-position1-position2 that need to be swap within the given integer p1 need to first and p2 need be second position\n");
				 scanf("%d-%d-%d",&no,&p1,&p2);
				 printf("bit pattern of the entered int before swapping\n");
				 display(no);
				 ret=bit_swapper(no,p1,p2);
				 printf("bit pattern of the entered int after swapping\n");
				 display(ret);
				 break;
			case '5':printf("enter the 1. for leftshift\n 2. for rightshift\n");
				 scanf("%d",&ret);
				 circular(ret);
				 break;
			case '6':printf("enter the an int value  to be check with different int val\n");
				 scanf("%d",&no);
				 bitfield(no);
				 break;
			default:printf("invalid option\n");


		}
	}
}
int rightbit(int num)
{
	return num&(num-1);
}
void display(int val)
{
	printf("in display the value is %d\n",val);
	int a;
	for(a=31;a>=0;a--)
	{
		if(a%8==0 && a)
			printf(" ");
		printf("%d",((val&(0x1<<a))>>a));
	}

}
int powerof2(int num)
{
	if(num&(num-1)==0)
		return 1;
	else
		return 0;
}
void bitfield(int val)
{
	struct tags b1={.a=val,.b=val,.c=val};
	printf("the value of given digit in bit pattern\n");
	display(val);
	printf("the value of bitfld a is range from 0-7 only that it can hold bit pattern of bitfld a after assigning the given value to it\n");
	display(b1.a);
	printf("the value of bitfld b is range from 0-31 same as int type that it can hold bit pattern of bitfld b after assigning the given value to it\n");
	display(b1.b);
	printf("the value of bitfld c is range from 0-3 only that it can hold bit pattern of bitfld c after assigning the given value to it\n");
	display(b1.c);


}
int bit_swapper(int num,int p1,int p2)
{ 
	int temp;
	if(p1>p2)
	{
		temp=p1;
		p1=p2;
		p2=temp;

	}
		num=num&~((0x1<<p1|0x1<<p2))|(num&0x1<<p1)<<p2-p1|(num&(0x1<<p2))>>(p2-p1);
		return num;
}
void circular(int val)
{
	int ret;
	switch(val)
	{
		case 1:leftshift();
		       break;
		case 2:rightshift();
		       break;
		default:printf("invalid opt\n");

	}
}
void leftshift()
{
	int no,not;
	printf("enter the val-no_bit to be left shifted\n");
	scanf("%d-%d",&no,&not);
	__fpurge(stdin);
	printf("before circular operation\n");
	display(no);
	no=(no<<not)|(no>>32-not);
	printf("after circular operation\n");
	display(no);
}
void rightshift()
{
	int no,not;
	printf("enter the val-no_bit to be right shifted\n");
	scanf("%d-%d",&no,&not);
	__fpurge(stdin);
	printf("before circular operation\n");
	display(no);
	no=(no>>not)|(no<<32-not);
	printf("after circular operation\n");
	display(no);
}

