#include <stdio.h>
#include <stdlib.h>

int input(){
  int temp;

  printf("Nhap vao mot so nguyen: ");
  scanf("%i",&temp);

  return temp;
}

int max(int a, int b, int c){
  if (b>=a&&b>=c){
    return b;
  }
  if (c>=a&&c>=b){
    return c;
  }
  return a;
}

int min(int a, int b, int c){
  if (b<=a&&b<=c){
    return b;
  }
  if (c<=a&&c<=b){
    return c;
  }
  return a;
}

int hieubinhphuong(int a, int b){
  return (a*a-b*b);
}

void uocsochung(int a, int b, int c){
  int start=1,end=min(a,b,c);

  if (a<0||b<0||c<0){
    start=min(a,b,c);
    end=abs(max(a,b,c));
  }

  printf("Uoc so chung cua 3 so %i, %i va %i la:\n",a,b,c);
  for (int i=start;i<=end;i++){
    if (i!=0&&a%i==0&&b%i==0&&c%i==0){
      printf("%i ",i);
    }
  }
}

int main(){
  int a=input();
  int b=input();
  int c=input();
  int hbp=hieubinhphuong(max(a,b,c),min(a,b,c));

  printf("Hieu binh phuong cua max va min la: %i\n",hbp);
  uocsochung(a,b,c);

  printf("\n");
  return 0;
}
