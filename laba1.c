#include <stdio.h>

int main()
{
    int a, b, n, v = 0;
    printf ("Enter a: ");,
    scanf("%d", &a);
    printf("Enter b: ");
    scanf("%d", &b);

    n = a;
    while (n > 0)
    {
        v += n%10;
        n /= 10;
    }

    if (v>b)
        printf("%d\n", v);
    if (v<b)
        printf("%d\n", v + b );
    if (v == b)
        printf("ravno\n");

    return 0;

}
