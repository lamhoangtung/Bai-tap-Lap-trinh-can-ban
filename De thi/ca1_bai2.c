#include <stdio.h>

int nhap(){
  int n;
  printf("Nhap vao so phan tu cua day (5<n<20): ");
  scanf("%i",&n);
  while (n<=5||n>=20) {
    printf("Du lieu khong hop le. Vui long nhap lai so phan tu cua day (5<n<20):");
    scanf("%i",&n);
  }
  return n;
}

int nhap2(char *s){
  int n;
  printf("Nhap vao %s: ",s);
  scanf("%i",&n);
  return n;
}

void nhapMang(int a[],int n){
  for (int i=0;i<n;i++){
    printf("Nhap phan tu thu %i cua day so: ",i+1);
    scanf("%i",&a[i]);
  }
}

void xuatMang(int a[],int n){
  printf("Day so la:\n");
  for (int i = 0; i < n; i++) {
    printf("%i ",a[i]);
  }
  printf("\n");
}

void chenMang(int a[],int *p_n,int c,int k){
  int n=*p_n;
  n++;
  for (int i=n-1;i>=k;i--){
    a[i]=a[i-1];
  }
  a[k-1]=c;
  *p_n=n;
}

void xoaMang(int a[],int *p_n,int k){
  int n=*p_n;
  n--;
  for (int i=k-1;i<n;i++){
    a[i]=a[i+1];
  }
  *p_n=n;
}

int main(){
  int n=nhap();
  int a[n];
  nhapMang(a,n);
  xuatMang(a,n);
  int c=nhap2("so c");
  int k=nhap2("vi tri k");
  chenMang(a,&n,c,k);
  printf("Sau khi chen %i vao vi tri %i thi ",c,k);
  xuatMang(a,n);
  xoaMang(a,&n,k);
  printf("Sau khi xoa phan tu tai vi tri %i trong mang thi ",k);
  xuatMang(a,n);
  return 0;
}
