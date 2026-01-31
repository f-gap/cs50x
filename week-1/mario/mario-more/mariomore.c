#include <stdio.h>

int main() 
{
    int altura = 0;
    do
    {
        setbuf(stdin, NULL);
        printf("Height: ");
        scanf("%d", &altura); 
    } while (altura < 1 || altura > 8);
    for (int i = 1; i <= altura; i++)
    {
            for (int espaços = 0; espaços < altura - i; espaços++)
            {
                printf(" ");
            }
            for (int blocos = 0; blocos < i; blocos++)
            {
                printf("#");
            }
            printf("  ");
            for (int blocos2 = 0; blocos2 < i; blocos2++)
            {
                printf("#");
            }
        printf ("\n");
    }
    return 0;
}