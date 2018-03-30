#include <stdio.h>
#include <math.h>

const gia=20000;

int main(void){
	float m;
	printf("Nhap vao trong luong cua goi buu pham: ");scanf("%f",&m);
	float ans=gia*m;
	printf("Buu phi cua goi buu pham la: %f dong\n",ans);
}
