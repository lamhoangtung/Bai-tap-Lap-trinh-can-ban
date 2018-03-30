#include <stdio.h>

int main(void){
	int n,m,ans;
	printf("Nhap 2 so n,m: ");scanf("%i%i",&n,&m);
	ans=n+5>m-8;
	printf("n+5>m-8 = %d\n",ans);
	ans=n>0 && m<0;
	printf("n>0 && m<0 = %d\n",ans);
	ans=n>0 || m<0;
	printf("n>0 || m<0 = %d\n",ans);	
	ans=!(n*2+5) && m-7;
	printf("!(n*2+5) && m-7 = %d\n",ans);

}
