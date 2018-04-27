#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int nguyento(int n){
  if (n<2) return 0;
  for (int i=2;i<=sqrt(n);i++){
    if (n%i==0) return 0;
  }
  return 1;
}

int main(){
  int n;
  printf("Nhap so phan tu cua mang: ");
  scanf("%i",&n);
  int *a;
  a=(int *)calloc(n,sizeof(int));
  for (int i=0;i<n;i++){
    printf("Nhap phan tu thu %i cua mang: ",i+1);
    scanf("%i",a+i);
  }
  printf("\nMang vua nhap la: ");
  for (int i=0;i<n;i++){
    printf("%i ",*(a+i));
  }
  for (int j=n-1;j>=1;j--){
    for (int i=0;i<=j-1;i++){
      if (*(a+i)>*(a+i+1)){
        int tg=*(a+i);
        *(a+i)=*(a+i+1);
        *(a+i+1)=tg;
      }
    }
  }
  printf("\nMang sau khi sap xep la: ");
  for (int i=0;i<n;i++){
    printf("%i ",*(a+i));
  }
  printf("\nCac so nguyen to co trong mang la: ");
  for (int i=0;i<n;i++){
    if (nguyento(*(a+i))==1) printf("%i ",*(a+i));
  }
  printf("\n");
  return 0;
}
