#include <stdio.h>

int main(void){
  char c;
  int n;
  scanf("%c %i",&c,&n);
  switch (c) {
    case 'A': printf("%i\n",n*10);
    break;
    case 'B': printf("%i\n",n*100);
    break;
    case 'C': printf("%i\n",n*1000);
    break;
  }
}
