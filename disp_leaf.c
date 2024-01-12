#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct node
{
	int data;
	struct node *left,*right;
}NODE;
struct stack
{
	struct node *data[MAX];
	int top;
}s;
void init()
{
	s.top=-1;
}
int isempty()
{
	if(s.top==-1)
	  return 1;
	else
	  return 0;
}
int isfull()
{
	if(s.top==MAX-1)
	return 1;
	else
	return 0;
	
}
void push(NODE *temp)
{
	if(isfull())
	 printf("Stack is full..");
	else
	{
		s.top++;
		s.data[s.top]=temp;
	}
}
NODE *pop()
{
	struct node *temp;
	if(isempty())
	printf("Stack is empty");
	else
	{
		temp=s.data[s.top];
		s.top--;
	}
 return temp;
}
NODE *create(NODE *root)
{
	NODE *newnode,*temp,*parent;
	int i,n;
	printf("Enter the Limit:");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
    {
    
    	newnode=(NODE *)malloc(sizeof(NODE));
     printf("\nEnter Elements :");
    	scanf("%d",&newnode->data);
    	newnode->left=NULL;
    	newnode->right=NULL;
    	if(root==NULL)
    	{
    		root=newnode;
    		continue;
		}
		temp=root;
		while(temp!=NULL)
		{
			parent=temp;
			if(newnode->data < temp->data)
			temp=temp->left;
			else
			 temp=temp->right;
		}
		if(newnode->data < parent->data)
		 parent->left=newnode;
		else
		  parent->right=newnode;
	}
	return root;
}
void inorder(NODE *root)
{
	NODE *temp=root;
	while(temp!=NULL)
	{
		push(temp);
		temp=temp->left;
	}
	while(!isempty())
	{
		temp=pop();
		printf("%d\t",temp->data);
		temp=temp->right;
		while(temp!=NULL)
		{
			push(temp);
			temp=temp->left;
		}
	}
}
NODE *disp_leaf(NODE *root)
{
	
	NODE *temp=root;
	while(temp!=NULL)
	{
		push(temp);
		temp=temp->left;
	}
	while(!isempty())
	{
		temp=pop();
		if(temp->left==NULL && temp->right==NULL)
		{
			printf("%d\t",temp->data);
		}
		temp=temp->right;
		while(temp!=NULL)
		{
			push(temp);
			temp=temp->left;
		}
	}
}
int main()
{
	NODE *root=NULL;
 init();
	root=create(root);
	
	printf("\n Display Using INORDER =");
	inorder(root);
	
	printf("\n Leaf NOdes =");
	disp_leaf(root);
	
	
}
