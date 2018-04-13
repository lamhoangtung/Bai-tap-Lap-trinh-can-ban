#include <stdio.h>

int main(void){
	int n;
	printf("Nhap n: ");scanf("%i",&n);
	int m=n;
	printf("a) n++ + 3 = %i\n",n++ +3);
	n=m;
	printf("b) ++n + 3 = %i\n",++n +3);
	n=m;
	printf("c) n++ + ++n = %i\n",n++ + ++n);
	n=m;
	printf("d) --n + --n = %i\n",--n + --n);
	n=m;
	printf("e) n/2 = %i\n",n/2);
	n=m;
	printf("f) n%2 = %i\n",n%2);
}
