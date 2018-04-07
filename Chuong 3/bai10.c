#include <stdio.h>

int main(void){
  int temp,a,b;
  do{
    printf("1. Nhap vao hai so nguyen\n");
    printf("2. Tinh tong hai so nguyen vua nhap\n");
    printf("3. Tinh hieu hai so nguyen vua nhap\n");
    printf("4. Tinh tich hai so nguyen vua nhap\n");
    printf("5. Tinh thuong hai so nguyen vua nhap\n");
    printf("6. Thoat\n");
    printf("Moi ban nhap lua chon: ");
    scanf("%i",&temp);

    switch (temp) {
      case 1: printf("Nhap vao 2 so nguyen: ");
              scanf("%i%i",&a,&b);
              break;
      case 2: printf("Tong cua 2 so nguyen %i va %i la %i\n",a,b,a+b);
              break;
      case 3: printf("Hieu cua 2 so nguyen %i va %i la %i\n",a,b,a-b);
              break;
      case 4: printf("Tich cua 2 so nguyen %i va %i la %i\n",a,b,a*b);
              break;
      case 5: printf("Thuong cua 2 so nguyen %i va %i la %f\n",a,b,(float)a/b);
              break;
    }
  }
  while (temp!=6);
}
