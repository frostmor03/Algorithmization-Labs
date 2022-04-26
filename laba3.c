#include <stdio.h>
#include <math.h>

int main()
{
    int c = 0;
    float h;
    float x = 0 ;
    printf("Введите h: ");
    scanf("%f", &h);
    int n = ceil (2/h);

    printf("x\t\tf(x)\n------------------\n");

    while (c != n + 1)
    {
      x = h*c;
      if (x <= 1)
        printf("%f %f\n", x, cos(x + pow(x, 3)));
      else
        printf("%f %f\n", x, exp(-2*pow(x, 2))-pow(x, 2) + 2*x);
      c++;
    }
    return 0;
}


     // for (int i = 0; i <= n; i++)
     // {
     //   x = h*i ;
     //   if (x <= 1)
     //    printf("%f %f\n", x, cos(x + pow(x, 3)));
     //   else
     //    printf("%f %f\n", x, exp(-2*pow(x, 2)) - pow(x, 2) + 2*x);
     //  }
    return 0;

  }
