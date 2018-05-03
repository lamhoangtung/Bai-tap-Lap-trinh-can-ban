#include <stdio.h>

int hoanhao(int n){
  int tong=0;
  for (int i=1;i<n;i++){
    if (n%i==0) tong+=i;
  }
  if (tong!=n) return 0;
  else return 1;
}

int main(){
  int n;
  printf("Nhap vao mot so nguyen duong: ");
  scanf("%i",&n);
  while (n<=0){
    printf("Du lieu khong hop le, vui long nhap lai mot so nguyen duong: ");
    scanf("%i",&n);
  }
  printf("Cac so hoan hao trong khoang tu 1 den %i la:\n",n);
  for (int i=1;i<=n;i++){
    if (hoanhao(i)==1) printf("%i ",i);
  }
  printf("\n");
  return 0;
}
