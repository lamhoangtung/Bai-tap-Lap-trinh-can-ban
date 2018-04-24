#include <stdio.h>
#include <string.h>

int main(){
  char a[1000];
  printf("Nhap xau: ");
  fgets(a,1000,stdin);
  printf("\nXau vua nhap la:\n%s",a);
  int n=strlen(a);
  if (a[0]==' '||a[n-1]==' '){
    printf("\nXau tren khong phai la xau chuan.\n");
    return 0;
  }
  int dem=0;
  for (int i=0;i<n;i++){
    if (a[i]!=' ') dem=0;
    if (a[i]==' ') dem++;
    if (dem==2){
      printf("\nXau tren khong phai la xau chuan.\n");
      return 0;
    }
  }
  printf("\nXau tren la xau chuan.\n");
  return 0;
}
