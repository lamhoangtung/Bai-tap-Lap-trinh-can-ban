#include <stdio.h>

int nhapspt(){
	int n;
	
	printf("Nhap so phan tu cua mang (0<n<=40): ");
	scanf("%i",&n);
	
	while (n<=0 || n>40){
		printf("Du lieu khong hop le. Vui long nhap lai so phan tu cua mang (0<n<=40): ");
		scanf("%i",&n);
	}
	
	return n;
}

void nhapMang(int a[], int n){
	int i;
	
	for (i=0;i<n;i++){
		printf("Nhap phan tu thu %i cua mang: ",i+1);
		scanf("%i",&a[i]);
	}
}

void xuatmang(int a[], int n){
	int i;
	
	for (i=0;i<n;i++){
		printf("%i ",a[i]);
	}
}

int nhapbienphu(char c){
	int n;
	
	printf("Nhap %c: ",c);
	scanf("%i",&n);
	
	return n;
}

void tbcduongnhohonc(int a[], int n, int c){
	int i;
	int tong=0;
	int dem=0;
	
	for (i=0;i<n;i++){
		if (a[i]<c && a[i]>0){
			tong+=a[i];
			dem++;
		}
	}
	
	if (dem!=0){
		float ans=(float)tong/dem;
		printf("Trung binh cong cua cac so duong va nho hon %i trong mang a la %f.\n",c,ans);
	}
	else{
		printf("Khong co so duong nao nho hon %i trong mang a.\n",c);
	}
}


void leduong(int a[], int n){
	int i;
	long long tong=0;
	int vitri[n];
	int j=0;
	
	for (i=0;i<n;i++){
		if (a[i]%2!=0 && a[i]>0){
			tong+=a[i]*a[i];
			vitri[j]=i+1;
			j++;
		}
	}
	
	printf("Tong binh phuong cua cac so le duong trong mang a la %lld.\n",tong);
	if (j==0){
		printf("Khong co so le duong nao trong mang a.\n");
	}
	else{
		printf("Vi tri cua cac so le duong trong mang a la:\n");
		for (i=0;i<j;i++){
			printf("%i ",vitri[i]);
		}
		printf("\n");
	}
}

void xoax(int a[], int *p_n, int x){
	int i;
	int n=*p_n;
	int vt=n;
	int flag;
	
	for (i=n-1;i>=0;i--){
		if (a[i]==x){
			vt=i;
			break;
		}
	}
	if (vt!=n){
		n--;
		for (i=vt;i<n;i++){
			a[i]=a[i+1];
		}
		*p_n=n;
		flag=1;
	}
	else{
		flag=0;
	}
	
	if (flag==0){
		printf("So %i khong ton tai trong mang a.\n",x);
	}
	else{
		printf("Mang a sau khi xoa di phan tu bang %i cuoi cung la:\n",x);
		xuatmang(a,n);
	}
}

int main(){
	int n=nhapspt();
	int a[n];
	nhapMang(a,n);
	
	int c=nhapbienphu('c');
	tbcduongnhohonc(a,n,c);
	
	leduong(a,n);
	
	int x=nhapbienphu('x');
	xoax(a,&n,x);
	
	return 0;
}



