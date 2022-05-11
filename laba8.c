#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <stdio_ext.h>
int mygetch()
{
    struct termios oldt, newt;
    int c;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    c = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return c;
}

int main()
{
    char c;
    int k = 1;
    while(1)
    {
        c = mygetch();
        if(c != 27 && c != 10)
        {
            c = c + k;
        }
        else if (c == 10)
            break;
        else if (c == 27)
            __fpurge(stdin);
    printf("%c",c);
  }
  printf("\n");
  return 0;
}
