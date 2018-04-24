#include <stdio.h>

int chinhphuong(int n){
  int i=0;
  while(i*i<n) ++i;
  if (i*i==n) return 1; return 0;
}

int main(void){
  int n,a[10000];
  printf("Nhap so phan tu cua mang: ");
  scanf("%i",&n);
  for (int i=1;i<=n;i++){
    printf("Nhap phan tu thu %i cua mang: ",i);
    scanf("%i",&a[i]);
  }
  printf("\nMang ban vua nhap la:\n");
  for (int i=1;i<=n;i++){
    printf("%i ",a[i]);
  }
  long long sum=0;
  printf("\n\nCac so chinh phuong co trong mang la: \n");
  for (int i=1;i<=n;i++){
    if (chinhphuong(i)==1){
      printf("%i ",a[i]);
      sum+=a[i];
    }
  }
  printf("\nTong cac so chinh phuong trong mang la %lld\n",sum);
}
