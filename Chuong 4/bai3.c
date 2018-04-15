#include <stdio.h>

float InputNumber(){
  float temp;
  printf("Nhap vao mot so thuc duong: ");
  scanf("%f",&temp);
  while (temp<=0||temp>=100){
    printf("So thuc phai lon hon 0 va nho hon 100, vui long nhap lai: ");
    scanf("%f",&temp);
  }
  return temp;
}

char InputChoice(){
  char temp;
  printf("Nhap vao lua chon P hoac D: ");
  scanf(" %c",&temp);
  while (temp!='P'&&temp!='D'){
    printf("Du lieu khong hop le, vui long nhap lai: ");
    scanf(" %c",&temp);
  }
  return temp;
}

void OutputResult(float n,char c){
  if (c=='P') printf("%f%%\n",n);
  else printf("%f\n",n/100.0);
}

int main(){
  float n=InputNumber();
  char c=InputChoice();
  OutputResult(n,c);
  return 0;
}
