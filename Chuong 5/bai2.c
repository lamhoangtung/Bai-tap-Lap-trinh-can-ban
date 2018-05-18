#include <stdio.h>

int hoanhao(int n){
  int tong=0;

  for (int i=1;i<n;i++){
    if (n%i==0){
      tong+=i;
    }
  }
  if (tong!=n){
    return 0;
  }
  else{
    return 1;
  }
}

int main(){
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
  printf("\n\nCac so hoan hao co trong mang la: \n");
  for (int i=1;i<=n;i++){
    if (hoanhao(i)==1){
      printf("%i ",a[i]);
      sum+=a[i];
    }
  }
  printf("\nTong cac so hoan hao trong mang la %lld\n",sum);

  return 0;
}
