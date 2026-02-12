#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int only_number(int lenght, char *argv);
int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
    if (only_number(strlen(argv[1]), argv[1]) == 0)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
    int k = atoi(argv[1]);
    k %= 26;
    char plaintext[150],ciphertext[150];
    printf("plaintext: ");
    scanf("%149[^\n]", plaintext);
    int n = strlen(plaintext);
    for (int i = 0; i < n; i++)
    {
        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
        {
            ciphertext[i] = ((plaintext[i]%65)+k)%26 + 'A';
        }
        else if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
        {
            ciphertext[i] = ((plaintext[i]%97)+k)%26 + 'a';
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[n] = '\0';
    printf("ciphertext: %s\n", ciphertext);
    return 0;
}

//return 1 for true and 0 for false
int only_number(int lenght, char *argv)
{
    for (int i = 0,n = lenght; i < n; i++)
    {
        if (isdigit(argv[i]) == 0)
        {
            return 0;
        }
    }
    return 1;
}
