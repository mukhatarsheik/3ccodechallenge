#include<stdio_ext.h>
#include<string.h>
#include<stdlib.h>
#include"cmhead.h"

/*inputbuf and inbuf string is use to take the input from the user for command line argument
 *parameter is use to hold the value of no of parameter(argument) given by the user along with command,command string is use to store the command name from the input string 
 *ix,ide,ind_1,ind_2 these are use as index values for the string and array and res is use to store the return value of the called function
 * mor2 is the int variable use when the are more than 2 output value need to be return back to the user
 * con int variable is use to hold the value after converting them from character to interger argu_1 and argu_2 are use to store the arguments after the command name in the input string*/
/*here struct para hold the different parameter of the Uc like temp,pressure in which some are int,char type etc var is structure variable and struct led is also use for same purpose*/
	struct command *head;
	unsigned char regist_command=0;
	 int ind_1=0,ind_2=0;
void main()
{
	/*this is the command line function or main func which perform command line operation and send to application 
	 *this function purse the command line argument which are in the form of strings and check for the user case like login,registeration,processing of stored command and help 
	 *this function also consist of dynamic creation of array of structure variable as the process load for the user and create two default command like help and blink which user can't register or remove */
	
	int def=2,opt,res;
	// opt for option variable for switch statement,res to store the calling functions return values,def is the default value of the available command in the syst
	char inputbuf[10],argument[8],command[8],userid[20],userpass[20];
	struct login log={.id="123456789",.pass="may i comein"};
	head=(struct command *)malloc(5*sizeof(struct command));
	if(head==NULL)
		printf("fail to create array of struct\n");
	else
		printf("created array of structure variable\n");
	printf("pls login to execute the system command\n");
	printf("enter the user id\n");
	scanf("%[^\n]s",userid);
			__fpurge(stdin);
	printf("enter the user password\n");
	scanf("%[^\n]s",userpass);
			__fpurge(stdin);
	if(strcmp(userid,log.id)==0&&strcmp(userpass,log.pass)==0)
	{
		for(ind_1=0;ind_1<def;ind_1++)
		{
			if(!ind_1)
			{
				printf("the val of ind_1 is %d\n",ind_1);
				strcpy(head[ind_1].name,"help");
				strcpy(head[ind_1].help,"help:-this command use for description");
				head[ind_1].f_c=command_inter;
				head[ind_1].para=-1;
				regist_command++;
			}
			else
			{
				struct command blink;
				strcpy(head[ind_1].name,"blink");
				strcpy(head[ind_1].help,"blink:-this command use for status of leds");
				head[ind_1].f_c=command_inter;
				head[ind_1].para=2;
				regist_command++;
			}
		}
		while(1)
		{
			printf("enter the option type help for description or\n 0. for termination of the process\n 1.for registeration\n 2.for process\n");
			scanf("%[^\n]s",inputbuf);
			//inputbuf is use for taking the input from user
			__fpurge(stdin);
			strcpy(argument,"\0");
			int count =1;
			//count is use to as index value for array of structure and ind_2 for general use as index for array operation
			for(ind_1=0,ind_2=0;inputbuf[ind_2]!='\0';ind_2++)
			{
				if(inputbuf[ind_2]==' ')
				{		
					for(ind_1=0,ind_2=ind_2+1;(inputbuf[ind_2]!='\0')&&(inputbuf[ind_2]!=' ');ind_1++,ind_2++)
						argument[ind_1]=inputbuf[ind_2];
					argument[ind_1]='\0';
					for(count;(strcmp(head[count].name,argument)!=0) && (head[count].para!=0);count++);
					break;
				}
				else
				{
					command[ind_1++]=inputbuf[ind_2];
					(inputbuf[ind_1]=='\0'||inputbuf[ind_1]==' ')?command[ind_1]='\0':inputbuf[ind_1];
				}
			}
			if((inputbuf[0]>=48)&&(inputbuf[0]<=50))
			{
				opt=inputbuf[0]-48;
				switch(opt)
				{
					case 0:exit(0);
					case 1:if(regist_command<5)
					       {
						       printf("enter the command and paramter\n");
						       scanf("%s %d",inputbuf,&res);
						       __fpurge(stdin);
						       res=register_command(inputbuf,res);
						       if(res)
							       printf("command %s is success\n",inputbuf);
						       else
							       printf("not reg\n");
					       }
					       else
						       printf("commmand reach exceed limit\n");
					       break;
					case 2:printf("enter the command for process\n");
					       scanf("%[^\n]s",inputbuf);
					       __fpurge(stdin);
					       process(inputbuf);
					       break;
				}	
			}
			else
			{
				if((strcmp(head[count].name,argument)==0)&&(strcmp(command,"help")==0)&&(head[count].para!=0))
				{
					printf("\t");
					printf("%s\n",head[count].help);
				}
				else if(strcmp(command,"help")==0)
				{
					for(ind_1=0;(head[ind_1].para!=0)&&(ind_1<MAX);ind_1++)
					{
						printf("\t");
						printf("%s\n",head[ind_1].help);
					}
				}
				else
					printf("command is incorrect\n");
			}		
		}

	}
	else
		printf("login is fail try again\n");
}


