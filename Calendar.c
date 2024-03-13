#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
struct fields 
{ 
 char *Day_Name; 
 int Day_Date; 
 char *Discription; 
}; 
typedef struct fields Fields; 
Fields **Activity; 
Fields *Create(char *Name,int Day,char *Disc) 
{ 
 Fields *data; 
 int nlen,nDisc; 
 nlen=strlen(Name); 
 nDisc=strlen(Disc); 
 data = (Fields *)malloc(sizeof(struct fields)); 
 data->Day_Name=(char *)calloc(nlen,sizeof(char)); 
 data->Discription =(char *)calloc(nDisc,sizeof(char)); 
 data->Day_Date=Day; 
 strcpy(data->Day_Name,Name); 
 strcpy(data->Discription,Disc); 
 return data; 
}
void readData() 
{ 
 char Name[10],Disc[25]; 
 int Day,i; 
 Activity = (Fields **)calloc(7,sizeof(Fields *)); 
 printf("\n Enter the calendar details \n"); 
 for(i=0;i<7;i++)   { 
  printf("Enter the Week Name\t"); 
  gets(Name); 
  printf("Enter the Week Discription\t"); 
  gets(Disc); 
  printf("Enter the Week Day\t"); 
  scanf("%d",&Day); 
  Activity[i]=Create(Name,Day,Disc); 
  fflush(stdin); 
 } 
} 
void display() { 
 int i; 
 printf("\n Week Name\t\t Day  \t Discription\n"); 
 for(i=0;i<7;i++) 
 { 
  printf("%10s\t%d\t\t%s\n", 
                                 Activity[i]->Day_Name, 
                                 Activity[i]->Day_Date, 
                                 Activity[i]->Discription); 
 } 
} 
void main() { 
 readData(); 
 display(); 
}