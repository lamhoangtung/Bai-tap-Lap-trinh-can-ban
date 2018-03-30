#include <stdio.h>

int count(int n){
	int d=0;
	while (n!=0){
		d++;
		n/=10;
	}
	return d;
}

int main(void){
	int n;
	float f;
	char c;
	printf("Nhap vao 1 so nguyen: ");
	scanf("%i",&n);
	printf("Nhap vao 1 so thuc: ");
	scanf("%f",&f);
	for (int i=0;i<6-count(n);i++) printf("0");
	printf("%i\n",n);
	int temp=(int)f;
	for (int i=0;i<8-count(f);i++) printf("0");
	printf("%0.2f\n",f);
}
