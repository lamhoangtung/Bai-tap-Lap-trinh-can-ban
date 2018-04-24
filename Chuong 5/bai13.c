#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
  char a[1000];
  printf("Nhap xau: ");
  fgets(a,1000,stdin);
  printf("\nXau vua nhap la:\n%s",a);
  int n=strlen(a),dem=0;
  if (isalpha(a[0])) dem=1;
  for (int i=0;i<n;i++){
    if (isalpha(a[i])&& a[i-1]==' ') dem++;
  }
  printf("\nXau tren co tat ca %i tu.\n",dem);
  return 0;
}
