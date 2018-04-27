#include <stdio.h>
#include <stdlib.h>

int main(){
  int n;
  printf("Nhap so phan tu cua mang: ");
  scanf("%i",&n);
  float *a;
  a=(float *)calloc(n,sizeof(int));
  for (int i=0;i<n;i++){
    printf("Nhap phan tu thu %i cua mang: ",i+1);
    scanf("%f",a+i);
  }
  printf("\nMang vua nhap la: ");
  for (int i=0;i<n;i++){
    printf("%f ",*(a+i));
  }
  for (int j=n-1;j>=1;j--){
    for (int i=0;i<=j-1;i++){
      if (*(a+i)<*(a+i+1)){
        float tg=*(a+i);
        *(a+i)=*(a+i+1);
        *(a+i+1)=tg;
      }
    }
  }
  printf("\nMang sau khi sap xep la: ");
  for (int i=0;i<n;i++){
    printf("%f ",*(a+i));
  }

  int d1=0,d2=0;
  float sumd=0,suma=0;
  for (int i=0;i<n;i++){
    if (*(a+i)<0){
      suma+=*(a+i);
      d1++;
    }
    else{
      sumd+=*(a+i);
      d2++;
    }
  }
  float ansa=suma/d1,ansd=sumd/d2;
  printf("\nTrung binh cong cua cac so am la %f\n",ansa);
  printf("Trung binh cong cua cac so khong am la %f\n",ansd);
  return 0;
}
