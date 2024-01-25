#include<stdio_ext.h>
int read(void);
int write(int);
main()
{
	printf("enter the charac");
	int vk,vl;
	char ent;
	printf("enter the character from the range 0-127 from ascii then and then after completion of sentence press enter key\n");
	while(1)
	{
		vk=read();
		if(vk==10)
			break;
		write(vk);
		/*vl=read(vk);
		 ent=write(vl);*/
	}
}
