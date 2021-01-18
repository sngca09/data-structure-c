#include<stdio.h>
int rear=-1;
int front=-1;
int maxcq=5;
int cq[10];
void insert()
{
    int iteam;
    printf("enter an iteam");
    scanf("%d",&iteam);
    if(front==(rear+1)%maxcq)
    {
    printf("circular queue is full");
    return;
    }
if(front == -1)
{
front = 0;
rear = 0;
}
else
{
if(rear == maxcq-1)
rear = 0;
else
rear = rear+1;
}
cq[rear] = iteam ;
}
void deletion()
{
if(front == -1)
{
printf("Queue is Underflow");
return ;
}
printf("Element deleted from queue is : %d",cq[front]);
if(front == rear)
{
front = -1;
rear=-1;
}
else
{
if(front == maxcq-1)
front = 0;
else
front = front+1;
}
}
void display()
{
int front_pos = front,rear_pos = rear;
if(front == -1)
{
printf("Queue is empty");
return;
}
printf("Queue elements :");
if( front_pos <= rear_pos )
while(front_pos <= rear_pos)
{
printf("%d ",cq[front_pos]);
front_pos++;
}
else
{
while(front_pos <= maxcq-1)
{
printf("%d ",cq[front_pos]);
front_pos++;
}
front_pos = 0;
while(front_pos <= rear_pos)
{
printf("%d ",cq[front_pos]);
front_pos++;
}
}
}
void search()
{
    int n,f=front,pos,i;
    pos=1;
    printf("enter the Element to be searched");
    scanf("%d",&n);
    if(front==-1)
    {
    printf("cq is underflow there is no elements in it");
    }
    else
   while(f<maxcq)
   {
        if(cq[f]==n)
        {
            printf("element found at the position %d",f+1);
            break;
        }
      else if (front==rear)
          {
              printf("Element not found");
              break;
          }
 f=(f+1)%maxcq;      pos=pos+1;
          }
}
int main()
{
int choice,item;
do
{
printf("\nenter a choice \n1.insert \n 2.delete\n 3.display\n 4.search\n5.exit");
scanf("%d",&choice);
switch(choice)
{
case 1 :
insert(item);
break;
case 2 :
deletion();
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
return 0;
}
