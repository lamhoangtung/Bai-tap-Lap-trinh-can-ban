//In ra cac uoc cua mot so

#include <stdio.h>
#include <stdlib.h>

int main(){
  int n;

  printf("Moi ban nhap vao mot so nguyen: ");
  scanf("%i",&n);

  printf("Cac uoc cua %i la: ",n);
  for (int i=-abs(n);i<=abs(n);i++){
    if (i!=0){
      if (n%i==0){
        printf("%i ",i);
      }
    }
  }
  printf("\n");
  return 0;
}
