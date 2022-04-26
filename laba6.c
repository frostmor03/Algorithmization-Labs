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

void f(int n, int *imax, int *imin, int array[]){
    for (int i = 1; i < n; i++) {
    if (array[i] > array[*imax]) {
      *imax = i;
    }
    if (array[i] < array[*imin]) {
      *imin = i;
    }
  }
}

void g(int *imax, int *imin, int array[]) {
    if (*imax + *imin > abs(array[*imax])) {
    array[*imax] = *imax + *imin;
  }
  else if(*imax + *imin < abs(array[*imin])){
    array[*imin] = *imax + *imin;
  }
  else {
    for (int i = *imin + 1; i < *imax; i++)
      array[i] = 0;
  }
}



int main() {
  srand(time(NULL));
  int max, min;
  int n, *imax = (int *)calloc(1,sizeof(int)), *imin= (int *)calloc(1,sizeof(int));
  printf("Введите количество элементов: ");
  scanf("%d", &n);
  int array[n];
  fill(n, array);
  out(n, array);
  f(n, imax, imin, array);
  max = array[*imax];
  min = array[*imin];
  g(imax, imin, array);  
  printf("Максимальное число: %d\n", max);
  printf("Минимальное число: %d\n", min);
  printf("Индекс максимаотного числа: %d\n", *imax);
  printf("Индекс минимального числа: %d\n", *imin);
  out(n, array);
}