#include <stdio.h>
#include <math.h>

int main()
{
  double x;
  printf("Введите x-> ");
  scanf("%lf", &x);
  if (-1.0 < x && x < 1.0 && x!=-0.46)
  {
    double y = log((1 + x)/(1 - x));
    double z = sqrt(y * y)/(1 + y);
    printf ("y(x) = %lf\nz(y) = %lf\n", y, z);
  }
  else
    printf ("x Значение неверно!\n");
  return 0;
}
