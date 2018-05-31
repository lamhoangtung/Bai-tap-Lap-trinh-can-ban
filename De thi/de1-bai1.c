#include <math.h>
#include <stdio.h>

int nhap(char *s) {
  int n;
  printf("Nhap do dai canh thu %s: ", s);
  scanf("%i", &n);
  while (n < 0) {
    printf("Du lieu khong hop le. Vui long nhap do dai canh thu %s: ", s);
    scanf("%i", &n);
  }
  return n;
}

int chuvi(int a, int b, int c) { return (a + b + c); }

float dientich(int a, int b, int c) {
  float p = (float)(a + b + c) / 2;
  return (sqrt(p * (p - a) * (p - b) * (p - c)));
}

void inra(int cv, float dt) {
  printf("Chu vi cua tam giac tren la %i don vi do dai.\n", cv);
  printf("Dien tich cua tam giac tren la %f don vi dien tich.\n", dt);
}

int main() {
  int a = nhap("nhat");
  int b = nhap("hai");
  int c = nhap("ba");
  inra(chuvi(a, b, c), dientich(a, b, c));
  return 0;
}
