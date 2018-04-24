#include <stdio.h>

int main(void){
  int n,a[10000],chan=0,le=0;
  printf("Nhap so phan tu cua mang: ");
  scanf("%i",&n);
  for (int i=1;i<=n;i++){
    printf("Nhap phan tu thu %i cua mang: ",i);
    scanf("%i",&a[i]);
    if (a[i]%2==0) chan++; else le++;
  }
  printf("\nMang ban vua nhap la:\n");
  for (int i=1;i<=n;i++){
    printf("%i ",a[i]);
  }
  printf("\n\nMang vua nhap co %i phan tu chan va %i phan tu le.\n",chan,le);
  int temp,dem=0;
  printf("\nNhap vao mot so nguyen: ");
  scanf("%i",&temp);
  for (int i=1;i<=n;i++){
    if (a[i]==temp) dem++;
  }
  printf("\nCo %i phan tu bang %i trong mang.\n",dem,temp);
}
