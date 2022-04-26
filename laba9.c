#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void my_atoi(int *n, char *s)
{
  int size_s = strlen(s);
  int digit;
  int value = 0;
  for (int i = 0; i < size_s; i++) {
    digit = s[i] - '0';
    value = value * 10 + digit;
  }
  *n = value;
}

void add_nch(int n, char c, char *res) {
  int len_res = strlen(res);
  while (n) {
    res[len_res++] = c;
    n--;
  }
}

int main() {
  char *str = (char *)calloc(100, sizeof(char));
  char *result = (char *)calloc(100, sizeof(char));
  char *buf = (char *)calloc(10, sizeof(char));
  scanf("%s", str);
  int len = strlen(str), count = 0, flag = 0;
  int len_res = 0;
  char c;

  for (int i = 1; i < len; i++) {
    if (flag) {
      if (str[i] == str[i - 1])
        count++;
      else {
        sprintf(buf, "%d", count);
        strcat(result, buf);
        len_res = strlen(result);
        result[len_res++] = c;
        flag = 0;
        count = 0;
      }
    } else {
      if (str[i] == str[i - 1]) {
        count += 2;
        c = str[i];
        flag = 1;
      } else
        result[len_res++] = str[i - 1];
    }
  }
  if (flag) {
    sprintf(buf, "%d", count);
    strcat(result, buf);
    len_res = strlen(result);
    result[len_res++] = c;
  } else
    result[len_res] = str[len - 1];
  printf("%s\n", result);

  free(result);
  free(str);
  free(buf);
  return 0;
}
