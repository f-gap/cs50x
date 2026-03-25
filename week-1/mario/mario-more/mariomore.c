#include <stdio.h>

void pyramid(int height);
int main() 
{
    int altura = 0;
    do
    {
        setbuf(stdin, NULL);
        printf("Height: ");
        scanf("%d", &altura); 
    } while (altura < 1 || altura > 8);
    pyramid(altura);
    return 0;
}

void pyramid(int height)
{
    for (int i = 0; i < height; i++)
    {
            for (int espaços = 0; espaços <= height - i; espaços++)
            {
                printf(" ");
            }
            for (int blocos = 0; blocos <= i; blocos++)
            {
                printf("#");
            }
            printf("  ");
            for (int blocos2 = 0; blocos2 <= i; blocos2++)
            {
                printf("#");
            }
        printf ("\n");
    }
}