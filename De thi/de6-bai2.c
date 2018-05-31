#include <stdio.h>

int nhap() {
  int n;
  printf("Nhap so phan tu cua mang (0<=n<=20): ");
  scanf("%i", &n);
  while (n < 0 || n > 20) {
    printf(
        "Du lieu khong hop le. Vui long nhap so phan tu cua mang (0<=n<=20): ");
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

void duongle(int a[], int n) {
  int dem = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] > 0 && a[i] % 2 != 0) {
      dem++;
    }
  }
  printf("Co %i phan tu duong le trong mang a:\n", dem);
  for (int i = 0; i < n; i++) {
    if (a[i] > 0 && a[i] % 2 != 0) {
      printf("\t%i tai vi tri thu %i\n", a[i], i + 1);
    }
  }
}

void sapxep(int a[], int n) {
  for (int j = n - 1; j >= 1; j--) {
    for (int i = 0; i <= j - 1; i++) {
      if (a[i] > a[i + 1]) {
        int temp = a[i];
        a[i] = a[i + 1];
        a[i + 1] = temp;
      }
    }
  }
}

int main() {
  int n = nhap();
  int a[n];
  nhapMang(a, n);
  xuatMang(a, n);
  duongle(a, n);
  sapxep(a, n);
  printf("Sau khi sap xep. ");
  xuatMang(a, n);
  return 0;
}
