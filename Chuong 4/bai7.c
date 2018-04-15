#include <stdio.h>
#include <math.h>

int nhap(){
  int temp;
  printf("Nhap vao mot so nguyen duong: ");
  scanf("%i",&temp);
  while(temp<=0){
    printf("Du lieu khong hop le, vui long nhap lai: ");
    scanf("%i",&temp);
  }
  return temp;
}

int tong(int n){
  int ans=0;
  for (int i=1;i<=n;i++) ans+=i;
  return ans;
}

void hienthi(int n){
  printf("%i\n",n);
}

int main(){
  int n=nhap();
  int ans=tong(n);
  printf("Tong cac so nguyen tu 1 den %i la: ",n);
  hienthi(ans);
  return 0;
}
