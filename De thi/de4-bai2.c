#include <stdio.h>

int nhap() {
  int n;
  printf("Nhap so phan tu cua mang (0<n<=35): ");
  scanf("%i", &n);
  while (n < 0 || n > 35) {
    printf(
        "Du lieu khong hop le. Vui long nhap so phan tu cua mang (0<n<=35): ");
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

void chan6(int a[], int n){
  int dem=0;
  for (int i=0;i<n;i++){
    if (a[i]<6&&a[i]%2==0){
      dem++;
    }
  }
  printf("Co %i phan tu chan nho hon 6 trong mang: \n",dem);
  for (int i=0;i<n;i++){
    if (a[i]<6&&a[i]%2==0){
      printf("\t%i tai vi tri thu %i\n",a[i],i);
    }
  }
}

void tongam(int a[],int n){
  int tong=0;
  for (int i=0;i<n;i++){
    if (a[i]<0&&a[i]%3==0){
      tong+=a[i];
    }
  }
  printf("Tong cua cac phan tu am va chia het cho 3 trong mang la %i.\n",tong);
}

int main() {
  int n = nhap();
  int a[n];
  nhapMang(a, n);
  xuatMang(a, n);
  chan6(a,n);
  tongam(a,n);
  return 0;
}
