#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int main()
{
  char c;
  int k;
  while(1)
  {
    printf("Enter String: ");
    fgets(c);
    printf("Enter Number: ");
    scanf("%d", &k);
    
   if (c >= 'a' && c <= 'z')
   {
        c = c + k;
        if(c < 'a')
            c += 26;
    }
   else
      if(c >= 'A' && c <= 'Z')
        {
            c = c + k;
            if(c < 'A')
                c += 26;
        }
   printf ("%c", c);
  }      
  getch();
  return 0;
}