#include <stdio.h>

int main(void){
	int tong=0;
	for (int i=1;i<=100;i+=2){
		tong+=i;
	}
	printf("Tong cac so tu nhien le tu 1 den 100 la %i\n",tong);
}
