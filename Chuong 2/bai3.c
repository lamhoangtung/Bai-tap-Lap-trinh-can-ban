#include <stdio.h>

int main(void){
	int a,b,c;
	printf("Nhap vao 3 so nguyen: ");
	scanf("%i%i%i",&a,&b,&c);
	int nho=a;
	a=c;
	c=nho;
	printf("3 so sau khi dao nguoc la: %i %i %i",a,b,c);
}
