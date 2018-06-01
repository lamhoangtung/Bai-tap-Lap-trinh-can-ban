#include <stdio.h>
#include <math.h>

float tinh(int x, int n){
	float ans;
	
	if (n%2 == 0){
		ans=1;
		int i;
		for (i=1;i<=n;i++){
			ans+=(1/pow(2,i));
		}
		ans+=x;
	}
	else{
		ans=2016*x+sqrt(n*n+10);
	}
	
	return ans;
}

int main(){
	int x1,n1,x2,n2;
	
	printf("Nhap x1: ");
	scanf("%i",&x1);
	printf("Nhap n1: ");
	scanf("%i",&n1);
	printf("Nhap x2: ");
	scanf("%i",&x2);
	printf("Nhap n2: ");
	scanf("%i",&n2);
	
	float ans = tinh(x1,n1) + tinh(x2,n2);
	printf("S = %f\n",ans);
	
	return 0;
}
