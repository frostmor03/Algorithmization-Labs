#include <stdio.h>

int main()
{
  int n;
  printf("Введите - >  ");
  scanf("%d", &n);
  int a = 1, b = 1, c;
  if (n <= 2)
    printf("1");
  else
  {
    for (int i = 3; i <= n; i++)
    {
      c = a + b;
      a = b;
      b = c;
    }
    printf("Результат: %d\n", b);
    return 0;
  }
}
