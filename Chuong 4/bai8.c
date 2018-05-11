#include <stdio.h>
#include <math.h>

float nhap(){
  float temp;

  scanf("%f",&temp);

  return temp;
}

double bieuthuc(float x,float y){
  return (pow(2,(x+y))+pow((x-y),1.0/3.0));
}

void hienthi(float f){
  printf("%f\n",f);
}

int main(){
  printf("Nhap so thuc x: ");
  float x=nhap();
  printf("Nhap so thuc y: ");
  float y=nhap();

  double ans=bieuthuc(x,y);
  printf("f(x,y) = ");
  hienthi(ans);

  return 0;
}
