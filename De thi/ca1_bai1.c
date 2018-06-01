#include <stdio.h>
#include <math.h>

float tinh(int x,int n){
  if (n<=0){
    return (x+n);
  }
  else {
    float temp=sqrt(x);
    int i=1;
    while (i<n){
      temp=sqrt(x+temp);
      i++;
    }
  return temp;
  }
}

int main(){
  int y,m;
  scanf("%i",&y);
  scanf("%i",&m);
  printf("%f\n",tinh(y,m));
  return 0;
}
