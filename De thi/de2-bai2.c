#include <stdio.h>
#include <math.h>

int nhap() {
  int n;
  printf("Nhap so phan tu cua mang (0<n<=35): ");
  scanf("%i", &n);
  while (n <= 0 || n > 35) {
    printf("Du lieu khong hop le. Vui long nhap so phan tu cua mang (0<=n<35): ");
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

void nguyento(int a[],int n){
  int nt[n],k=0,dem=0;
  for (int i=0;i<n;i++){
    int kt=1;
    if (a[i]<2) kt=0;
    for (int j=2;j<=sqrt(a[i]);j++){
      if (a[i]%j==0){
        kt=0;
        break;
      }
    }
    if (kt==1){
      dem++;
      nt[k]=a[i];
      k++;
    }
  }
  printf("Co %i so nguyen to trong mang a:\n",dem);
  for (int i=0;i<k;i++){
    printf("%i ",nt[i]);
  }
  printf("\n");
}


void xuatMang(int a[], int n) {
  printf("Cac phan tu trong mang la:\n");
  for (int i = 0; i < n; i++) {
    printf("%i ", a[i]);
  }
  printf("\n");
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
  nguyento(a, n);
  sapxep(a, n);
  printf("Sau khi sap xep. ");
  xuatMang(a, n);
  return 0;
}
