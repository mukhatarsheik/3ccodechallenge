#include<stdio.h>
#include<string.h>
#include"cmhead.h"
/*inputbuf string is use to take the input from the user for command line argument 
 *parameter is use to hold the value of no of parameter(argument) given by the user along with command
 * arp is the int array which hold the value as 1,2,3 which are use to match with no of parameter in the given command  
 *here ix is the index value of the  array regist_command is the global variable which keep the value of registeration of command*/


int arp[3]={1,2,3};
int get_parameter(char inputbuf[])
{
	/* this function use to return no of parameter in the command 
	 * by using the space between the input string which is given by the user as command and argument*/
	int parameter=0,ix;
	/*here ix is the index value of the input array and paramter is used to hold the value of no of parameter after the command*/
	for(ix=0;inputbuf[ix]!='\0';ix++)
	if(inputbuf[ix]==' ')
		parameter++;
	return parameter;
}			
int register_command(char inputbuf[],int parameter)
{
	/* This function is use for registeration of 3 new commands from the user by checking the command name is correct or not
	 * this function use to return  1 when successfully registered a new command in array of structure with the index value
	 * and return 0 if incorrect command name or no of parameter are mismatched with the command name 
	 * also check and prevent the user to register the same command again and again
	 * in this registration we are registering only 3 command like set,get and concat*/
	int ix;
        for(ix=0;head[ix].para!=0;ix++)
                if(strcmp(head[ix].name,inputbuf)==0)
                {
                        printf("command %s is already regist\n",inputbuf);
                        return 0;
                }
        if(strcmp(inputbuf,"set")==0)//set command registeration
        {
                if(parameter!=arp[1])
                {
                        printf("no of parametr is not correct\n");
                        return 0;
                }
                else
                {
                        printf("new index value is %d for command %s\n",ix,inputbuf);
                        strcpy(head[ix].name,inputbuf);
                        strcpy(head[ix].help,"set:-command will set the parameters");
                        head[ix].f_c=command_inter;
                        head[ix].para=parameter;
                        regist_command++;
                }
        }
	else if(strcmp(inputbuf,"get")==0)//get command registeration
        {
                if(parameter!=arp[0])
                {
                        printf("no of parametr is not correct\n");
                        return 0;
                }
                else
                {
                        printf("index value of new command %s is %d\n",inputbuf,ix);
                        strcpy(head[ix].name,inputbuf);
                        strcpy(head[ix].help,"get:-command will get the parameters");
                        head[ix].f_c=command_inter;
                        head[ix].para=parameter;
                        regist_command++;
		}
	}
	else if(strcmp(inputbuf,"concat")==0)// get command registeration
        {
                if(parameter!=arp[1])
                {
                        printf("no of parametr is not correct\n");
                        return 0;
                }
                else
                {
                        printf("index value of new command %s is %d\n",inputbuf,ix);
                        strcpy(head[ix].name,inputbuf);
                        strcpy(head[ix].help,"concat:-command will apend the two string as one string");
                        head[ix].f_c=command_inter;
                        head[ix].para=parameter;
                        regist_command++;
                }
        }
	else
	{
		printf("wrong command is entered\n");
		return 0;
	}
        return 1;
}	
