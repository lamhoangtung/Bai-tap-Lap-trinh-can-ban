#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <cstring>

struct contact{
  char name[30];
  long phone_number;
  char email[30];
}temp;

/*
void addContact(){
  temp = (struct contact) {"",0,""};
  printf("\n\t\tAdding a new contact:\n\n");
  printf("\t\tName: ");
  scanf(" %[^\n]%*c",temp.name);
  printf("\t\tPhone number: ");
  scanf("%ld",&temp.phone_number);
  printf("\t\tEmail: ");
  scanf("%s",&temp.email);
  //database = fopen("database.txt","a");
  fprintf(database,"%s|%ld|%s\n",temp.name,temp.phone_number,temp.email);
  printf("\n\t\tAdded %s to the contact book.",temp.name);
}
*/

void listContact(FILE *database){
  //database = fopen("database.txt","r");
  char savedData[100];
  //printf("\t\t%s\n",savedData);
  int id=0;
  while(1){
    fscanf(database," %[^\n]%*c",savedData);
    int begin=0,end;
    id++;
    printf("\t\t%i\t",id);
    for (int i=0;i<strlen(savedData);i++){
      if (savedData[i]=='|'){
        end=i-1;
        for (int j=begin;j<=end;j++){
          printf("%c",savedData[j]);
        }
        begin=i+1;
        printf("\t");
      }
    }
    end=strlen(savedData)-1;
    for (int j=begin;j<=end;j++){
      printf("%c",savedData[j]);
    }
    printf("\n");
    if (id==4) break;
  }
}

int main(){
  //Init contact book database
  FILE *database;
  database = fopen("database.txt","a");
  if (database==NULL){
    printf("\t\tWe could not open or create the database! Please try to run the program again.\n\n");
    return 0;
  }

  //Main menu
  int choice;
  printf("\n\t **** Welcome to T3-KHMT1-K12 Contact Manager ****");
  while (1){
    printf("\n\n\n\t\t\tMAIN MENU\n\t\t=====================\n\t\t[1] Add a new");
    printf(" Contact\n\t\t[2] List all Contacts\n\t\t[3] Search for contact\n\t\t[4] Edit");
    printf(" a Contact\n\t\t[5] Delete a Contact\n\t\t[0] Exit\n\t\t=================\n\t\t");
    printf("Enter the choice: ");
    scanf("%i",&choice);
    while (choice<0||choice>5){
      printf("\n\n\t\tInvalid number, please enter the choice again: ");
      scanf("%i",&choice);
    }

    switch (choice) {
      case 0: printf("\n\n\t\tAre you sure u want to exit? Confirm with Y/N: ");
              char confirm;
              scanf(" %c",&confirm);
              while (confirm!='y' && confirm!='Y' && confirm!='n' && confirm!='N'){
                printf("\n\n\t\tInvalid Input! Are you sure u want to exit? Confirm with Y/N: ");
                scanf(" %c",&confirm);
              }
              if (confirm=='y'||confirm=='Y'){
                printf("\n\n\t\tExiting .... Thanks for using our Contact Manager!\n\n");
                fclose(database);
                return 0;
              } else break;

      case 1: temp = (struct contact) {"",0,""};
              printf("\n\t\tAdding a new contact:\n\n");
              printf("\t\tName: ");
              scanf(" %[^\n]%*c",temp.name);
              printf("\t\tPhone number: ");
              scanf("%ld",&temp.phone_number);
              printf("\t\tEmail: ");
              scanf("%s",&temp.email);
              //database = fopen("database.txt","a");
              fprintf(database,"%s|%ld|%s\n",temp.name,temp.phone_number,temp.email);
              printf("\n\t\tAdded %s to the contact book.",temp.name);
              break;

      case 2: database = fopen("database.txt","r");
              listContact(database);
              break;
      case 3: printf("\n\n\t\tPlease type in something to search: ");
              //char query[30];
              //scanf("%s",&query);
              break;
      case 4: printf("\n\n\t\tPlease type in the ID of the contact: ");
              //int id;
              //scanf("%i",&id);
              //editContact(id);
              break;
      case 5: printf("\n\n\t\tPlease type in the ID of the contact: ");
              //int id;
              //scanf("%i",&id);
              //editContact(id);
              break;
    }
  }
  fclose(database);
  return 0;
}
