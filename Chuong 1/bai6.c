#include <stdio.h>
#include <math.h>

int main(void){
	float f;
	printf("Nhap do Fahrenheit: ");scanf("%f",&f);
	float c=(f-32.0)/1.8;
	printf("%f Fahrenheit equal %f Celsius\n",f,c);
}
