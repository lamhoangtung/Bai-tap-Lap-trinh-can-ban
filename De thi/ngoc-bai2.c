#include <stdio.h>

int nhap() {
  int n;
  printf("Nhap vao so phan tu cua day (n<5): ");
  scanf("%i", &n);
  while (n <= 5) {
    printf("Du lieu khong hop le. Nhap vao so phan tu cua day (n<5): ");
    scanf("%i", &n);
  }
  return n;
}

void nhapMang(int a[], int n) {
  for (int i = 0; i < n; i++) {
    printf("Nhap phan tu thu %i cua day: ", i + 1);
    scanf("%i", &a[i]);
  }
}

void xuatMang(int a[], int n) {
  printf("Day so ban vua nhap la:\n");
  for (int i = 0; i < n; i++) {
    printf("%i ", a[i]);
  }
  printf("\n");
}

void chanam(int a[], int n) {
  int dem = 0, tong = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] % 2 == 0 && a[i] < 0) {
      dem++;
      tong += a[i];
    }
  }
  printf("Co %i so chan am trong day va tong cua chung bang %i.\n", dem, tong);
}

int main() {
  int n = nhap();
  int a[n];
  nhapMang(a, n);
  xuatMang(a, n);
  chanam(a, n);
  return 0;
}
