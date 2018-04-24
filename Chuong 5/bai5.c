#include <stdio.h>

int main(void){
  int n,m,a[999][999];
  long long sum=0;
  printf("Nhap so hang cua ma tran: ");
  scanf("%i",&n);
  printf("Nhap so cot cua ma tran: ");
  scanf("%i",&m);
  for (int i=1;i<=n;i++){
    for (int j=1;j<=m;j++){
      printf("Nhap phan tu a[%i][%i]: ",i,j);
      scanf("%i",&a[i][j]);
      if (i%2==0) sum+=a[i][j];
    }
  }
  printf("\n\nMa tran ban vua nhap la:\n");
  for (int i=1;i<=n;i++){
    for (int j=1;j<=m;j++){
      printf("%i ",a[i][j]);
    }
    printf("\n");
  }
  printf("\nTong cac phan tu cua hang chan la: %lld\n",sum);

  for (int x=1;x<=m;x++){
    for (int j=n;j>=2;j--){
      for (int i=1;i<=j-1;i++){
        if (a[i][x]>a[i+1][x]){
          int temp=a[i][x];
          a[i][x]=a[i+1][x];
          a[i+1][x]=temp;
        }
      }
    }
  }
  printf("\nMa tran sau khi sap xep tang dan theo cot la:\n");
  for (int i=1;i<=n;i++){
    for (int j=1;j<=m;j++){
      printf("%i ",a[i][j]);
    }
    printf("\n");
  }
}
