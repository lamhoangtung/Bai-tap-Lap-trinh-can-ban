#include <stdio.h>

int main(){
	float a,b;
	printf("Nhap a: ");scanf("%f",&a);
	printf("Nhap b: ");scanf("%f",&b);
	if (a==0 && b==0){
		printf("Phuong trinh %f*x + %f = 0 co vo so nghiem\n",a,b);
		return 0;
	}
	else if (a==0 && b!=0){
		printf("Phuong trinh %f*x + %f = 0 vo nghiem\n",a,b);
		return 0;
	}
	else{
		printf("Phuong trinh %f*x + %f = 0 co nghiem duy nhat %f\n",a,b,-b/a);
		return 0;
	}
}
