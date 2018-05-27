//In ra 1 danh sach lua chon tu 1 den 10

#include <stdio.h>

int main(){
  int chon;

  printf("\t***MENU*** \n");
  for(int i=1;i<=10;i++){
    printf("\t%i. Lua chon %i \n",i,i);
  }
  printf("\t0. Thoat \n");
  printf("\n\tMoi ban lua chon: ");
  scanf("%i",&chon);

  printf("\tBan vua chon chuc nang so %i \n",chon);
  return 0;
}
