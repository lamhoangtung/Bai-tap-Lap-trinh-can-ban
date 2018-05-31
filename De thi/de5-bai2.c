#include <math.h>
#include <stdio.h>

int nhap() {
  int n;
  printf("Nhap so phan tu cua mang (0<n<=20): ");
  scanf("%i", &n);
  while (n <= 0 || n > 20) {
    printf(
        "Du lieu khong hop le. Vui long nhap so phan tu cua mang (0<n<=20): ");
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

void min(int a[], int n) {
  int min = a[0];
  for (int i = 1; i < n; i++) {
    if (a[i] < min)
      min = a[i];
  }
  printf("Phan tu nho nhat trong mang la %i va xuat hien tai vi tri thu: ",
         min);
  for (int i = 0; i < n; i++) {
    if (a[i] == min)
      printf("%i ", i + 1);
  }
  printf("\n");
}

void demxh(int a[], int n) {
  int c;
  printf("Nhap vao mot so nguyen: ");
  scanf("%i", &c);
  int dem = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == c) {
      dem++;
    }
  }
  printf("So %i xuat hien %i lan trong mang.\n", c, dem);
}

int main() {
  int n = nhap();
  int a[n];
  nhapMang(a, n);
  xuatMang(a, n);
  min(a, n);
  demxh(a, n);
  return 0;
}
