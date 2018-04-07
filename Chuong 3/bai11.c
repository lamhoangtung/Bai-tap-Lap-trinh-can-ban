#include <stdio.h>

int main(){
  int n,tongtien=0,tonggio=0,soxe=0;
  do {
    printf("Nhap vao so gio do xe: ");
    scanf("%i",&n);
    if (n!=0){
      int tien;
      if (n>=1&&n<=4) tien=n*30000;
      if (n>=5&&n<=7) tien=4*30000+(n-4)*15000;
      if (n>=9&&n<=24) tien=n*18000;
      tongtien+=tien;
      tonggio+=n;
      soxe++;
    }
  }
  while (n!=0);

  printf("\nThong ke\n");
  printf("Tong so xe da do trong bai do la: %i xe\n",soxe);
  printf("Tong so gio cua tat ca cac xe da do la: %i gio\n",tonggio);
  printf("Tong tien thu cua tat cac cac xa da do la: %i dong\n",tongtien);
  printf("Trung binh so gio do cua moi xe la %f gio\n",(float)tonggio/soxe);
  printf("Trung binh tien phai tra cua moi xe la: %i dong\n",tongtien/soxe);
}
