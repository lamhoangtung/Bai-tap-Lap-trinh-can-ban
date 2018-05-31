#include <stdio.h>
#include <stdlib.h>

int main() {
  int n = 40;
  float *a;
  a = (float *)calloc(n, sizeof(int));
  for (int i = 0; i < n; i++) {
    printf("Nhap diem thi cua sinh vien thu %i: ", i + 1);
    scanf("%f", a + i);
    while (*(a + i) < 1 || *(a + i) > 100) {
      printf("Diem thi vua nhap khong hop le, vui long nhap lai diem thi cua "
             "sinh vien thu %i: ",
             i + 1);
      scanf("%f", a + i);
    }
  }
  int xuatsac = 0, gioi = 0, kha = 0, trungbinh = 0, khongdat = 0;
  for (int i = 0; i < n; i++) {
    if (*(a + i) >= 90)
      xuatsac++;
    if (*(a + i) >= 80 && *(a + i) < 90)
      gioi++;
    if (*(a + i) >= 70 && *(a + i) < 80)
      kha++;
    if (*(a + i) >= 50 && *(a + i) < 70)
      trungbinh++;
    if (*(a + i) < 50)
      khongdat++;
  }
  printf("Trong %i sinh vien tren co:\n", n);
  printf("+ %i sinh vien xuat sac.\n", xuatsac);
  printf("+ %i sinh vien gioi.\n", gioi);
  printf("+ %i sinh vien kha.\n", kha);
  printf("+ %i sinh vien trung binh.\n", trungbinh);
  printf("+ %i sinh vien khong dat.\n", khongdat);
  return 0;
}
