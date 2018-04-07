#include <stdio.h>

int main(void){
  int n,gia;
  printf("Nhap vao khoang cach van tai: ");
  scanf("%i",&n);
  switch (n/100){
    case 0: gia=5;
    break;
    case 1: gia=8;
    break;
    case 2: gia=10;
    break;
    case 3: gia=12;
    break;
  }
  printf("Cuoc phi van tai la: %i dong\n",n*gia);
}
