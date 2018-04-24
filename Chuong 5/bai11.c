#include <stdio.h>
#include <string.h>

int nhapint(){
  int n;
  printf("Nhap so nguyen n: ");
  scanf("%i",&n);
  while (n<=0||n>10){
    printf("n phai lon hon 0 va nho hon 10, vui long nhap lai: ");
    scanf("%i",&n);
  }
  return n;
}

void nhapXau(char a[][1000],int n){
  fflush(stdin);
  for (int i=0;i<n;i++){
    printf("Nhap xau thu %i: ",i+1);
    fgets(a[i],1000,stdin);
    fflush(stdin);
  }
}

void hienthiXau(char a[][1000],int n){
  printf("\nCac xau vua nhap la:\n");
  for (int i=0;i<n;i++) printf("%s",a[i]);
}

void hienthiXaudainhat(char a[][1000],int n){
  int max=0,vt=0;
  for (int i=0;i<n;i++){
    if (strlen(a[i])>=max){
      max=strlen(a[i]);
      vt=i;
    }
  }
  printf("\nXau dai nhat la: %s\n",a[vt]);
}

void hienthiXaudaichan(char a[][1000],int n){
  printf("\nCac xau co do dai chan la:\n");
  for (int i=0;i<n;i++){
    if ((strlen(a[i])-1)%2==0) printf("%s",a[i]);
  }
}

int main(){
  int n=nhapint();
  char a[1000][1000];
  nhapXau(a,n);
  hienthiXau(a,n);
  hienthiXaudainhat(a,n);
  hienthiXaudaichan(a,n);
  return 0;
}
