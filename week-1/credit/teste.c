#include <stdio.h>

int main()
{
    int numero,soma1,soma2,i,idt;
    scanf("%d", &numero);
    for (i = 1; numero > 0; i++)
    {
        if (i % 2 == 0)
        {
            soma2 += (numero % 10)*2;
        }
        else 
        {
            soma1 += numero % 10;
        }
        numero = numero/10;
        if (numero < 100 && numero > 10)
        {
            idt = numero;
        }  
        printf("soma 1:%d soma 2:%d i:%d idt:%d\n", soma1,soma2,i,idt);
    }
}