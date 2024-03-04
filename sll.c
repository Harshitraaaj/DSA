#include<stdio.h> 
#include<stdlib.h> 
struct student { 
 char USN[10]; 
 char Name[20]; 
 char Branch[15]; 
 char Sem[3]; 
 char PhNo[10]; 
}; 
typedef struct student STU; 
struct node { 
 STU info; 
 struct node *link; 
}; 
typedef struct node* Node; 
STU GetData() { 
  STU temp; 
  printf("Enter the usn: "); 
  fflush(stdin); 
  gets(temp.USN); 
  printf("\nEnter the Name:"); 
  fflush(stdin); 
  gets(temp.Name); 
  printf("\nEnter branch:"); 
  fflush(stdin); 
  gets(temp.Branch); 
   printf("\nEnter sem:"); 
  fflush(stdin); 
  gets(temp.Sem); 
  printf("\nEnter the phone number:"); 
  fflush(stdin); 
  gets(temp.PhNo); 
  return temp; 
} 
void displayRec(STU ele)  { 
 printf("\n%s\t\t",ele.USN); 
 printf("%s\t\t",ele.Name); 
 printf("%s\t",ele.Branch); 
 printf("%s\t",ele.Sem); 
 printf("%s\n",ele.PhNo); 
} 
Node Create(STU ele)  { 
 Node temp; 
 temp=(Node)malloc(sizeof(struct node)); 
 temp->info=ele; 
 temp->link=NULL; 
 return temp; 
} 
Node Finsert(Node first,STU ele)  { 
 Node temp=Create(ele); 
 if(first== NULL) 
  first=temp; 
 else 
 { 
  temp->link=first; 
  first = temp; 
 } 
 return first; 
} 
Node Einsert(Node first,STU ele) 
{ 
 Node temp=Create(ele),cur; 
 if(first== NULL) 
  first=temp; 
 else 
 { 
  //for(cur=first;cur->link!=NULL;cur=cur->link); 
  cur=first; 
  while(cur->link!=NULL) 
   cur=cur->link; 
  cur->link=temp; 
 } 
 return first; 
} 
void display(Node first) 
{ 
 Node temp=first; 
 if(temp == NULL) 
  printf("\nList is empty\n"); 
 else 
 { 
  printf("\nStudent Details in the list\n"); 
  printf("USN\t\tName\t\tBranch\tSem\tPhno\n"); 
  while(temp!=NULL) 
  { 
   displayRec(temp->info); 
   temp=temp->link; 
  } 
 } 
} 
int Count(Node first) 
{ 
 Node temp=first; 
 int cnt=0; 
 if(temp == NULL) 
  printf("\nList is empty\n"); 
 else 
 { 
  while(temp!=NULL) 
  { 
   cnt++; 
   temp=temp->link; 
  } 
 } 
 return cnt; 
} 
Node Fdelete(Node first) 
{ 
 Node temp=first; 
 if(first== NULL) 
  printf("\nList is empty"); 
 else 
 { 
  temp=first; 
  printf("\nElement Deleted is\n"); 
  printf("USN\t\tName\t\tBranch\tSem\tPhno\n"); 
  displayRec(temp->info); 
  first = first->link; 
  free(temp); 
 } 
 return first; 
}
Node Edelete(Node first) 
{ 
 Node temp=first,t; 
 if(first== NULL) 
  printf("\nList is empty"); 
 else if(first->link==NULL) 
 { 
  printf("\nElement Deleted is\n"); 
  printf("USN\t\tName\t\tBranch\tSem\tPhno\n"); 
  displayRec(first->info); 
  first=NULL; 
 } 
 else 
 { 
  //for(temp=first;temp->link->link!=NULL;temp=temp>link); 
  while(temp->link->link!=NULL) 
   temp=temp->link; 
  printf("\nElement Deleted is\n"); 
  printf("USN\t\tName\t\tBranch\tSem\tPhno\n"); 
  displayRec(temp->link->info); 
  t = temp->link; 
  temp->link=NULL; 
  free(t); 
 } 
 return first; 
}
void main() { 
 Node first=NULL; 
 int flag=1,ch; 
 STU ele; 
 while(flag)  { 
  printf("\n Menu \n"); 
  printf("\n1 Front Insert\n2 End Insert\n3 Front Delete\n4 End Delete\n5 Display\n6 No. of Nodes in the list\n"); 
  printf("7 Exit\n Enter the Choice"); 
  scanf("%d",&ch); 
  switch(ch)    { 
   case 1: printf("\n Enter the Student Details \t"); 
     ele=GetData(); 
     first=Finsert(first,ele); 
     break; 
   case 2: printf("\n Enter the Student Details \t"); 
     ele=GetData(); 
     first=Einsert(first,ele); 
     break; 
   case 3: first=Fdelete(first); 
     break; 
   case 4: first=Edelete(first); 
     break; 
   case 5: display(first); 
     break; 
   case 6: printf("\n the Number of Node in list %d\t",Count(first)); 
     break; 
   default: flag = 0; 
  } 
 }  
}
