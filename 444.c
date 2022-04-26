#include <math.h>
#include <stdio.h>

// Функция для нахождения интеграла с n шагами
double f(int n) {
  // Начальная точка 1.0 / n, далее увеличивается на шаг 2.0 / n, при этом это
  // середина прямоугольника
  double I = 0.0;
  for (double x = 1.0 / n; x <= 2.0; x += 2.0 / n) {
    double y;
    if (x <= 1.0)
      y = cos(x) exp(-pow(x, 2));
    else
      y = log(x + 1) - sqrt(4 - pow(x, 2));
    I += y;
  }
  I = (2.0 / n) I;
  return I;
}

int main() {
  // Запрос точности
  double e;
  printf("Введите точность --> ");
  scanf("%lf", &e);

  // Запуск цикла до нужной точности
  int n = 1;
  double In = f(n);
  double I2n = f(2n);

  while ((fabs(I2n - In) / 3) >= e) {
    printf("%lf для n = %d\n", I2n, n2);
    n = n * 2;
    In = I2n;
    I2n = f(2 * n);
  }

  // Вывод результата
  printf("%lf\n", I2n);

  return 0;
}
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill(int n, int array[]) {
  int i;
  for (i = 0; i < n; i++)
    array[i] = rand() % 101;
}

void out(int n, int arr[]) {
  for (int i = 0; i < n; i++)
    printf("%4d", arr[i]);
  printf("\n");
}



int main() {
  srand(time(NULL));
  int n, imax = 0, imin = 0, max = 0, min = 0;
  printf("Введите количество элементов: ");
  scanf("%d", &n);
  int array[n];
  fill(n, array);
  out(n, array);
  signed i;
  max = array[0];
  min = array[0];
  for (i = 1; i < n; i++) {
    if (array[i] > max) {
      max = array[i];
      imax = i;
    }
    if (array[i] < min) {
      min = array[i];
      imin = i;
    }
  }
  if (imax + imin > abs(max)) {
    array[imax] = imax + imin;
  }
  if(imax + imin < abs(min)){
    array[imin] = imax + imin;
  }
  else {
    for (int i = imin + 1; i < imax; i++)
      array[i] = 0;

  }
  printf("Максимальное число: %d\n", max);
  printf("Минимальное число: %d\n", min);
  printf("Индекс максимаотного числа: %d\n", imax);
  printf("Индекс минимального числа: %d\n", imin);
  out(n, array);
}


#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill(int n, int array[]) {
  int i;
  for (i = 0; i < n; i++)
    array[i] = rand() % 101;
}

void out(int n, int arr[]) {
  for (int i = 0; i < n; i++)
    printf("%4d", arr[i]);
  printf("\n");
}

void f(int *imax, int *imin, int array[]){
    for (int i = 1; i < n; i++) {
    if (array[i] > a[*imax]) {
      *imax = i;
    }
    if (array[i] < a[*imin]) {
      *imin = i;
    }
  }
}

void g(int *imax, int *imin, int array[]) {
    if (*imax + *imin > abs(array[*imax])) {
    array[*imax] = *imax + *imin;
  }
  if(*imax + *imin < abs(array[*imin])){
    array[*imin] = *imax + *imin;
  }
  else {
    for (int i = *imin + 1; i < *imax; i++)
      array[i] = 0;
  }
}



int main() {
  srand(time(NULL));
  int n, *imax = calloc(1,sizeof(int)), *imin= calloc(1,sizeof(int));
  printf("Введите количество элементов: ");
  scanf("%d", &n);
  int array[n];
  fill(n, array);
  out(n, array);
  f(imax, imin, array);
  g(imax, imin, array);  
  printf("Максимальное число: %d\n", array[*imax]);
  printf("Минимальное число: %d\n", array[*imin]);
  printf("Индекс максимаотного числа: %d\n", *imax);
  printf("Индекс минимального числа: %d\n", *imin);
  out(n, array);
}