#include <stdio.h>

typedef struct 
{
    int points;
    char word[50];
}player;

typedef struct
{
    char character;
    int value;
}tableValue;



int main()
{
    tableValue letter[53];
    int indice;
    for (int i = 0; i < 26; i++)
    {
        letter[i].character = 97 + i;
        indice = i + 1;
    }

    for (int i = 0;i < 26 ; i++)
    {
        letter[indice + i].character = 65 + i;
    }
    

    letter[0].value = 1;
    letter[1].value = 3;
    letter[2].value = 3;
    letter[3].value = 2;
    letter[4].value = 1;
    letter[5].value = 4;
    letter[6].value = 2;
    letter[7].value = 4;
    letter[8].value = 1;
    letter[9].value = 8;
    letter[10].value = 5;
    letter[11].value = 1;
    letter[12].value = 3;
    letter[13].value = 1;  // N
    letter[14].value = 1;  // O
    letter[15].value = 3;  // P
    letter[16].value = 10; // Q
    letter[17].value = 1;  // R
    letter[18].value = 1;  // S
    letter[19].value = 1;  // T
    letter[20].value = 1;  // U
    letter[21].value = 4;  // V
    letter[22].value = 4;  // W
    letter[23].value = 8;  // X
    letter[24].value = 4;  // Y
    letter[25].value = 10; // Z

    for (int i = 0; i < 26; i++)
    {
        letter[26 + i].value = letter[i].value;
    }
    
    
    player n1,n2;
    n1.points = 0;
    n2.points = 0;
    printf("Player 1: ");
    scanf("%s", n1.word);
    for (int i = 0; n1.word[i] != '\0'; i++)
    {
        for (int j = 0; j < 52; j++)
        {
            if (n1.word[i] == letter[j].character)
            {
                n1.points += letter[j].value;
                break;
            }
        }
    }
    printf("Player 2: ");
    scanf("%s", n2.word);
    for (int i = 0; n2.word[i] != '\0'; i++)
    {
        for (int j = 0; j < 52; j++)
        {
            if (n2.word[i] == letter[j].character)
            {
                n2.points += letter[j].value;
                break;
            }
        }
    }
    if (n1.points > n2.points)
    {
        printf("Player 1 wins!\n");
    }
    else if (n1.points < n2.points)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
    return 0;
}