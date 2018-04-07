#include <stdio.h>

int main(void){
  int n;
  do scanf("%i",&n);
  while (n<10||n>20);
  for (int i=1;i<=n;i++){
    for (int j=1;j<=i;j++) printf("*");
    printf("\n");
  }
}
