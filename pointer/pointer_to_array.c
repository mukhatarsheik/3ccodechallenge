#include<stdio.h>
#include<stdlib.h>
int main()
{
	int mag[2][3]={{5,10,15},{70,75,80}},r,e;//r mean row of 2d,e mean no of elemnet in a row matrix
	/*for(r=0;r<2;r++)
		for(e=0;e<3;e++)
		{
			printf("enter the element for row %d and element is %d\n",r+1,e+1);
			scanf("%d",&mag[r][e]);//mag[r]+e,*(mag+r)+e
		}*/
	for(r=0;r<2;r++)
		for(e=0;e<3;e++)
		{
			printf("the sizeof  the 2d array is %d\n",sizeof(mag));
			printf("the element are %d\n",mag[r][e]);//*(mag[r]+e),*(*(mag+r)+e)
		}
			printf("the sizeof  the 2d array row 1 is %d\n",sizeof(mag[0]));
			printf("the sizeof  the 2d array row 2  is %d\n",sizeof(mag[1]));
	int (*ptrarr)[3]=&mag;
	printf("the sizeof ptrarr[0] is %d\n",sizeof(ptrarr[0]));
	for(r=0;r<2;r++)
		for(e=0;e<3;e++)
		printf("the ptrarr[%d]\n element is %d\n",r+1,ptrarr[r][e]);

}
