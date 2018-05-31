#include <stdio.h>

int nhap() {
  int n;
  printf("Nhap so phan tu cua mang (0<n<=40): ");
  scanf("%i", &n);
  while (n <= 0 || n > 40) {
    printf(
        "Du lieu khong hop le. Vui long nhap so phan tu cua mang (0<n<=40): ");
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

void tongle(int a[], int n) {
  int tong = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] > 3 && a[i] % 2 != 0) {
      tong+=a[i];
    }
  }
  printf("Tong cac tu le lon hon 3 trong mang a la %i.\n", tong);
}

void max(int a[], int n){
  int max=a[0];
  for (int i=1;i<n;i++){
    if (a[i]>max){
      max=a[i];
    }
  }
  printf("Phan tu lon nhat trong mang a co gia tri bang %i va xuat hien tai vi tri: ",max);
  for (int i=0;i<n;i++){
    if (a[i]==max){
      printf("%i ",i+1);
    }
  }
  printf("\n");
}


int main() {
  int n = nhap();
  int a[n];
  nhapMang(a, n);
  xuatMang(a, n);
  tongle(a,n);
  max(a,n);
  return 0;
}
