#include<stdlib.h>
#include<stdio_ext.h>
struct selref{
	int data;
	struct selref *link;
};
void add_afternode(int);
void add_beforenode(int);
void del_beforenode();
void del_afternode();
void display();
struct selref *head=NULL;
void main()
{
	while(1)
	{
		int val,opt;
		printf("type 0 for exit the process........\n 1 for add a node after other or to create......\n 2 for add a node before the exiting node or to create a node......\n 3 delete the node at the last.......\n 4 delete the node at first(first node)......\n 5 display the list with all node....\n ");
		printf("enter the option for given operation on single linked list\n");
		scanf("%d",&opt);
		switch(opt)
		{
			case 0:exit(0);
			       break;
			case 1:printf("enter the val for the node\n");
			       scanf("%d",&val);
			       __fpurge(stdin);
			       add_afternode(val);
			       break;
			case 2:printf("enter the val for the node\n");
                               scanf("%d",&val);
                               __fpurge(stdin);
			       add_beforenode(val);
			       break;
			case 3:del_afternode();
			       break;
			case 4:del_beforenode();
			       break;
			case 5:display();
			       break;
			default:printf("invalid option type again\n");
		}
	}
}
void add_afternode(int val)
{
	struct selref *temp;
		struct selref *sptr=(struct selref *)malloc(1*sizeof(struct selref));
		if(sptr==NULL)
		{
			printf("fail to allocate memory dynamically\n");
			return;
		}
			sptr->data=val;
			sptr->link=NULL;
		if(head==NULL)
		{
			head=sptr;
			return;
		}
		temp=head;
		while(temp->link!=NULL)
		{
			temp=temp->link;
		}
		temp->link=sptr;

}
void add_beforenode(int val)
{
	struct selref *temp;
		struct selref *sptr=(struct selref *)malloc(1*sizeof(struct selref));
		if(sptr==NULL)
		{
			printf("fail to allocate memory dynamically\n");
			return;
		}
			sptr->data=val;
			sptr->link=NULL;
		if(head==NULL)
		{
			head=sptr;
			return;
		}
		temp=head;
		head=sptr;
		sptr->link=temp;

}
void display()
{
	int i=0;
	struct selref *temp;
	if(head==NULL)
	{
		printf("the link is empty\n");
		return;
	}
	temp=head;
	while(temp!=NULL)
	{
		printf("the node %d data is %d  ",i,temp->data);
		printf("the node %d link for next node is %p\n",i,temp->link);
		i++;
		temp=temp->link;
	}

}
void del_beforenode()
{
	printf("here we deleting the first node of the linked list\n");
	struct selref *temp=head;
	if(head==NULL)
	{
		printf("list is empty\n");
		return;
	}
	head=head->link;
	free(temp);
}
void del_afternode()
{
	printf("here we deleting the last node of the linked list\n");
	struct selref *temp=head,*p1;
	if(head==NULL)
	{
		printf("list is empty\n");
		return;
	}
	if(head->link==NULL)
	{
		head=NULL;
		free(temp);
		return;
	}
	while(temp->link!=NULL)
	{
		p1=temp;
		temp=temp->link;
	}
	p1->link=NULL;
	free(temp);
}
