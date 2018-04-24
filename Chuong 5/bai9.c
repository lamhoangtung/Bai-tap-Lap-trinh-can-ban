#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
  char a[1000];
  printf("Nhap xau: ");
  fgets(a,1000,stdin);
  printf("\nXau vua nhap la:\n%s",a);
  int n=strlen(a),phuam=0,nguyenam=0;
  for (int i=0;i<n;i++){
    if (isalpha(a[i])){
      if (a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u'||a[i]=='A'||a[i]=='E'||a[i]=='I'||a[i]=='O'||a[i]=='U')
        nguyenam++;
      else phuam++;
    }
  }
  printf("\nXau tren co %i nguyen am va %i phu am.\n",nguyenam,phuam);
  return 0;
}
