#include <stdio.h>
#include <math.h>

int nhap(){
  int n;
  printf("Nhap vao mot so nguyen: ");
  scanf("%i",&n);
  return n;
}

float tinh(int n){
  float ans=0;
  if (n%2==0){
    for (int i=1;i<=n;i++){
      ans+=pow(i,2);
    }
  }else{
    ans=(float)(log(n)/log(5))+5;
  }
  return ans;
}

void hienthi(float n){
  printf("f(n) = %f\n",n);
}

int main(){
  int m=nhap();
  hienthi(tinh(m));
  return 0;
}
