#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
  char a[1000];
  printf("Nhap xau: ");
  fgets(a,1000,stdin);
  printf("\nXau vua nhap la:\n%s",a);
  int n=strlen(a);
  a[0]=toupper(a[0]);
  for (int i=0;i<n;i++){
    if (isalpha(a[i])&& a[i-1]==' ') a[i]=toupper(a[i]);
  }
  printf("\nXau sau khi chuyen doi la:\n%s\n",a);
  return 0;
}
