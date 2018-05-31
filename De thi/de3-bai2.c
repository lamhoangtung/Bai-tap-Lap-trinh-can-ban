#include <stdio.h>

int nhap() {
  int n;
  printf("Nhap so phan tu cua mang (0<=n<=40): ");
  scanf("%i", &n);
  while (n < 0 || n > 40) {
    printf(
        "Du lieu khong hop le. Vui long nhap so phan tu cua mang (0<=n<40): ");
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

void le(int a[], int n) {
  int dem = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] % 2 != 0) {
      dem++;
    }
  }
  printf("Co %i phan tu le trong mang a:\n", dem);
  for (int i = 0; i < n; i++) {
    if (a[i] % 2 != 0) {
      printf("%i ", a[i]);
    }
  }
  printf("\n");
}

void tbcDuongChan(int a[], int n) {
  int dem = 0, tong = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] >= 0 && a[i] % 2 == 0) {
      dem++;
      tong += a[i];
    }
  }
  if (dem != 0) {
    float tbc = (float)tong / dem;
    printf("Trung binh cong cua cac phan tu duong chan trong mang la %f.\n",
           tbc);
  } else {
    printf("Khong co phan tu duong chan nao trong mang.\n");
  }
}

int main() {
  int n = nhap();
  int a[n];
  nhapMang(a, n);
  xuatMang(a, n);
  le(a, n);
  tbcDuongChan(a, n);
  return 0;
}
