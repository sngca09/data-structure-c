#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *nxt;
}*head=NULL;
void insertb()
{
      struct node *ptr=(struct node*)malloc(sizeof(struct node));
	  printf("enter the element to be insert in the 1st position");
	  scanf("%d",&ptr->data);
	  ptr->prev=NULL;
	  ptr->nxt=NULL;

	  if(ptr==NULL)
	  {
		  printf("your dbly linked list is full");
		  return;
	  }
	 else if(head==NULL)
	  {
		  head=ptr;
		  return;
	  }
	 else
	 {
		 head->prev=ptr;
		 ptr->nxt=head;
		 head=ptr;
	 }		 
	  
	
}
void inspos()
{
	struct node *ptr=(struct node*)malloc(sizeof(struct node));
	struct node *h,*h1;
	int value;
	  printf("enter the element to be insert in a position");
	  scanf("%d",&ptr->data);
	  ptr->prev=NULL;
	  ptr->nxt=NULL;
	  if(ptr==NULL)
	  {
		  printf("your dbly linked list is full");
		  return;
	  }
	  else if(head==NULL)
	  {
		  head=ptr;
		  printf("element inserted at 1st pos");
		  return;
	  }
	  printf("enter a value,after which the node has to be inserted");
	  scanf("%d",&value);
	  h=head;
	  while(h->nxt!=NULL && h->data!=value)
	  {
		  h=h->nxt;
	  }
	  if(h->nxt==NULL)
	  {
		  h->nxt=ptr;
		  ptr->prev=h;
		  printf("element insereted at the last pos");
	  }
	  else
	  {
		  h1=h->nxt;
		  ptr->nxt=h1;
		  ptr->prev=h;
		  h->nxt=ptr;
		  h1->prev=ptr;
	  }	  

}
void inslst()
{
	struct node *ptr=(struct node*)malloc(sizeof(struct node));
	struct node *h;
	  printf("enter the element to be insert in the lst position");
	  scanf("%d",&ptr->data);
	  ptr->prev=NULL;
	  ptr->nxt=NULL;

	  if(ptr==NULL)
	  {
		  printf("your dbly linked list is full");
		  return;
	  }
	 else if(head==NULL)
	  {
		  head=ptr;
		  printf("enter the element at 1st pos");
		  return;
	  }
	  else
   {  h=head;
      while(h->nxt!=NULL)
      { h=h->nxt;
      }
      h->nxt=ptr;
      ptr->prev=h;
   }
}
void dltbeg()
{
struct node *h;
if(head==NULL)
{
	printf("the dblnls is empty");
	return;
}
h=head;
else
{
	h=head;
	printf("deleted element is=%d",h->data);
	head->prev=NULL;
	free(h);
}
}
void dltlst()
{
	struct node *h,*left;
	if(head==NULL)
	{
		printf("empty dblst");
		return;
	}
	else if(head->nxt==NULL)
	{
		free(head);
		head=NULL;
	}
	h=head->nxt;
	while(h->nxt!=NULL)
	{
		h=h->nxt;
	}
	left=h->prev;
	left->nxt=NULL;
	free(h);
}
void dltpos()
{
	struct node *h,*left,*right;
   int x;
   if (head==NULL)
	{ printf("\nlist is empty\n");
	  return;
	 }
    printf("Enter the element to delete: ");
    scanf("%d",&x);
    if (head->data==x)
		{ 
	    h=head;
	  head=h->nxt;
	  if (head!=NULL)
	  { 
       head->prev=NULL;
  }
	  free(h);
	  return;
	}

    h=head;
    while(h->data!=x && h->nxt!=NULL)
    { 
h=h->nxt;
    }
     if (h->data==x)
     {        right=h->nxt;
	  left=h->prev;
	  left->nxt=h->nxt;
	  if (right!=NULL)
	       right->prev=h->prev;
	   free(h);
	   return;
       }
	   else
      printf("\nElement not present in the list\n");
}
void search()
{  struct node *h;
int x;
  if (head==NULL)
       { printf("\nLinkedList Empty");
	  return;
	 }
   printf("Enter  element to search : ");
   scanf("%d",&x);
   h=head;
   while(h!=NULL)
   {  if (h->data==x)
      {   printf("\nElement present in the list\n");
	 break;
       }
       h=h->nxt;
    }
    if (h==NULL)
      printf("\n Element not in the List\n");
}



void display()
{
	struct node *ptr=head;
  if (head==NULL)
  { printf("\n dblnls is empty");
    return;
  }
  printf("The Elements in the dblnls are\n");
  while(ptr!=NULL)
  {  printf("%d\t",ptr->data);
     ptr=ptr->nxt;
   }

}




int main()
{
int choice,item;
do
{
printf("\nenter a choice \n1.inesert@begining \t 2.insert@pos\n 3.insert@last\t 4.delete@begning\n5.delete@pos\t 6.delete@lst\n 7.search element\t 8.dispaly\n 9.exit");
scanf("%d",&choice);
switch(choice)
{
case 1 :
insertb();
break;
case 2 :
inspos();
break;
case 3:
inslst();
break;
case 4:
dltbeg();
break;
case 5:
dltpos();
break;
case 6 :
dltlst();
break;
case 7:
search();
break;
case 8:
display();
break;
case 9:
return 0;
break;
default:
printf("check your choice");
break;
}
}while(choice!=9);
}