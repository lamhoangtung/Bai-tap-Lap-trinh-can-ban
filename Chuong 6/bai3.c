#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int chinhphuong(int n){
  int i=sqrt(n);
  if (n==i*i) return 1;
  else return 0;
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
  long long sum=0;
  printf("\nMang vua nhap la: ");
  for (int i=0;i<n;i++){
    printf("%i ",*(a+i));
    sum+=*(a+i);
  }
  printf("\n\nTong cac phan tu trong mang vua nhap la: %lli\n",sum);

  printf("\nCac so chinh phuong co trong mang la: ");
  for (int i=0;i<n;i++){
    if (chinhphuong(*(a+i))==1) printf("%i ",*(a+i));
  }
  printf("\n");
  return 0;
}
