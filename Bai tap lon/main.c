#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

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

int check_subsequence(char a[], char b[]){
  int c,d;
  c=d=0;
  while (a[c]!='\0'){
    while ((a[c]!=b[d]) && b[d]!='\0'){
      d++;
    }
    if (b[d]=='\0') break;
    d++;
    c++;
  }
  if (a[c]=='\0') return 1;
  else return 0;
}

void printContact(int id, char data[]){
  int begin=0,end;
  printf("\t\t%i\t",id);
  for (int i=0;i<strlen(data);i++){
    if (data[i]=='|'){
      end=i-1;
      for (int j=begin;j<=end;j++){
        printf("%c",data[j]);
      }
      begin=i+1;
      printf("\t\t");
    }
  }
  end=strlen(data)-1;
  for (int j=begin;j<=end;j++) printf("%c",data[j]);
  printf("\n");
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
    printf("\n\t\tThere are %i contacts in the contact book:\n\n",lines);
    database = fopen("database.txt","r");
    for (int id=1;id<=lines;id++){
      fscanf(database," %[^\n]%*c",savedData);
      //printf("\t\t%s\n",savedData);
      printContact(id,savedData);
    }
    fclose(database);
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
  int lines=countline();
  database = fopen("database.txt","r");
  for (int id=1;id<=lines;id++){
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
    if (strstr(preprocessedData,query)!=NULL) printContact(id,savedData);
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
    printf(" Contact\n\t\t[2] List all Contacts\n\t\t[3] Search for contact\n\t\t[4] Edit");x
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

      case 3: searchContact();
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
