#include <stdio.h>

int hoanhao(int n){
  int tong=0;
  for (int i=1;i<n;i++){
    if (n%i==0) tong+=i;
  }
  if (tong!=n) return 0;
  else return 1;
}

int main(void){
  int n,ans=0;
  scanf("%i",&n);
  for (int i=1;i<=n;i++){
    if (hoanhao(i)==1) printf("%i ",i);
  }
}
