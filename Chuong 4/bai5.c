#include <stdio.h>

float nhap(){
  float temp;
  scanf("%f",&temp);
  while (temp<0){
    printf("Du lieu khong hop le, vui long nhap lai: ");
    scanf("%f",&temp);
  }
  return temp;
}

float trokhang(float r, float l, float c){
  return (r*r+(l-c)*(l-c));
}

void hienthi(float f){
  printf("Tro khang cua mach RLC la: %f\n",f);
}

int main(){
  printf("Nhap dien tro R: ");
  float r=nhap();
  printf("Nhap cam khang L: ");
  float l=nhap();
  printf("Nhap dung khang C: ");
  float c=nhap();
  hienthi(trokhang(r,l,c));
  return 0;
}
