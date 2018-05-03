#include <stdio.h>

int main(){
  int n;
  printf("Nhap vao mot so nguyen: ");
  scanf("%i",&n);
  while (n<10||n>20){
    printf("So nhap vao phai lon hon hoac bang 10 va nho hon hoac bang 20, vui long nhap lai: ");
    scanf("%i",&n);
  }
  for (int i=1;i<=n;i++){
    for (int j=1;j<=i;j++) printf("*");
    printf("\n");
  }
  return 0;
}
