#include <stdio.h>
#include <conio.h>

int main()
{
    char n[80];
    int k;

    printf("Enter String: ");
    gets(n);
    printf("Enter Number: ");
    scanf("%i", &k);

      while (1)
    {
        if (n >= 'a' && n <= 'z')
        {
            n = n + k;
                if(n < 'a')
                    n += 26;
        }
        else
            if(n >= 'A' && n <= 'Z')
        {
            n = n + k;
                if(n < 'A')
                    n += 26;
        }
        printf ("%c", n);

    }

    printf("\n");
    getch();
    return 0;
}