//Kiem tra tinh nguyen to cua mot so

#include <stdio.h>
#include <math.h>

int main(){
  int n;

  printf("Moi ban nhap vao mot so nguyen: ");
  scanf("%i",&n);

  int kt=1;
  if (n<2){
    kt=0;
  }
  for (int i=2;i<=sqrt(n);i++){
    if (n%i==0){
      kt=0;
      break;
    }
  }
  if (kt==1){
    printf("So %i la so nguyen to.\n",n);
  }
  else{
    printf("So %i khong la so nguyen to.\n",n);
  }
  return 0;
}
