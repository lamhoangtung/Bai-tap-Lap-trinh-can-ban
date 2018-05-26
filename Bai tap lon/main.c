#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//Define some common use variable
#define BUFFER_SIZE 1000
#define SHORT_STRING_SIZE 30
#define LONG_STRING_SIZE 100
#define DATA_BASE_FILE "database.txt"

//Define contact data structure
struct contact{
  char name[SHORT_STRING_SIZE];
  char phone_number[SHORT_STRING_SIZE];
  char email[SHORT_STRING_SIZE];
};

FILE *database;

//Return the number of contact stored in the database
int getNumberofContact(){
  database = fopen(DATA_BASE_FILE,"r");
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

//Standardize name by upper case any first alpha characters
char* inputName(){
  static char typed[SHORT_STRING_SIZE];
  scanf(" %[^\n]%*c",typed);
  int n=strlen(typed);
  for (int i=0;i<n;){
    if ((typed[i]==' ') && (typed[i+1]==' ')){
      for (int j=i+1;j<n;j++){
        typed[j]=typed[j+1];
      }
      n--;
    } else i++;
  }
  typed[0]=toupper(typed[0]);
  for (int i=1;i<strlen(typed);i++){
    if (isalpha(typed[i]) && typed[i-1]==' '){
      typed[i]=toupper(typed[i]);
    } else typed[i]=tolower(typed[i]);
  }
  return typed;
}

//Check a given string is a phone number or not
int checkPhoneNum(char *input){
  for (int i=0;i<strlen(input);i++){
    if (!isdigit(input[i]) && input[i]!=' '){
      return 0;
    }
  }
  return 1;
}

//Return the phone number typed by user
char* inputPhoneNum(){
  static char typed[SHORT_STRING_SIZE];
  scanf(" %[^\n]%*c",typed);
  while (checkPhoneNum(typed)==0){
    printf("\t\tThat's not a phone number. Please type in a phone number: ");
    scanf(" %[^\n]%*c",typed);
  }
  int n=strlen(typed);
  for (int i=0;i<n;){
    if ((typed[i]==' ') && (typed[i+1]==' ')){
      for (int j=i+1;j<n;j++){
        typed[j]=typed[j+1];
      }
      n--;
    } else i++;
  }
  return typed;
}

//Check a given string is a email or not
int checkEmail(char *input){
  int countDot=0,countA=0;
  for (int i=0;i<strlen(input);i++){
    if (input[i]=='.')  countDot++;
    else if (input[i]=='@') countA++;
  }
  if (countA==1 && countDot>=1) return 1;
  else return 0;
}

//Return the string email typed by user
char* inputEmail(){
  static char typed[SHORT_STRING_SIZE];
  scanf(" %[^\n]%*c",typed);
  while (checkEmail(typed)==0){
    printf("\t\tThat's not an email. Please type in an email: ");
    scanf(" %[^\n]%*c",typed);
  }
  int n=strlen(typed);
  for (int i=0;i<n;){
    if ((typed[i]==' ') && (typed[i+1]==' ')){
      for (int j=i+1;j<n;j++){
        typed[j]=typed[j+1];
      }
      n--;
    } else i++;
  }
  return typed;
}

//Return a struct variable given the ID of the contact inside the database
struct contact getinfoContact(int id){
  struct contact temp = {"","",""};
  database = fopen(DATA_BASE_FILE,"r");
  char data[LONG_STRING_SIZE];
  for (int i=1;i<=id;i++){
    fscanf(database," %[^\n]%*c",data);
  }
  fclose(database);
  int i;
  for (i=0;data[i]!='|';i++){
    temp.name[i]=data[i];
  }
  i++;
  for (int j=0;data[i]!='|';i++,j++){
    temp.phone_number[j]=data[i];
  }
  i++;
  for (int j=0;i<strlen(data);i++,j++){
    temp.email[j]=data[i];
  }
  return temp;
}

//Replace old contact data with new data on the database
void replaceContact(struct contact input, int id){
  database = fopen(DATA_BASE_FILE,"r");
  FILE *tempFile;
  tempFile = fopen("replaced.tmp","a");
  if (database == NULL || tempFile == NULL){
    printf("\t\tWe are unable to open or create the necessary files! Please check you have read/write previleges and try to run the program again.\n\n");
    fclose(database);
    fclose(tempFile);
    exit(EXIT_FAILURE);
  }
  char newData[LONG_STRING_SIZE];
  strcat(newData,input.name);
  strcat(newData,"|");
  strcat(newData,input.phone_number);
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
  remove(DATA_BASE_FILE);
  rename("replaced.tmp",DATA_BASE_FILE);
}

//Print out the contact given the ID of the contact in the database
void printContact(int id){
  struct contact temp = getinfoContact(id);
  printf("\t\t%i\t%s\t\t%s\t\t%s\n",id,temp.name,temp.phone_number,temp.email);
}

//Add a new contact to the database with command-line interface
void addContact(){
  struct contact temp;
  printf("\n\t\tAdding a new contact:\n\n");
  printf("\t\tName: ");
  strcpy(temp.name,inputName());
  printf("\t\tPhone number: ");
  strcpy(temp.phone_number,inputPhoneNum());
  printf("\t\tEmail: ");
  strcpy(temp.email,inputEmail());
  database = fopen(DATA_BASE_FILE,"a");
  fprintf(database,"%s|%s|%s\n",temp.name,temp.phone_number,temp.email);
  fclose(database);
  printf("\n\t\tAdded %s to the contact book.",temp.name);
}

//Print out all the contact inside the database
void listContact(){
  int n=getNumberofContact();
  if (n==0) printf("\n\t\tThere is no contact to display.");
  else{
    char savedData[LONG_STRING_SIZE];
    printf("\n\t\tThere are %i contacts in the contact book:\n\n",n);

    for (int id=1;id<=n;id++){
      printContact(id);
    }
  }
}

//Search for contact in the database given any kind of information
void searchContact(){
  printf("\n\n\t\tPlease type in something to search: ");
  char query[SHORT_STRING_SIZE];
  scanf(" %[^\n]%*c",query);
  for (int i=0;i<strlen(query);i++){
    query[i]=tolower(query[i]);
  }
  int flag=0;
  int n=getNumberofContact();
  for (int id=1;id<=n;id++){
    struct contact temp1 = getinfoContact(id);
    char preprocessedData[LONG_STRING_SIZE];
    strcpy(preprocessedData,"");
    strcat(preprocessedData,temp1.name);
    strcat(preprocessedData," ");
    strcat(preprocessedData,temp1.phone_number);
    strcat(preprocessedData," ");
    strcat(preprocessedData,temp1.email);
    for (int i=0;i<strlen(preprocessedData);i++){
      preprocessedData[i]=tolower(preprocessedData[i]);
    }
    if (strstr(preprocessedData,query)!=NULL){
      flag++;
      if (flag==1) printf("\n\n\t\tHere is all the contact have found:\n\n");
      printf("\t");
      printContact(id);
    }
  }
  if (flag==0) printf("\n\n\t\tNo contact have found!");
}

//Edit contact with command-line interface
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
    char newName[SHORT_STRING_SIZE],newPhonenum[SHORT_STRING_SIZE],newEmail[SHORT_STRING_SIZE];
    while (run==1){
      printf("\n\n\t\tYou are editing %s. Type in the following number to edit:",temp.name);
      printf("\n\n\t\t\t[1]: Edit name");
      printf("\n\t\t\t[2]: Edit phone number");
      printf("\n\t\t\t[3]: Edit email");
      printf("\n\t\t\t[0]: Quit/Save");
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
                    if (flagPhonenum!=0) strcpy(temp.phone_number,newPhonenum);
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
                strcpy(newName,inputName());
                flagName++;
                break;
        case 2: printf("\n\n\t\tType in the new phone number: ");
                strcpy(newPhonenum,inputPhoneNum());
                flagPhonenum++;
                break;
        case 3: printf("\n\n\t\tType in the new email: ");
                strcpy(newEmail,inputEmail());
                flagEmail++;
                break;
      }
    }
  }
}

//Delete contact given the the ID of the contact inside the database
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
    database = fopen(DATA_BASE_FILE,"r");
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
    remove(DATA_BASE_FILE);
    rename("deleted.tmp",DATA_BASE_FILE);
    printf("\n\n\t\tDeleted %s",temp.name);
  }
  else{
    printf("\n\n\t\tCanceled. Nothing have changed.");
  }
}

int main(){
  //Init and check contact book database
  FILE *database;
  database = fopen(DATA_BASE_FILE,"a");
  if (database==NULL){
    printf("\t\tWe are unable to open or create the database! Please check you have read/write previleges and try to run the program again.\n\n");
    exit(EXIT_FAILURE);
  } else fclose(database);

  //Main menu interface
  int choice;
  printf("\n\t **** Welcome to Team 3 - Computer Science 1 Contact Manager ****");
  while (1){
    printf("\n\n\n\t\t\tMAIN MENU\n\t\t=====================\n\t\t");
    printf("[1] Add a new Contact\n\t\t[2] List all Contacts\n\t\t[3] Search for contact\n\t\t");
    printf("[4] Edit a Contact\n\t\t[5] Delete a Contact\n\t\t[0] Exit\n\t\t=================\n\t\t");
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
