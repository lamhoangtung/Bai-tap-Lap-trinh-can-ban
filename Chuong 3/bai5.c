#include <stdio.h>

int main(void){
  int n;
  printf("Nhap so diem cua sinh vien: ");
  scanf("%i",&n);
  switch (n/10) {
    case 10: printf("Sinh vien xep loai A voi %i diem\n",n);
    break;
    case 9: printf("Sinh vien xep loai A voi %i diem\n",n);
    break;
    case 8: printf("Sinh vien xep loai B voi %i diem\n",n);
    break;
    case 7: printf("Sinh vien xep loai C voi %i diem\n",n);
    break;
    case 6: printf("Sinh vien xep loai D voi %i diem\n",n);
    break;
    case 5: printf("Sinh vien xep loai F voi %i diem\n",n);
    break;
    case 4: printf("Sinh vien xep loai F voi %i diem\n",n);
    break;
    case 3: printf("Sinh vien xep loai F voi %i diem\n",n);
    break;
    case 2: printf("Sinh vien xep loai F voi %i diem\n",n);
    break;
    case 1: printf("Sinh vien xep loai F voi %i diem\n",n);
    break;
    case 0: printf("Sinh vien xep loai F voi %i diem\n",n);
    break;
  }
}
