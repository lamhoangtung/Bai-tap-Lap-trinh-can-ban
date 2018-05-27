//Tinh giai thua bang de quy

#include <stdio.h>

int nhap(){
  int n;

  printf("Moi ban nhap mot so nguyen duong: ");
  scanf("%i",&n);
  while (n<=0){
    printf("So vua nhap khong hop le, vui long nhap lai mot so nguyen duong: ");
    scanf("%i",&n);
  }
  return n;
}

int giaithua(unsigned int n){
  if (n<=1){
    return 1;
  }
  else{
    return (n*giaithua(n-1));
  }
}

void inra(unsigned int n)
{
  printf("Giai thua cua %i la: %i\n",n,giaithua(n));
}

int main(){
  int n=nhap();
  inra(n);
  return 0;
}
