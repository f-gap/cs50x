#include <stdio.h>

int main()
{
    int troco = -1,moedas = 0;
    printf("Change owed: ");
    do
    {
        setbuf(stdin, NULL);
        scanf("%d", &troco);
    } while (troco < 0);
    for (; troco >= 25; troco -= 25)
    {
        moedas++;
    }
    for (; troco >= 10; troco -= 10)
    {
        moedas++;
    }
    for (; troco >= 5; troco -= 5)
    {
        moedas++;
    }
    for (; troco >= 1; troco -= 1)
    {
        moedas++;
    }
    printf("%d\n", moedas);
    return 0;
}