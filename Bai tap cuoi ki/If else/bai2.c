//Tim so lon nhat trong 3 so

#include <stdio.h>

int main(){
  float a,b,c;

  printf("Moi ban nhap vao so dau tien: ");
  scanf("%f",&a);
  printf("Moi ban nhap vao so thu hai: ");
  scanf("%f",&b);
  printf("Moi ban nhap vao so thu ba: ");
  scanf("%f",&c);

  if (a>b && a>c){
    printf("So %.3f la so lon nhat trong ba so. \n",a);
  }
  else if(b>a && b>c){
    printf("So %.3f la so lon nhat trong ba so. \n",b);
  }
  else{
    printf("So %.3f la so lon nhat trong ba so. \n",c);
  }
  return 0;
}
