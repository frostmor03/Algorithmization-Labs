#include <stdio.h>

unsigned int f(unsigned int n) {
  if (n < 2)
    return n;
  else
    return f(n - 1) + f(n - 2);
}

unsigned int f2(unsigned int n) {
  int a = 1, b = 1, c;
  for (int i = 3; i <= n; i++) {
    c = a + b;
    a = b;
    b = c;
  }

  return c;
}

int main() {
  int n;
  printf("Введите: ");
  scanf("%u", &n);
  printf("Рекурсия: %u\n", f(n));
  if (n <= 2)
    printf("Функция: 1\n");
  else
    printf("Функция: %d\n", f2(n));
  return 0;
}
