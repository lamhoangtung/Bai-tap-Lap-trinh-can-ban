#include <stdio.h>

int main(void){
	int n;
	printf("Nhap n: ");scanf("%i",&n);
	printf("a) n++ + 3 = %i\n",n+4);
	printf("b) ++n + 3 = %i\n",n+4);
	printf("c) n++ + ++n = %i\n",n+n+2);
	printf("d) --n + --n = %i\n",n+n-2);
	printf("e) n/2 = %i\n",n/2);
	printf("f) n%2 = %i\n",n%2);
}
