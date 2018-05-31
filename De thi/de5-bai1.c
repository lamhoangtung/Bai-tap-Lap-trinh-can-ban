#include <stdio.h>

int nhap() {
  int n;
  printf("Nhap vao mot so nguyen duong (n>3): ");
  scanf("%i", &n);
  while (n < 3) {
    printf(
        "Du lieu khong hop le. Vui long nhap vao mot so nguyen duong (n>3): ");
    scanf("%i", &n);
  }
  return n;
}

void tongchiahet(int n) {
  int tong = 0;
  for (int i = 1; i <= n; i++) {
    if (i % 3 == 0) {
      tong += i;
    }
  }
  printf("Tong cac so nguyen chia het cho 3 trong khoang tu 1 den %i la %i.\n",
         n, tong);
}

int main() {
  int n = nhap();
  tongchiahet(n);
  return 0;
}
