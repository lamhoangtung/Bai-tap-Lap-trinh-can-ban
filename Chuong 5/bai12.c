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
  for (int i=0;i<n;i++){
    printf("Nhap xau thu %i: ",i+1);
    fflush(stdin);
    fgets(a[i],1000,stdin);
  }
}

void hienthiXau(char a[][1000],int n){
  printf("\nCac xau vua nhap la:\n");
  for (int i=0;i<n;i++) printf("%s",a[i]);
}

char nhapkitu(){
  char c;
  printf("\nNhap vao mot ky tu: ");
  fflush(stdin);
  scanf("%c",&c);
  return c;
}

void dem(char a[][1000],int n,char c){
  int ans=0;
  for (int i=0;i<n;i++){
    for (int j=0;j<strlen(a[i]);j++){
      if (a[i][j]==c){
        ans++;
        break;
      }
    }
  }
  printf("Co %i xau co chua ki tu %c.\n",ans,c);
}

int main(){
  int n=nhapint();
  char a[1000][1000];
  nhapXau(a,n);
  hienthiXau(a,n);
  char c=nhapkitu();
  dem(a,n,c);
  return 0;
}
