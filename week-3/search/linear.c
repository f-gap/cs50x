#include <stdio.h>
#include <string.h>

int main()
{
    char *strings[] = {"joao","maria","joana","isis","gabriel"};
    char input[20];
    scanf("%s", input);
    for (int i = 0; i < 5; i++)
    {
        if (strcmp(input,strings[i]) == 0)
        {
            printf("%s está na lista!\n", input);
            return 0;
        }
    }
    printf("%s não está na lista!\n", input);
    return 1;
}