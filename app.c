#include<stdio_ext.h>
#include<stdlib.h>
#include<string.h>
#include"cmhead.h"
/*inputbuf and inbuf string is use to take the input from the user for command line argument 
 *parameter is use to hold the value of no of parameter(argument) given by the user along with command
 *ix,ide,ind_1,ind_2 these are use as index values for the string and array and res is use to store the return value of the called function 
 * mor2 is the int variable use when the are more than 2 output value need to be return back to the user
 * con int variable is use to hold the value after converting them from character to interger argu_1 and argu_2 are use to store the arguments after the command name in the input string*/
/*here struct para hold the different parameter of the Uc like temp,pressure in which some are int,char type etc var is structure variable and struct led is also use for same purpose*/
struct led lit;
struct param var={.lh=&lit}; 			

void process(char inputbuf[])
{
	int ix,res;
	char command[10];
	for(ix=0;inputbuf[ix]!=' ';ix++)
		command[ix]=inputbuf[ix];
	command[ix]='\0';
	for(ix=0;ix<MAX;ix++)
	{
		if(strcmp(head[ix].name,command)==0)
			break;
	}
	if(strcmp(head[ix].name,command)==0)
	{
		res=get_parameter(inputbuf);
		if(res==head[ix].para)
		{
                        inkov:res=head[ix].f_c(inputbuf,ix);
			if(!res)
				printf("the entered parameter is not as per the command\n");
			else if(res==2)
				goto inkov;
		}
		else
			printf("command is ok but para is wrong\n");
	}
	else
		printf("command not registered\n");
}
int command_inter(const char inbuf[],int idx)
{
	int con_int=0,i=10,rer=0,z=0;
       	char command[8],argu_1[10],argu_2[10];
	unsigned int id_1=0,id_2=0,ide=0;
	int parameter=0;
	for(ide;inbuf[ide]!='\0';ide++)
	{
			if(inbuf[ide]==' ')
			{
				parameter++;
				continue;
			}
			else if(parameter==1)
			{
				argu_1[id_1++]=inbuf[ide];
				if(inbuf[ide+1]==' '||inbuf[ide+1]=='\0')
					argu_1[id_1]='\0';
			}
			else if(parameter==2)
			{
				argu_2[id_2++]=inbuf[ide];
				if(inbuf[ide+1]==' '||inbuf[ide+1]=='\0')
				{
					argu_2[id_2]='\0';
				}
			}
	}
	ide=0,id_1=0;
	while((inbuf[ide]!=' ')&&(inbuf[ide]!='\0'))
	{
		command[ide++]=inbuf[id_1++];
		if(inbuf[id_1]==' ')
			command[ide]='\0';
	}
	if(strcmp("set",command)==0)//set
	{
		if(strcmp(argu_1,"temp")==0)
		{
			id_2=0;
			for(id_2;id_2<strlen(argu_2);id_2++)
			{
				if((argu_2[id_2]>=48)&&(argu_2[id_2]<=57))
				{
					con_int=con_int*i+argu_2[id_2]-48;
				}
			}
			if(con_int>0)
			{
				
				var.temp=con_int;
				return 1;
			}
			else
				return 0;

		}
		else if(strcmp(argu_1,"press")==0)
		{
			id_2=0;
			for(id_2;id_2<strlen(argu_2);id_2++)
			{
				if((argu_2[id_2]>=48)&&(argu_2[id_2]<=57))
				{
					con_int=con_int*i+(argu_2[id_2]-48);
				}
			}
			if(con_int>0)
			{
				var.press=con_int;
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
	else if(strcmp(command,"get")==0)
	{
		if(strcmp(argu_1,"temp")==0)
			printf("temp  %d\n",var.temp);
		else if(strcmp(argu_1,"press")==0)
			printf("press %d\n",var.press);
		else if(strcmp(argu_1,"leds")==0)
		{
			if(mor2>=0)
			{
				if(mor2==5)
				{
					printf("the led1 is %s\n",var.lh->led1);
					mor2--;
					sleep(1);
					return 2;
				}
				else if(mor2==4)
				{
					printf("the led2 is %s\n",var.lh->led2);
					mor2--;
					sleep(1);
					return 2;
				}
				else if(mor2==3)
				{
					printf("the led3 is %s\n",var.lh->led3);
					mor2--;
					sleep(1);
					return 2;
				}
				else if(mor2==2)
				{
					printf("the led4 is %s\n",var.lh->led4);
					mor2--;
					sleep(1);
					return 2;
				}
				else if(mor2==1)
				{
					printf("the led5 is %s\n",var.lh->led5);
					mor2--;
					sleep(1);
					return 2;
				}
				else if(mor2==0)
					return 1;
			}
		}
		else if(strcmp(argu_1,"led1")==0)
		{
			printf("led1 is %s\n",var.lh->led1);
			return 1;
		}
		else if(strcmp(argu_1,"led2")==0)
		{
			printf("led2 is %s\n",var.lh->led2);
			return 1;
		}
		else if(strcmp(argu_1,"led3")==0)
		{
			printf("led3 is %s\n",var.lh->led3);
			return 1;
		}
		else if(strcmp(argu_1,"led4")==0)
		{
			printf("led4 is %s\n",var.lh->led4);
			return 1;
		}
		else if(strcmp(argu_1,"led5")==0)
		{
			printf("led5 is %s\n",var.lh->led5);
			return 1;
		}
		else
			return 0;
		return 1;
	}
	else if(strcmp(command,"blink")==0)
	{
		if((argu_1[3]>=49)&&(argu_1[3]<=53))
		{
			if(strcmp(argu_2,"on")==0)
			{
				if(argu_1[3]==49)				
				{
					strcpy(lit.led1,"on");
					return 1;
				}
				else if(argu_1[3]==50)
				{
					strcpy(lit.led2,"on");
					return 1;
				}
				else if(argu_1[3]==51)
				{
					strcpy(lit.led3,"on");
					return 1;
				}
				else if(argu_1[3]==52)
				{
					strcpy(lit.led4,"on");
					return 1;
				}
				else if(argu_1[3]==53)
				{
					strcpy(lit.led5,"on");
					return 1;
				}
				else
					return 0;	
			}
			else if(strcmp(argu_2,"off")==0)
			{
				if(argu_1[3]==49)
				{
					strcpy(var.lh->led1,"off");
					return 1;
				}
				else if(argu_1[3]==50)
				{
					strcpy(var.lh->led2,"off");
					return 1;
				}
				else if(argu_1[3]==51)
				{
					strcpy(var.lh->led3,"off");
					return 1;
				}
				else if(argu_1[3]==52)
				{
					strcpy(var.lh->led4,"off");
					return 1;
				}
				else if(argu_1[3]==53)
				{
					strcpy(var.lh->led5,"off");
					return 1;
				}
				else
					return 0;
			}
			else 
				return 0;
		}
		else
			return 0;


	}
	else if(strcmp(command,"concat")==0)
	{
		id_1=0;
		id_1=strlen(argu_1);
		for(id_1,id_2=0;argu_2[id_2]!='\0';id_1++,id_2++)
			argu_1[id_1]=argu_2[id_2];
		argu_1[id_1]=argu_2[id_2];
		printf("the concat string is %s\n",argu_1);
		return 1;
	}
}
