#include <stdio.h>
#include <math.h>

int nhap(){
  int temp;

  printf("Nhap vao so nguyen: ");
  scanf("%i",&temp);

  return temp;
}

void nguyento(int n){
  int check=1;

  if (n<2){
    check=0;
  }
  for (int i=2;i<=sqrt(n);i++){
    if (n%i==0){
      check=0;
      break;
    }
  }

  if (check==1){
    printf("%i la so nguyen to.\n",n);
  }
  else{
    printf("%i khong phai la so nguyen to.\n",n);
  }
}

int main(){
  int n=nhap();

  nguyento(n);
  
  return 0;
}
