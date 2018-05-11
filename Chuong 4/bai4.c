/*
#include <stdio.h>

void DoSomething(int Num2);

int main(void){
  int Num1=0;
  int Num2=3;
  printf("\nInside main: Num1 = %d Num2 = %d",Num1,Num2);
  DoSomething(Num2);
  printf("\nInside main: Num1 = %d Num2 = %d",Num1,Num2);
  return 0;
}

void DoSomething(int Num2){
  int Num1=0;
  Num1=Num1+5;
  printf("\nInside main: Num1 = %d Num2 = %d",Num1,Num2);
  return;
}
*/

#include <stdio.h>

int DoSomething(int Num1);

int main(void){
  int Num1=4;
  int Num2=7;
  printf("\nInside main: Num1 = %d Num2 = %d",Num1,Num2);
  Num1 = DoSomething(Num1);
  printf("\nInside main: Num1 = %d Num2 = %d",Num1,Num2);
  return 0;
}

int DoSomething(int Num1){
  int Num2=0;
  Num1=Num1+2;
  printf("\nInside main: Num1 = %d Num2 = %d",Num1,Num2);
  return Num1;
}
