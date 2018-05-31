#include <math.h>
#include <stdio.h>

int nhap() {
  int n;
  printf("Nhap so phan tu cua mang (0<n<=30): ");
  scanf("%i", &n);
  while (n <= 0 || n > 30) {
    printf(
        "Du lieu khong hop le. Vui long nhap so phan tu cua mang (0<n<30): ");
    scanf("%i", &n);
  }
  return n;
}

void nhapMang(int a[], int n) {
  for (int i = 0; i < n; i++) {
    printf("Nhap phan tu a[%i] = ", i + 1);
    scanf("%i", &a[i]);
  }
}

void xuatMang(int a[], int n) {
  printf("Cac phan tu trong mang la:\n");
  for (int i = 0; i < n; i++) {
    printf("%i ", a[i]);
  }
  printf("\n");
}

void tongduong(int a[], int n) {
  int tong = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] > 3) {
      tong += a[i];
    }
  }
  printf("Tong cac phan tu duong lon hon 3 trong mang a la %i.\n", tong);
}

void amduong(int a[], int n) {
  int am = 0, duong = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] < 0)
      am++;
    else
      duong++;
  }
  printf("Mang a co %i phan tu am va %i phan tu duong.\n", am, duong);
}

int main() {
  int n = nhap();
  int a[n];
  nhapMang(a, n);
  xuatMang(a, n);
  tongduong(a, n);
  amduong(a, n);
  return 0;
}
