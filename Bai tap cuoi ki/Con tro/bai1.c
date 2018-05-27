//Quan ly diem so don gian su dung con tro

#include <stdio.h>
#include <stdlib.h>

int main(){
	int n;
	float *a;
	const int so_SV_Max=100;

	printf("Nhap so luong sinh vien (<%i): ",so_SV_Max);
	scanf("%i",&n);
	printf("\n");
	a=(float *)calloc(n,sizeof(int));
	for (int i=0;i<n;i++){
		printf("Nhap diem cua sinh vien thu %i: ",i+1);
		scanf("%f",a+i);
		while (*(a+i)<0||*(a+i)>10){
			printf("Diem so khong hop le, vui long nhap lai diem cua sinh vien thu %i: ",i+1);
			scanf("%f",a+i);
		}
	}

	printf("\nDiem cua tat ca cac sinh vien la:\n");
	for (int i=0;i<n;i++){
		printf("%0.1f\t",*(a+i));
	}
	printf("\n");
	return 0;
}
