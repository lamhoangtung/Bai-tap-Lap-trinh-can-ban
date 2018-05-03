#include <stdio.h>
#include <math.h>

int nguyento(int n){
  if (n<2) return 0;
  for (int i=2;i<=sqrt(n);i++){
    if (n%i==0) return 0;
  }
  return 1;
}

int main(){
  int n,ans=0;
  do{
    printf("Nhap vao mot so nguyen duong: ");
    scanf("%i",&n);
  }
  while (n<=0);
  for (int i=1;i<=n;i++){
    if (nguyento(i)==1) ans+=i;
  }
  printf("Tong cua cac so nguyen to tu 1 den %i la: %i\n",n,ans);
  return 0;
}
