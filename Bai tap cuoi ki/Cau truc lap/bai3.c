//Tinh tong cac chu so cua mot so

#include <stdio.h>
#include <stdlib.h>

int main(){
  int n;

  printf("Nhap vao mot so nguyen: ");
  scanf("%i",&n);

  int m=abs(n),tong=0;
  while (m!=0){
    tong+=m%10;
    m=m/10;
  }

  printf("Tong cac chu so cua so %i la %i\n",n,tong);
  return 0;
}
