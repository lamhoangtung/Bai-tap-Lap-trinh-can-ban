#include <stdio.h>

float nhap(char *s) {
  float n;
  printf("Nhap so thuc thu %s: ", s);
  scanf("%f", &n);
  while (n <= 1 || n >= 50) {
    printf("Du lieu khong hop le. Vui long nhap so thuc thu %s: ", s);
    scanf("%f", &n);
  }
  return n;
}

char luachon() {
  char c;
  printf("Nhap N de tinh tong, Y de tinh hieu: ");
  scanf(" %c", &c);
  while (c != 'y' && c != 'Y' && c != 'n' && c != 'N') {
    printf("Lua chon khong hop le. Vui long nhap N de tinh tong, Y de tinh "
           "hieu: ");
    scanf(" %c", &c);
  }
  return c;
}

void tinh(float a, float b, float c, char lc) {
  if (lc == 'y' || lc == 'Y') {
    printf("Hieu cua 3 so la %f.\n", a - b - c);
  } else {
    printf("Tong cua 3 so la %f.\n", a + b + c);
  }
}

int main() {
  float a = nhap("nhat");
  float b = nhap("hai");
  float c = nhap("ba");
  tinh(a, b, c, luachon());
  return 0;
}
