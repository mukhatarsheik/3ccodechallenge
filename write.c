#include<stdio.h>
int read(int);
int write(int ch)
{
	int ret;
	if(ch==10)
		return 0;
	else
	 ret=putchar(ch);
	return ret;
}
