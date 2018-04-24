#include <stdio.h>

int n,m,a[1000][1000];

int nhap(){
  int n;
  scanf("%i",&n);
  return n;
}

void nhapmatran(){
  for (int i=1;i<=n;i++){
    for (int j=1;j<=m;j++){
      printf("Nhap phan tu a[%i][%i]: ",i,j);
      scanf("%i",&a[i][j]);
    }
  }
}

void hienthi(){
  for (int i=1;i<=n;i++){
    for (int j=1;j<=m;j++){
      printf("%i ",a[i][j]);
    }
    printf("\n");
  }
}

void sapxep(){
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
}

long long tongchan(){
  long long sum=0;
  for (int i=1;i<=n;i++){
    for (int j=1;j<=m;j++){
      if (a[i][j]%2==0) sum+=a[i][j];
    }
  }
  return sum;
}

int main(){
  printf("Nhap so dong cua ma tran: ");
  n=nhap();
  printf("Nhap so cot cua ma tran: ");
  m=nhap();
  nhapmatran();
  printf("\nCac phan tu cua ma tran la:\n");
  hienthi();
  sapxep();
  printf("\nMa tran sau khi sap xep tang dan theo cot la:\n");
  hienthi();
  printf("\nTong cac phan tu chan cua ma tran la %lld\n",tongchan());
  return 0;
}
