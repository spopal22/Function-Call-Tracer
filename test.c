#include <stdio.h>

void f3() {
    printf("Inside f3()\n");
}

void f2() {
    printf("Inside f2()\n");
    f3();
}

void f1() {
    printf("Inside f1()\n");
    f2();
}

int main(int argc, char *argv[]) {
  f1();
  f3();
  f2();
  return 0;
}