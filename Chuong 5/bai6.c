#include <stdio.h>
#include <math.h>

int a[51],n;

void nhap(){
  printf("\nNhap so luong phan tu cua mang: ");
  scanf("%i",&n);
  while (n<0||n>50){
    printf("Kich thuoc cua mang phai lon hon 0 va nho hon 50, vui long nhap lai: ");
    scanf("%i",&n);
  }
  for (int i=1;i<=n;i++){
    printf("Nhap phan tu thu %i cua mang: ",i);
    scanf("%i",&a[i]);
  }
  printf("\n");
}

void hienthi(){
  printf("\nCac phan tu cua mang la:\n");
  for (int i=1;i<=n;i++){
    printf("%i ",a[i]);
  }
  printf("\n");
}

void maxmin(){
  int amax=-999999999,dmin=999999999;
  for (int i=1;i<=n;i++){
    if (a[i]>=0 && a[i]<dmin) dmin=a[i];
    if (a[i]<0 && a[i]>amax) amax=a[i];
  }
  printf("\nPhan tu duong nho nhat la %i va phan tu am lon nhat la %i.\n",dmin,amax);
}

int chinhphuong(int n){
  int i=0;
  while(i*i<n) ++i;
  if (i*i==n) return 1; return 0;
}

void demchinhphuong(){
  int dem=0;
  for (int i=1;i<=n;i++){
    if (chinhphuong(a[i])==1) dem++;
  }
  printf("\nCo %i so chinh phuong trong mang.\n",dem);
}

int nguyento(int n){
  if (n<2) return 0;
  for (int i=2;i<=sqrt(n);i++){
    if (n%i==0) return 0;
  }
  return 1;
}

void tongnguyento(){
  long long sum=0;
  for (int i=1;i<=n;i++){
    if (nguyento(a[i])==1) sum+=a[i];
  }
  printf("\nTong cua cac so nguyen to trong mang la %lld.\n",sum);
}

void sapxep(){
  for (int j=n;j>=2;j--){
    for (int i=1;i<=j-1;i++){
      if (a[i]>a[i+1]){
        int temp=a[i];
        a[i]=a[i+1];
        a[i+1]=temp;
      }
    }
  }
  printf("\nMang sau khi sap xep la:\n");
  for (int i=1;i<=n;i++){
    printf("%i ",a[i]);
  }
  printf("\n");
}

int main(){
  int request=0;
  printf("1. Nhap vap kich thuoc va cac phan tu cua mang so nguyen tu ban phim.\n");
  printf("2. Hien thi cac phan tu cua mang vua nhap ra man hinh.\n");
  printf("3. Tim va hien thi phan tu duong nho nhat va am lon nhat trong mang vua nhap.\n");
  printf("4. Dem cac so chinh phuong trong mang. Hien thi ket qua dem duoc ra man hinh.\n");
  printf("5. Tinh va hien thi tong cua tat ca cac so nguyen to trong mang.\n");
  printf("6. Sap xep cac phan tu cua mang theo chieu tang dan va hien thi mang sau khi sap xep ra man hinh.\n");
  printf("7. Ket thuc chuong trinh.\n");
  while (request!=7){
    printf("\nMoi nhap vao lua chon: ");
    scanf("%i",&request);
    switch (request) {
      case 1: nhap();
      break;
      case 2: hienthi();
      break;
      case 3: maxmin();
      break;
      case 4: demchinhphuong();
      break;
      case 5: tongnguyento();
      break;
      case 6: sapxep();
      break;
      case 7: printf("\nChuong trinh da thoat.\n");
      break;
    }
  }
  return 0;
}
