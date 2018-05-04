#include <stdio.h>

int main(){
  int firstIndex=0,lastIndex=0,counter=0;
  char temp;

  do{
    int number;
    printf("Nhap vao mot so nguyen: ");
    scanf("%i",&number);
    counter++;
    if (number==24){
      if (firstIndex==0){
        firstIndex=counter;
        lastIndex=counter;
      }
      else{
        lastIndex=counter;
      }
    }
    printf("Nhap Y de tiep tuc, nhap N de ket thuc: ");
    scanf(" %c",&temp);
    getchar();
    while (temp!='Y'&&temp!='N') {
      printf("Ban da nhap sai, vui long nhap Y de tiep tuc va N de ket thuc: ");
      scanf(" %c",&temp);
      getchar();
    }
  }
  while (temp=='Y');

  printf("Vi tri xuat hien lan dau tien va cuoi cung cua so 24 lan luot la %i va %i\n",firstIndex,lastIndex);
  return 0;
}
