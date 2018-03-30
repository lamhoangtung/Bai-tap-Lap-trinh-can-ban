#include <stdio.h>

int main(void){
	double p,r,t;
	printf("Nhap vao so tien vay: ");scanf("%lf",&p);
	printf("Nhap vao lai suat vay: ");scanf("%lf",&r);
	printf("Nhap vao thoi gian vay (nam): ");scanf("%lf",&t);
	double m=p*(1+r*t/100.0)/(12*t);
	printf("So tien phai tra hang thang la: %f\n",m);
}
