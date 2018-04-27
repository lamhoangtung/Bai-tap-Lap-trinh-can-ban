#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int hoanhao(int n){
  int tong=0;
  for (int i=1;i<n;i++){
    if (n%i==0) tong+=i;
  }
  if (tong!=n) return 0;
  else return 1;
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
  int dem=0;
  for (int i=0;i<n;i++){
    if (hoanhao(*(a+i))==1) dem++;
  }
  printf("\n\nMang vua nhap co %i so hoan hao.\n",dem);

  int chanmax=INT_MIN,lemin=INT_MAX;
  for (int i=0;i<n;i++){
    if (*(a+i)%2==0&&*(a+i)>=chanmax) chanmax=*(a+i);
    if (*(a+i)%2!=0&&*(a+i)<=lemin) lemin=*(a+i);
  }
  printf("\nMang vua nhap co phan tu chan lon nhat la %i va phan tu le nho nhat la %i.\n",chanmax,lemin);

  int temp;
  printf("\nNhap mot so nguyen: ");
  scanf("%i",&temp);
  printf("\nCac vi tri ma phan tu vua nhap xuat hien trong mang la:\n");
  for (int i=0;i<n;i++){
    if (*(a+i)==temp) printf("%i ",i);
  }
  printf("\n");
  return 0;
}
