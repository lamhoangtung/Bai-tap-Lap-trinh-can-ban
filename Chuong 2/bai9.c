#include <stdio.h>

void dectohexa(long long n){
	char hexaDeciNum[10000];
	long long i=0;
	while (n!=0){
		long long temp=0;
		temp = n%16;
		if (temp<10){
			hexaDeciNum[i]=temp+48;
			i++;
		}
		else{
			hexaDeciNum[i]=temp+55;
			i++;
		}
		n/=16;
	}
	for (long long j=i-1;j>=0;j--) printf("%c",hexaDeciNum[j]);
}

int main(void){
	long long n,j=0;
	scanf("%lld",&n);
	char bin[1000000];
	long long m=n;
	printf("Binary: ");
	while (m!=0){
		bin[j]=m%2;
		j++;
		m/=2;
	}
	for (int x=j--;j>=0;j--){
		printf("%i",bin[j]);
	}
	printf("\n");
	
	m=n;
		long long temp,i=1,ans=0;
	while (m>0){
		temp=m%8;
		ans+=(temp*i);
		m/=8;
		i*=10;
	}
	
	printf("Octal: %lld\n",ans);
	printf("Hexa: ");
	dectohexa(n);
	printf("\n");
}
