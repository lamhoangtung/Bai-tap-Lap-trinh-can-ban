#include <math.h>
#include <stdio.h>

int nhap(char c) {
  int n;
  printf("Nhap so nguyen thu %c: ", c);
  scanf("%i", &n);
  return n;
}

int max(int a, int b) {
  if (a > b) {
    return a;
  } else {
    return b;
  }
}

void inra(int a, int b, int c, int d, int max) {
  printf("So lon nhat trong 4 so %i, %i, %i va %i la %i.\n", a, b, c, d, max);
}

int main() {
  int a = nhap('1');
  int b = nhap('2');
  int c = nhap('3');
  int d = nhap('4');
  int maxx = max(max(a, b), max(c, d));
  inra(a, b, c, d, maxx);
  return 0;
}
