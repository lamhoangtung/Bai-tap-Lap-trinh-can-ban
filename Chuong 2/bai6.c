#include <stdio.h>

int main(void){
	long long ngay,gio,phut,giay;
	printf("Nhap vao so ngay gio phut giay: ");
	scanf("%lld%lld%lld%lld",&ngay,&gio,&phut,&giay);
	giay+=((ngay*24+gio)*60+phut)*60;
	printf("So giay la %lld\n",giay);
}
