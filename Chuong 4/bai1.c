#include <stdio.h>
#include <math.h>

float input(){
  float temp;
  printf("Nhap vao so thuc duong: ");
  scanf("%f",&temp);
  while (temp<=0){
    printf("Du lieu khong hop le, vui long nhap vao mot so thuc duong: ");
    scanf("%f",&temp);
  }
  return temp;
}

float chuvi(float a, float b, float c){
  return (a+b+c);
}

float dientich(float a, float b, float c){
  float p=(a+b+c)/2;
  return (sqrt(p*(p-a)*(p-b)*(p-c)));
}

void hienthi(float a, float b, float c, float d, float e){
  printf("Do dai 3 canh a, b, c lan luot la: %f, %f, %f\n",a,b,c);
  printf("Chu vi cua tam giac la %f don vi do dai, dien tich cua tam giac la %f don vi dien tich.\n",d,e);
}

int main(){
  float a=input(),b=input(),c=input();

  if (a+b>c&&a+c>b&&b+c>a){
    hienthi(a,b,c,chuvi(a,b,c),dientich(a,b,c));
  }
  else printf("Tam giac da nhap khong ton tai.\n");
  return 0;
}
