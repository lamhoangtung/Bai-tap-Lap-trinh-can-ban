#include <math.h>
#include <stdio.h>

int nhap() {
  int n;
  printf("Nhap mot so nguyen duong: ");
  scanf("%i", &n);
  while (n < 0) {
    printf("Du lieu khong hop le. Vui long nhap vao mot so nguyen duong: ");
    scanf("%i", &n);
  }
  return n;
}

int tongnt(int n) {
  int tong = 0;
  for (int i = 1; i <= n; i++) {
    int kt = 1;
    for (int j = 2; j <= sqrt(i); j++) {
      if (i % j == 0) {
        kt = 0;
        break;
      }
    }
    if (kt == 1)
      tong += i;
  }
  return tong;
}

void inra(int n, int tong) {
  printf("Tong cac so nguyen to tu 1 den %i la %i.\n", n, tong);
}

int main() {
  int n = nhap();
  int tong = tongnt(n);
  inra(n, tong);
  return 0;
}
