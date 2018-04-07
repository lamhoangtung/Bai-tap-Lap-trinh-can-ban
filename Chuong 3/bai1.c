#include <stdio.h>

int main(void){
  int n,gia;
  printf("Nhap so dien tieu thu: ");
  scanf("%i",&n);
  if (n>=0&&n<=100) gia=600;
  else if (n>=101&&n<=150) gia=900;
  else if (n>=151&&n<=200) gia=1200;
  else if (n>=201&&n<=300) gia=1500;
  else gia=2000;
  printf("Tien dien phai tra la: %i dong\n",n*gia);
}
