#include <stdio.h>
#include <math.h>

int nguyento(int n){
  int check=1;
  if (n<2) check=0;
  for (int i=2;i<=sqrt(n);i++){
    if (n%i==0){
      check=0;
      break;
    }
  }
  return check;
}

int main(void){
  int n,ans=0;
  scanf("%i",&n);
  for (int i=1;i<=n;i++){
    if (nguyento(i)==1) ans+=i;
  }
  printf("%i\n",ans);
}
