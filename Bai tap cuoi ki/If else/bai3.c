//Kiem tra do dai 3 doan thang co phai do dai 3 canh cua 1 tam giac khong

#include <stdio.h>

int main(){
  float a,b,c;

  printf("Moi ban nhap do dai canh thu nhat: ");
  scanf("%f",&a);
  printf("Moi ban nhap do dai canh thu hai: ");
  scanf("%f",&b);
  printf("Moi ban nhap do dai canh thu ba: ");
  scanf("%f",&c);

  if(b+c>a && a+c>b && a+b>c){
    printf("Ba canh co do dai lan luot la %.2f, %.2f va %.2f tao thanh mot tam giac. \n",a,b,c);
  }
  else{
    printf("Ba canh co do dai lan luot la %.2f, %.2f va %.2f khong tao thanh mot tam giac. \n",a,b,c);
  }
  return 0;
}
