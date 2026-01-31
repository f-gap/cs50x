#include <ctype.h>
#include <math.h>
#include <stdio.h>

int main()
{
    char text[501];
    double letters = 0.0, words = 1.0, sentences = 0.0;
    double L,S;
    printf("Text: ");
    scanf("%500[^\n]", text);
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isalnum(text[i]) != 0)
        {
            letters++;
        }
        if (isspace(text[i]) != 0)
        {
            words++;
        }
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        } 
    }
    L = letters/words * 100;
    S = sentences/words * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    if (index < 1)
    {
        printf("Before Grade 1\n"); 
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else 
    {
        printf("Grade %d\n", index);
    }
}