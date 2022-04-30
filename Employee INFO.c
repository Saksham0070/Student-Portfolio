/*
1. (a) Write a program that can take employee name, emp id and salary as user input
create a linked list (for 5 employees). Allow user to insert a new employee in the list
and delete an existing employee from list (at any position).
(b) Create a sorted link list with employee data and allow user to perform insertion of
new employee (maintaining the sorted sequence).
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
  float salary;
  char name[100];
  char id[100];
  struct node *link;
};

struct node *head;

void insert_at_beg(int pos,struct node *newemp,struct node *ptr);     //function prototype

            //   FOR DISPLAYING THE DATAS ............

void display(){

 struct node *temp = head;

 int i=1;
 printf("\nAll the Employees information are like that \n\n");

  while(temp!=NULL){

    printf("Employee %d name = %s\n",i,temp->name);
    printf("Employee %d id = %s\n",i,temp->id);
    printf("Employee %d salary = %.2f\n",i,temp->salary);

    printf("\n");
    temp = temp->link;
    i++;

  }
      printf("\n-----------------------------------------------------------\n");
}

     //       FOR INSERTING THE DATAS AT ANY POSITION ..........

void insert(){

   struct node *ptr=head;

  struct node *newemp=malloc(sizeof(struct node));

  int pos;

  printf("Enter the position in which you want to enter\n" );
  scanf("%d",&pos);

  if(pos==1){

    insert_at_beg(pos,newemp,ptr);

  }
  else{
  printf("Enter new employee name\n");
  scanf("%s",newemp->name );
  printf("Enter new employee id\n");
  scanf("%s",newemp->id);
  printf("Enter new employee salary \n");
  scanf("%f",&newemp->salary );

  newemp->link = NULL;

  pos--;

  while(pos!=1){
    ptr=ptr->link;
    pos--;
  }
  newemp->link = ptr->link;
  ptr->link = newemp;
}
     }

//              FOR INSERTING NEW DATAS IN THE BEGGINING..............

void insert_at_beg(int pos,struct node *newemp,struct node *ptr){

  printf("Enter new employee name\n");
  scanf("%s",newemp->name );
  printf("Enter new employee id\n");
  scanf("%s",newemp->id);
  printf("Enter new employee salary \n");
  scanf("%f",&newemp->salary );

  newemp->link = NULL;
  newemp->link = ptr;
  ptr = newemp;
  head=ptr;

}

//     FOR DELETING THE DATAS ..........

void delete(){

 int pos1, pos2;

   struct node *temp = head;
   struct node *temp1 = head;
   struct node *temp2 = head;

   printf("Enter the poistion which you want to delete\n ");
    scanf("%d",&pos1);

    pos2=pos1;
    pos2--;

   if(pos1==1){
     free(temp);
     temp = NULL;
     head = head->link;              //To traverse the list from 1st node to 2nd node
   }
   else{
    while(pos2!=1){
      temp=temp->link;
      pos2--;
    }
    temp1 = temp->link;
    temp2 = temp1->link;
    free(temp1);
    temp1 = NULL;
    temp->link = temp2;
  }
}

 //    FOR SORTING OF DATAS BASED ON THEIR SALARY IN ASCENDING ORDER..........

void sort(struct node *head){

  struct node *temp=head;

   float salary;
   char name[100];
   char id[100];

  struct node *ptr;
  struct node *ptr1;

  for(ptr=head;ptr!=NULL;ptr=ptr->link)
    {
       for(ptr1=ptr->link;ptr1!=NULL;ptr1=ptr1->link)
       {
          if(ptr->salary > ptr1->salary)
          {
              strcpy(name,ptr->name);
              strcpy(ptr->name,ptr1->name);
              strcpy(ptr1->name,name);

              salary=ptr->salary;
              ptr->salary=ptr1->salary;
              ptr1->salary=salary;

              strcpy(id,ptr->id);
              strcpy(ptr->id,ptr1->id);
              strcpy(ptr1->id,id);
          }
       }
    }
  }

int main(){

  head=NULL;
  float salary;
  char name[100];
  char id[100];
  int n , choice;

  printf("Enter number of employees\n");
  scanf("%d",&n);

for(int i=1;i<=n;i++){
  printf("Enter the name of employee \n");
  scanf("%s",name);
  printf("Enter the id of employee \n");
  scanf("%s",id);
  printf("Enter the salary of employee \n");
  scanf("%f",&salary);

  struct node *ptr=malloc(sizeof(struct node));

  strcpy(ptr->name,name);
  strcpy(ptr->id,id);
  ptr->salary = salary;

  ptr->link = NULL;

  if(head==NULL){
    head = ptr;

    }
    else{
      ptr->link = head;
      head = ptr;
    }

  printf("\n");

       }

   display();

   do{

     printf("\n 1. for sorting \n 2. for inserting any employee in the list \n 3. for deleting any employee from the list \n Press 0 for EXIT\n");
     printf("\nEnter your choice\n");
     scanf("%d",&choice);

     switch(choice){

       case 1:
      printf("\n-------------------SORTED INFORMATION-------------------------------\n");
      sort(head);
      display();
       break;

       case 2:
       insert();
      printf("\n-------------------NEW INFORMATION AFTER INSERTING------------------\n");
       display();
       break;

       case 3:
      delete();
      printf("\n-------------------NEW INFORMATION AFTER DELETING------------------\n");
      display();
       break;

     }
   }while(choice!=0);
  }
