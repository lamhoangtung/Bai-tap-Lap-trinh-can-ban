#include <stdio.h>
#include <math.h>

float nhap(char c){
  float n;
  printf("Nhap so thuc %c: ",c);
  scanf("%f",&n);
  return n;
}

float tinh(float x, float y){
  return pow(3,2*x-y)-exp(x+3*y);
}

void inra(float n){
  printf("A = %f\n",n);
}

int main(){
  int x=nhap('x');
  int y=nhap('y');
  inra(tinh(x,y));
  return 0;
}
