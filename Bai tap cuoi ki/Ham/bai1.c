#include <stdio.h>
#include <math.h>

float nhap(char c){
  float n;

  printf("Moi ban nhap %c: ",c);
  scanf("%f",&n);
  return n;
}

float tinh(float x, float n){
  float kq=0;

  kq=(float)(pow(x,n)+pow(n,x))/pow(x+1,n+1);
  return kq;
}

void inra(float ketqua){
  printf("Ket qua cua phep tinh la: %f \n",ketqua);
}

int main(){
  float x=nhap('x');
  float n=nhap('n');

  float ketqua=tinh(x,n);
  inra(ketqua);

  return 0;
}
