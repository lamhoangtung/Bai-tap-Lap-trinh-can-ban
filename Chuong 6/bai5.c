#include <stdio.h>
#include <stdlib.h>

int main(){
  int n,m,temp,mang[1000][1000];
  printf("Nhap so hang: ");
  scanf("%i",&n);
  printf("Nhap so cot: ");
  scanf("%i",&m);
  int (*a)[1000];
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      printf("Nhap phan tu a[%i][%i]: ",i+1,j+1);
      scanf("%i",&temp);
      (*a)[i][j]=temp;
    }
  }
  long long sum=0;
  printf("\nMa tran vua nhap la:\n");
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
      printf("%i ",*(*(a+i)+j));
      if (j%2!=0) sum+=*(*(a+i)+j);
    }
    printf("\n");
  }
  printf("\nTong tat ca cac phan tu trong cot le la %lli.\n",sum);

  return 0;
}
