#include <math.h>
#include <stdio.h>

double f(int n) {

  double N = 0;
  for (double x = 1.0 / n; x <= 2.0; x += 2.0 / n) {
    double y;
    if (x <= 1.0)
      y = cos(x + x * x * x);
    else
      y = exp(-(x * x)) - x * x + 2 * x;
    N += y;
  }
  N = (2.0 / n) * N;
  return N;
}

int main() {

  double z;
  printf("Введитe: ");
  scanf("%lf", &z);

  int n = 1;
  double q = f(n);
  double h = f(n * 2);

  while ((fabs(h - q) / 3) >= z) {

    n = n * 2;
    q = h;
    h = f(n * 2);
  }

  printf("%lf\n", h);

  return 0;
}
