#define MAX 5
#include<unistd.h>
/*inputbuf and inbuf string is use to take the input from the user for command line argument 
 *parameter is use to hold the value of no of parameter(argument) given by the user along with command
 *ix,ide,ind_1,ind_2 these are use as index values for the string and array and res is use to store the return value of the called function 
 * mor2 is the int variable use when the are more than 2 output value need to be return back to the user
 * con int variable is use to hold the value after converting them from character to interger argu_1 and argu_2 are use to store the arguments after the command name in the input string*/
/*here struct para hold the different parameter of the Uc like temp,pressure in which some are int,char type etc var is structure variable and struct led is also use for same purpose*/
/* struct command consts of four members like 1)name of the command 2)help description related to the command 3)function pointer which point to command interpreter function which use to process the command 4)para is the no of parameter required by the command*/
/* struct param is use to store the parameter value as per the command and struct login is use to hold correct user id and pass*/
struct command
{
        char name[10];
        char help[55];
        int (*f_c)(const char pur[],int);
        int para;
};
struct led
{
	char led1[5];
	char led2[5];
	char led3[5];
	char led4[5];
	char led5[5];
};
struct param
{
	int temp;
	int press;
	struct led *lh;
};
struct login
{
        char *id;
        char *pass;
};
extern struct command *head;
extern unsigned char regist_command;
static unsigned char mor2=5;
int command_inter(const char pur[],int);
int get_parameter(char inputbuf[]);
 void process(char *);
int register_command(char *,int );

