#include <stdio.h>

int main(void){
	float d,r;
	printf("Nhap vao chieu dai: ");scanf("%f",&d);
	printf("Nhap vao chieu rong: ");scanf("%f",&r);
	float c=(d+r)*2,s=d*r;
	printf("Chu vi cua hinh chu nhat la: %f\n",c);
	printf("Dien tich cua hinh chu nhat la: %f\n",s);	
}
