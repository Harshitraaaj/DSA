#include<stdio.h> 
#include<stdlib.h> 
struct Employee 
{ 
 char SSN[10]; 
  char Name[10]; 
  char Branch[10]; 
  char Des[10]; 
  char sal[10]; 
  char phone[10]; 
}; 
typedef struct Employee EMP; 
struct node 
{ 
 EMP info; 
 struct node *lptr,*rptr; 
}; 
typedef struct node* Node; 
Node front=NULL,rear=NULL; 
EMP GetRec() 
{ 
 EMP temp; 
 printf("Enter the SSN: "); 
  fflush(stdin); 
 gets(temp.SSN); 
printf("Enter the Name:"); 
 fflush(stdin); 
 gets(temp.Name); 
 printf("Enter branch:"); 
 fflush(stdin); 
 gets(temp.Branch); 
 printf("Enter the designation: "); 
 fflush(stdin); 
 gets(temp.Des); 
 printf("Enter sal:"); 
 fflush(stdin); 
 gets(temp.sal); 
 printf("Enter the phone number:"); 
 fflush(stdin); 
 gets(temp.phone); 
 return temp; 
} 
void DispRec(EMP temp) 
{ 
 printf("%s\t",temp.SSN); 
 printf("%s\t\t",temp.Name); 
 printf("%s\t\t",temp.Branch); 
 printf("%s\t\t",temp.Des); 
 printf("%s\t\t",temp.sal); 
 printf("%s\n",temp.phone); 
} 
Node Create(EMP ele) 
{ 
 Node temp; 
 temp=(Node)malloc(sizeof(struct node)); 
 temp->info=ele; 
 temp->lptr=NULL; 
 temp->rptr=NULL;
 return temp; 
} 
void Finsert(EMP ele) 
{ 
 Node temp=Create(ele); 
 if(front== NULL) 
 { 
  front=temp; 
  rear=temp; 
 } 
 else 
 { 
  temp->rptr=front; 
  front->lptr=temp; 
  front = temp; 
 } 
} 
void Einsert(EMP ele) 
{ 
 Node temp=Create(ele); 
 if(rear == NULL) 
 { 
  front=temp; 
  rear=temp; 
 } 
 else 
 { 
  rear->rptr=temp; 
  temp->lptr=rear; 
  rear=temp; 
 } 
} 
void Fdelete()
{ 
 Node temp=front; 
 if(front == NULL) 
  printf("\nList is empty"); 
 else 
 { 
  temp=front; 
  printf("\nDeleted Employee Records \n"); 
  DispRec(temp->info); 
  front = front->rptr; 
  front->lptr= NULL; 
  if(front == NULL) 
   rear = NULL; 
  free(temp); 
 } 
} 
void Edelete() 
{ 
 Node temp=rear,t; 
 if(rear== NULL) 
  printf("\nList is empty"); 
 else if(rear->lptr == NULL) 
 { 
  printf("\nDeleted Employee Records \n"); 
  DispRec(rear->info); 
  front=rear=NULL; 
  free(temp); 
 } 
 else 
 {  
  rear = rear->lptr; 
  rear->rptr=NULL; 
  printf("\nDeleted Employee Records \n");
  DispRec(temp->info); 
  free(temp); 
 } 
} 
void display(Node front) 
{ 
 Node temp=front; 
 if(temp == NULL) 
  printf("\nList is empty\n"); 
 else 
 { 
  printf("\nEmployee Records list\n"); 
  printf("SSL\t\tName\t\tBranch\tdesignation\tPhno\n"); 
  while(temp!=NULL) 
  { 
   DispRec(temp->info); 
   temp=temp->rptr; 
  } 
 } 
} 
void main() 
{ 
 EMP ele; 
 int flag=1,ch; 
 while(flag) 
 { 
  printf("\n Menu Implementation of Double Ended Queue using DLL\n"); 
  printf("\n1 Insert Front \n2 Insert rear \n3 Delete Front \n4 Delete Rear \n5 Display\n"); 
  printf("6 Exit\n Enter the Choice"); 
  scanf("%d",&ch); 
  switch(ch) 
  { 
    case 1: printf("\n Enter the Employee Record to Insert Front of Queue\n"); 
     ele = GetRec(); 
     Finsert(ele); 
     break; 
   case 2: printf("\n Enter the Employee Record to Insert Front of Queue\n"); 
     ele=GetRec(); 
     Einsert(ele); 
     break; 
   case 3: Fdelete(); 
     break; 
   case 4: Edelete(); 
     break; 
   case 5: display(front); 
     break; 
   default: flag = 0; 
  } 
 }  
}
