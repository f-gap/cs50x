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
        numero/=10;
        if (numero < 100 && numero > 10)
        {
            idt = numero;
        }  
    }
    if (((soma1+soma2) % 10) == 0)
    {
        if (idt == 34 || idt == 37)
        {
            printf("AMEX\n");
        }
        else if (idt == 51 || idt == 52 || idt == 53 || idt == 54 || idt == 55)
        {
            printf("MASTERCARD\n");
        }
        else if (idt == 40 || idt == 41 || idt == 42 || idt == 43 || idt == 44 || idt == 45 || idt == 46 || idt == 47 || idt == 48 || idt == 49)
        {
            printf("VISA\n");  
        } 
    }
    else
    {
        printf("INVALID\n");
    }
    return 0;
}