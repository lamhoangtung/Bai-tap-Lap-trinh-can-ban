#include <stdio.h>
#include <math.h>

int main(){
  printf("ax^2 + bx + c = 0\n");
  float a,b,c;
  printf("Nhap 3 so thuc a,b,c: ");
  scanf("%f%f%f",&a,&b,&c);
  if (a==0&&b==0&&c==0){
    printf("Phuong trinh co vo so nghiem.\n");
    return 0;
  }
  else{
    float delta=b*b-4*a*c;
    if (delta<0){
      printf("Phuong trinh vo nghiem.\n");
      return 0;
    }
    else if (delta=0){
      printf("Phuong trinh co nghiem kep x = %f\n",-b/2*a);
      return 0;
    }
    else {
      printf("Phuong trinh co 2 nghiem phan biet x1 = %f va x2 = %f\n",(-b+sqrt(delta))/2*a,(-b-sqrt(delta))/2*a);
      return 0;
    }
  }
}
