#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define BUFFER_SIZE 1000

struct contact{
  char name[30];
  long phone_number;
  char email[30];
}temp;

FILE *database;

int getNumberofContact(){
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

struct contact getinfoContact(int id){
  struct contact temp = {"",0,""};
  database = fopen("database.txt","r");
  char data[100];
  for (int i=1;i<=id;i++){
    fscanf(database," %[^\n]%*c",data);
  }
  fclose(database);
  int i;
  for (i=0;data[i]!='|';i++){
    temp.name[i]=data[i];
  }
  i++;
  char phonenum[30];
  for (int j=0;data[i]!='|';i++,j++){
    phonenum[j]=data[i];
  }
  char *trash;
  temp.phone_number=strtol(phonenum,&trash,10);
  i++;
  for (int j=0;i<strlen(data);i++,j++){
    temp.email[j]=data[i];
  }
  return temp;
}

void replaceContact(struct contact input, int id){
  database = fopen("database.txt","r");
  FILE *tempFile;
  tempFile = fopen("replaced.tmp","a");
  if (database == NULL || tempFile == NULL){
    printf("\t\tWe are unable to open or create the necessary files! Please check you have read/write previleges and try to run the program again.\n\n");
    fclose(database);
    fclose(tempFile);
    exit(EXIT_FAILURE);
  }
  char newData[100];
  strcat(newData,input.name);
  strcat(newData,"|");
  char newPhonenum[30];
  sprintf(newPhonenum,"%ld",input.phone_number);
  strcat(newData,newPhonenum);
  strcat(newData,"|");
  strcat(newData,input.email);
  strcat(newData,"\n");
  int count=0;
  char buffer[BUFFER_SIZE];
  while ((fgets(buffer,BUFFER_SIZE,database)) != NULL){
    count++;
    fflush(stdin);
    if (count == id){
      fputs(newData,tempFile);
    }
    else fputs(buffer,tempFile);
  }
  fclose(database);
  fclose(tempFile);
  remove("database.txt");
  rename("replaced.tmp","database.txt");
}

void printContact(int id){
  struct contact temp = getinfoContact(id);
  printf("\t\t%i\t%s\t\t0%ld\t\t%s\n",id,temp.name,temp.phone_number,temp.email);
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
  int n=getNumberofContact();
  if (n==0) printf("\n\t\tThere is no contact to display.");
  else{
    char savedData[100];
    printf("\n\t\tThere are %i contacts in the contact book:\n\n",n);
    for (int id=1;id<=n;id++){
      printContact(id);
    }
  }
}

void searchContact(){
  printf("\n\n\t\tPlease type in something to search: ");
  char query[30];
  scanf(" %[^\n]%*c",query);
  for (int i=0;i<strlen(query);i++){
    query[i]=tolower(query[i]);
  }
  //printf("%s\n",query);
  int n=getNumberofContact();
  database = fopen("database.txt","r");
  for (int id=1;id<=n;id++){
    int flag;
    char savedData[100];
    fscanf(database," %[^\n]%*c",savedData);
    char preprocessedData[100];
    for (int i=0;i<strlen(savedData);i++){
      if (savedData[i]=='|'){
        preprocessedData[i]=' ';
      } else preprocessedData[i]=tolower(savedData[i]);
    }
    //printf("%s\n",preprocessedData);
    if (strstr(preprocessedData,query)!=NULL) printContact(id);
  }
  fclose(database);
}

void editContact(){
  printf("\n\n\t\tPlease type in the ID of the contact that you want to edit: ");
  int id;
  scanf("%i",&id);
  int n=getNumberofContact();
  if (id<=0||id>n){
    printf("\n\n\t\tID Invalid. Please double check and try again.");
  }
  else{
    struct contact temp = getinfoContact(id);
    int run=1;
    int flagName=0,flagPhonenum=0,flagEmail=0;
    char newName[30],newPhonenum[30],newEmail[30];
    while (run==1){
      printf("\n\n\t\tYou are editing %s. Type in the following number to edit:",temp.name);
      printf("\n\n\t\t\t[1]: Edit name");
      printf("\n\t\t\t[2]: Edit phone number");
      printf("\n\t\t\t[3]: Edit email");
      printf("\n\t\t\t[0]: Quit");
      printf("\n\n\t\tEnter the choice: ");
      int choice;
      scanf("%i",&choice);
      while (choice<0||choice>3){
        printf("\n\n\t\tInvalid choice, please enter the choice again: ");
        scanf("%i",&choice);
      }
      switch(choice){
        case 0: if (flagName==0 && flagPhonenum==0 && flagEmail==0){
                  printf("\n\n\t\tCanceled. Nothing have changed.");
                  run=0;
                }
                else{
                  printf("\n\n\t\tAre you sure you want to save the change ? Confirm with Y/N: ");
                  char confirm;
                  scanf(" %s",&confirm);
                  while (confirm!='y' && confirm!='Y' && confirm!='n' && confirm!='N'){
                    printf("\n\n\t\tInvalid Input! Are you sure you want to save the change ? Confirm with Y/N: ");
                    scanf(" %c",&confirm);
                  }
                  if (confirm=='y'||confirm=='Y'){
                    if (flagName!=0) strcpy(temp.name,newName);
                    if (flagPhonenum!=0){
                      char *trash;
                      temp.phone_number=strtol(newPhonenum,&trash,10);
                    }
                    if (flagEmail!=0) strcpy(temp.email,newEmail);
                    replaceContact(temp,id);
                    printf("\n\n\t\tAll changed saved!");
                    run=0;
                  }
                  else{
                    printf("\n\n\t\tCanceled. Nothing have changed.");
                    run=0;
                  }
                }
                break;
        case 1: printf("\n\n\t\tType in the new name: ");
                scanf(" %[^\n]%*c",newName);
                flagName++;
                break;
        case 2: printf("\n\n\t\tType in the new phone number: ");
                scanf(" %[^\n]%*c",newPhonenum);
                flagPhonenum++;
                break;
        case 3: printf("\n\n\t\tType in the new email: ");
                scanf(" %[^\n]%*c",newEmail);
                flagEmail++;
                break;
      }
    }
  }
}

void deleteContact(){
  printf("\n\n\t\tPlease type in the ID of the contact that you want to delete: ");
  int id;
  scanf("%i",&id);
  struct contact temp = getinfoContact(id);
  printf("\n\n\t\tAre you sure you want to delete %s ? Confirm with Y/N: ",temp.name);
  char confirm;
  scanf(" %c",&confirm);
  while (confirm!='y' && confirm!='Y' && confirm!='n' && confirm!='N'){
    printf("\n\n\t\tInvalid Input! Are you sure you want to delete %s ? Confirm with Y/N: ",temp.name);
    scanf(" %c",&confirm);
  }
  if (confirm=='y'||confirm=='Y'){
    database = fopen("database.txt","r");
    FILE *tempFile;
    tempFile = fopen("deleted.tmp","w");
    if (database == NULL || tempFile == NULL){
      printf("\t\tWe are unable to open or create the necessary files! Please check you have read/write previleges and try to run the program again.\n\n");
      fclose(database);
      fclose(tempFile);
      exit(EXIT_FAILURE);
    }
    char buffer[BUFFER_SIZE];
    int count = 1;
    while ((fgets(buffer,BUFFER_SIZE,database)) != NULL){
      if (id!=count) fputs(buffer,tempFile);
      count++;
    }
    fclose(database);
    fclose(tempFile);
    remove("database.txt");
    rename("deleted.tmp","database.txt");
    printf("\n\n\t\tDeleted contact %s",temp.name);
  }
  else{
    printf("\n\n\t\tCanceled. Nothing have changed.");
  }
}

int main(){
  //Init contact book database
  FILE *database;
  database = fopen("database.txt","a");
  if (database==NULL){
    printf("\t\tWe are unable to open or create the database! Please check you have read/write previleges and try to run the program again.\n\n");
    exit(EXIT_FAILURE);
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
      printf("\n\n\t\tInvalid choice, please enter the choice again: ");
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
                return 0;
              } else break;

      case 1: addContact();
              break;

      case 2: listContact();
              break;

      case 3: searchContact();
              break;

      case 4: editContact();
              break;

      case 5: deleteContact();
              break;
    }
  }
  return 0;
}
