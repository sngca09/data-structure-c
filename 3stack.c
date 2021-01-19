#include<stdlib.h>
#include<stdio.h>
struct sta
{
    int num;
    struct sta *nxt;
};struct sta *TOP=NULL;
void push()
{
    struct sta *new=(struct sta*)malloc(sizeof(struct sta));
    if(new==NULL)
    {
        printf("stack is full");
        return;
    }
    else
    {
        printf("enter the element to push");
        scanf("%d",&new->num);
        new->nxt=TOP;
        TOP=new;
    }
}
void pop()
{
    struct sta *ptr;
    if(TOP==NULL)
    {
        printf("stack is empty");
        return;
    }
    printf("the deleted element(poped) is %d",TOP->num);
    ptr=TOP;
    TOP=TOP->nxt;
    free(ptr);
}
void display()
{
    struct sta *ptr=TOP;
    if(TOP==NULL)
    {
        printf("stack is empty");
        return;
    }
    ptr=TOP;
    printf("the elements in stack are\n");
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->num);
        ptr=ptr->nxt;
    }
}
void search()
{
    struct sta *ptr;
    int y,pos=1;
    if(TOP==NULL)
    {
        printf("empty stack");
        return;
    }
    ptr=TOP;
    printf("enter the element to be searched");
    scanf("%d",&y);
    while(ptr!=NULL)
    {
        if(ptr->num==y)
        {
            printf("the element  found at the position %d from top",pos);
            break;
        }
        ptr=ptr->nxt;
        pos++;
    }
    if(ptr==NULL)
    {
        printf("element not found in the stack");
    }
    
}

int main()
{
int choice;
do
{
printf("\nenter a choice \n1.push \n 2.pop\n 3.traverse and display\n 4.search\n5.exit");
scanf("%d",&choice);
switch(choice)
{
case 1 :
push();
break;
case 2 :
pop();
break;
case 3:
display();
break;
case 4:
search();
break;
case 5:
return 0;
break;
default:
printf("check your choice");
break;
}
}while(choice!=5);
}
