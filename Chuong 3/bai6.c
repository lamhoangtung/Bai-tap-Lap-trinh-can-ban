#include <stdio.h>

int main(){
  int a,b,c;
  printf("Nhap vao 3 so nguyen: ");
  scanf("%i%i%i",&a,&b,&c);
  int max=a,min=a;
  if (b>=a&&b>=c) max=b;
  if (c>=a&&c>=b) max=c;
  if (b<=a&&b<=c) min=b;
  if (c<=a&&c<=b) min=c;
  printf("So lon nhat la %i va so nho nhat la %i\n",max,min);
  return 0;
}
