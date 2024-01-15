#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct node 
{
  int data;
  struct node *left,*right;
};
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
void push(struct node *temp)
 {
   if(isfull())
   printf("stack is full dont push...");
   else
   {
     s.top++;
      s.data[s.top]=temp;
   }
 }

struct node *pop()
{
  struct node *temp;
 if(isempty())
  printf("stack is empty dont pop...");
  else
  {
     temp=s.data[s.top];
      s.top--;
  }
   return temp;
}

struct node *create(struct node *root)
 {
  int i,n;
  struct node *newnode,*temp,*parent;
  printf("enter limit:");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    newnode=(struct node*)malloc(sizeof(struct node));
     printf("enter value:");
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
            if(newnode->data<temp->data)
             temp=temp->left;
            else
            temp=temp->right;
        }
         if(newnode->data<parent->data)
           parent->left=newnode;
         else
           parent->right=newnode;
  }
    return root;
  }

struct node *insert(struct node *root,int num)
 {
   struct node *newnode,*parent,*temp;
   newnode=(struct node*)malloc(sizeof(struct node));
     newnode->data=num;
      newnode->left=NULL;
       newnode->right=NULL;
      if(root==NULL)
      {
         root=newnode;
      }
      temp=root;
      while(temp!=NULL)
      {
        parent=temp;
           if(newnode->data<temp->data)
           temp=temp->left;
           else
            temp=temp->right;
      }
      if(newnode->data<parent->data)
           parent->left=newnode;
      else
       parent->right=newnode;
     return root;
}

void inorder(struct node *root)
 {
   struct node *temp=root;
    if(temp!=NULL)
    {
      inorder(temp->left);
       printf("%d\t",temp->data);
       inorder(temp->right);
  }
 }

void preorder(struct node *root)
 {
   struct node *temp=root;
    if(temp!=NULL)
    {
        printf("%d\t",temp->data);
      inorder(temp->left);       
       inorder(temp->right);
  }
 }

void postorder(struct node *root)
 {
   struct node *temp=root;
    if(temp!=NULL)
    {
      inorder(temp->left);       
       inorder(temp->right);
       printf("%d\t",temp->data);
  }
 }

void nonrinorder(struct node *root)
 {
  struct node *temp=root;
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

void leafnode(struct node *root)
 {
 struct node *temp=root;
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

void cntleaf(struct node *root)
{
struct node *temp=root;
  int cnt=0;
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
        cnt++;
     }
     temp=temp->right;
       while(temp!=NULL)
       {
          push(temp);
          temp=temp->left;
       }
 }
 printf("counted leaf node=%d",cnt);

}
int main()
{
 struct node *root=NULL;
  int num,ch;
  init();
  do{
    printf("\n1-create\n2-insert\n3-inorder\n4-preorder");
    printf("\n5-postorder\n6-without recursion display");
    printf("\n7-display leafnode\n8-count leafnode");
     printf("\nenter choice:");
      scanf("%d",&ch);
    switch(ch)
   {
     case 1: root=create(root);
              break;
     case 2: printf("enter no to insert:");
             scanf("%d",&num);
             root=insert(root,num);
               break;
      case 3: inorder(root);
               break;
      case 4: preorder(root);
               break;
      case 5: postorder(root);
               break;
       case 6: nonrinorder(root);
               break;
       case 7: leafnode(root);
                 break;
       case 8: cntleaf(root);
               break;

   }

   }while(ch<9);

}
