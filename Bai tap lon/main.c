#include <stdio.h>
#include <math.h>
#include <string.h>

struct contact{
  char name[30];
  long phone_number;
  char email[30];
}temp;

FILE *database;

int countline(){
  database = fopen("database.txt","r");
  int lines=0;
  while (!feof(database)){
    char ch = fgetc(database);
    if(ch == '\n')
    {
      lines++;
    }
  }
  fclose(database);
  return lines;
}


void addContact(){
  temp = (struct contact) {"",0,""};
  printf("\n\t\tAdding a new contact:\n\n");
  printf("\t\tName: ");
  scanf(" %[^\n]%*c",temp.name);
  printf("\t\tPhone number: ");
  scanf("%ld",&temp.phone_number);
  printf("\t\tEmail: ");
  scanf("%s",&temp.email);
  database = fopen("database.txt","a");
  fprintf(database,"%s|%ld|%s\n",temp.name,temp.phone_number,temp.email);
  fclose(database);
  printf("\n\t\tAdded %s to the contact book.",temp.name);
}


void listContact(){
  int lines=countline();
  if (lines==0) printf("\n\t\tThere is no contact to display.");
  else {
    char savedData[100];
    int id=0;
    printf("\n\t\tThere are %i contacts in the contact book:\n\n",lines);
    database = fopen("database.txt","r");
    while(id<lines){
      fscanf(database," %[^\n]%*c",savedData);
      //printf("\t\t%s\n",savedData);
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
          printf("\t\t");
        }
      }
      end=strlen(savedData)-1;
      for (int j=begin;j<=end;j++) printf("%c",savedData[j]);
      printf("\n");
    }
    fclose(database);
  }
}

int main(){
  //Init contact book database
  FILE *database;
  database = fopen("database.txt","a");
  if (database==NULL){
    printf("\t\tWe could not open or create the database! Please try to run the program again.\n\n");
    return 0;
  } else fclose(database);

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
                scanf(" %c",&confirm);
                printf("\n\n\t\tInvalid Input! Are you sure u want to exit? Confirm with Y/N: ");
              }
              if (confirm=='y'||confirm=='Y'){
                printf("\n\n\t\tExiting .... Thanks for using our Contact Manager!\n\n");
                return 0;
              } else break;

      case 1: addContact();
              break;

      case 2: listContact();
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
  return 0;
}
