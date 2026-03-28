#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    FILE *file = fopen("phonebook.csv", "a");
    char *name = malloc(50 * sizeof(char));
    char *number = malloc(20 * sizeof(char));

    scanf("%s", name);
    scanf("%s", number);

    fprintf(file, "%s,%s\n", name, number);
    fclose(file);

    free(name);
    free(number);
    return 0;
}