//program consist of subroutine which were based on string manupulation//
#include<stdio_ext.h>
#include<stdlib.h>
/*write your own string compare function which is predifined library function*/
/*write your own string copy function which is predifined library function*/
/*write your own string length function which is predifined library function*/

/*....................string length function  which return no of chararcter in the given input string..........*/
int mstrlen(char *p)
{
	int i=0;
	while(*p++!='\0')
		i++;
	return i;	
}
/*....................string copy function from source to destionation..........*/
char *mstrcpy(char strd[],char strs[])// string strd represent destination string and strs represent source string
{
	int a=0;
	while(strd[a]=strs[a])
		a++;
	return strd;
}

/*...................string compare function used to check and return 0 for identical string and return non zero for unsimilar string....................*/
int mstrcmp(char str1[],char str2[])
{
	int i=0;
	while(str1[i]!='\0' && str2[i]!='\0')
	{
		if(str1[i]!=str2[i])
			return str1[i]-str2[i];
		i++;
	}
	return 0;
}

/*......................str1 string will be concatinated with string str2 and a pointer to the str1 will be return............*/
char *mcatstr(char str1[],char str2[])
{
	int a=0,i=0;
	while(str1[a]!=0)
		a++;
	while(str2[i]!=0)
	{
		str1[a]=str2[i];
		a++,i++;
	}
	str1[a]=str2[i];
	return str1;
}
void main(void)
{
		int opt,a;	
		char str1[15],str2[15],*cp;
	while(1)
	{
		printf("enter the option for string operaation on the entered strings\n 0. for termination of the process\n 1. for getting lenght of the string 2. for copying the one string into another string copy 3.to compare two given string as they were same or not\n 4. to append or concadinate the first string with the second string....\n ");
		scanf("%d",&opt);
		__fpurge(stdin);
		switch(opt)
		{
			case 0:exit(0);
			case 1:printf("the string for getting the no  of the chararcter in it\n");
			       scanf("%s",str1);
			       __fpurge(stdin);
			       a=mstrlen(str1);
			       printf("the no of chararcter present in the string are %d\n",a);
			       break;
			case 2:printf("enter the source string to copy in the second string...\n ");
			       scanf("%[^\n]s",str1);
			       __fpurge(stdin);
			       cp= mstrcpy(str2,str1);
			       printf("string after copying is %s\n",cp);
			       break;
			case 3:printf("enter two string in string-string format for comparartion\n");
			       scanf("%s %s",str1,str2);
			       __fpurge(stdin);
			       a=mstrcmp(str1,str2);
			       if(a==0)
				       printf("entered two strings are similar\n");
			       else 
				       printf("entered string are not similar\n");
			       break;
			case 4:printf("entered two string in string-string format to be concadinate\n");
			       scanf("%s %s",str1,str2);
			       __fpurge(stdin);
			       printf("string 1 %s and string 2 is %s before concadinate\n",str1,str2);
			       mcatstr(str1,str2);
			       printf("string 1 %s and string 2 is %s after concadinate\n",str1,str2);
			       break;
			default:printf("invalid opt\n");
		}

	}

}




