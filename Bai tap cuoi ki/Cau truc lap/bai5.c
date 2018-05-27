//Kiem tra so chinh phuong

#include <stdio.h>
#include <math.h>

int main(){
  int n;

  printf("Moi ban nhap vao mot so nguyen duong: ");
  scanf("%i",&n);
  while (n<0){
    printf("So vua nhap khong hop le. Vui long nhap lai mot so nguyen duong: ");
    scanf("%i",&n);
  }

  int a=sqrt(n);
  if (a*a==n){
    printf("%i la so chinh phuong.\n",n);
  }
  else{
    printf("%i khong phai so chinh phuong.\n",n);
  }
  return 0;
}
