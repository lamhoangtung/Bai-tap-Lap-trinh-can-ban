//Tim uoc chung lon nhat cua hai so

#include <stdio.h>

int main(){
  int a,b;

  printf("Moi ban nhap vao so nguyen dau tien: ");
  scanf("%i",&a);
  printf("Moi ban nhap vao so nguyen thu hai: ");
  scanf("%i",&b);

  int aa=a,bb=b;
  while(a!=b){
    if (a>b){
      a-=b;
    }
    else{
      b-=a;
    }
  }

  printf("Uoc so chung lon nhat cua hai so %i va %i la %i\n",aa,bb,a);
  return 0;
}
