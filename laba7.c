#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fill(int m, int n, int array[][n]) {
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      array[i][j] = rand() % 101 - 50;
}
void out(int m, int n, int arr[][n]) {
  for (int i = 0; i < m; i++) {
    int sum = 0;
    for (int j = 0; j < n; j++) {
      sum += arr[i][j];
      printf("%6d", arr[i][j]);
    }
    printf("%8.2lf", (double)sum / n);
    printf("\n");
  }
  for (int j = 0; j < m; j++) {
    int sum1 = 0;
    for (int i = 0; i < n; i++) {
      sum1 += arr[i][j];
    }
    printf("%6.2f", (float)sum1 / m);
  }
  printf("\n");
}

int main() {
  srand(time(NULL));
  int n, m;
  printf("Введите количево строк: ");
  scanf("%d", &m);
  printf("Введите количество столбцов: ");
  scanf("%d", &n);
  int array[m][n];
  fill(m, n, array);
  out(m, n, array);
  return 0;
}
