#include <stdio.h>

int nhap() {
  int n;
  printf("Nhap mot so nguyen duong n (4<n<100): ");
  scanf("%i", &n);
  while (n <= 4 || n >= 100) {
    printf("Du lieu khong hop le. Vui long nhap vao mot so nguyen duong n "
           "(4<n<100): ");
    scanf("%i", &n);
  }
  return n;
}

int tonghoanhao(int n) {
  int tong = 0;
  for (int i = 1; i <= n; i++) {
    int temp = 0;
    for (int j = 1; j < i; j++) {
      if (i % j == 0)
        temp += j;
    }
    if (temp == i)
      tong += i;
  }
  return tong;
}

void inra(int n, int tong) {
  printf("Tong cac so hoan hao tu 1 den %i la %i.\n", n, tong);
}

int main() {
  int n = nhap();
  int tong = tonghoanhao(n);
  inra(n, tong);
  return 0;
}
