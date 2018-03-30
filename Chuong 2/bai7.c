#include <stdio.h>
#include <math.h>

int main(void){
	float l;
	printf("Nhap vao chieu dai con lac don: ");scanf("%f",&l);
	float T=2.0*3.14*sqrt(l/9.8);
	printf("Chu ky cua con lac don la: %f\n",T);
}
