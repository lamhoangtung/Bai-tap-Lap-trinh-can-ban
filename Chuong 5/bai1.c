#include <stdio.h>

int main(){
  int n;
  float a[10000],temp;

  printf("Nhap so phan tu cua mang: ");
  scanf("%i",&n);
  for (int i=1;i<=n;i++){
    printf("Nhap phan tu thu %i cua mang: ",i);
    scanf("%f",&a[i]);
  }

  printf("\nMang ban vua nhap la:\n");
  for (int i=1;i<=n;i++){
    printf("%f  ",a[i]);
  }

  double tongam=0;
  printf("\nCac phan tu duong cua mang la:\n");
  for (int i=1;i<=n;i++){
    if (a[i]>=0){
      printf("%f  ",a[i]);
    }
    else{
      tongam+=a[i];
    }
  }
  printf("\nTong cac phan tu am trong mang la: %lf\n",tongam);

  for (int j=n;j>=2;j--){
    for (int i=1;i<=j-1;i++){
      if (a[i]<a[i+1]){
        temp=a[i];
        a[i]=a[i+1];
        a[i+1]=temp;
      }
    }
  }
  printf("\nMang sau khi sap xep theo chieu giam dan la:\n");
  for (int i=1;i<=n;i++){
    printf("%f  ",a[i]);
  }
  printf("\n");

  return 0;
}
