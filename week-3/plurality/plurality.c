#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 9

typedef struct 
{
    char names[50];
    int votes;
}cand;

void selection(int length, cand list[]);
int main(int argc, char *argv[])
{
    int voters;
    int length = argc - 1;
    cand candidatos[length];
    bool statusvote;

    for (int i = 0; i < length; i++)
    {
        strcpy(candidatos[i].names, argv[i+1]);
        candidatos[i].votes = 0;
    }

    //aviso caso o programa seja executado errado
    if (argc == 1)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }
    
    //define um limite para o maximo de candidatos (9)
    if (argc > MAX + 1)
    {
        return 1;
    }
    
    printf("Numbeer of voters: ");
    scanf("%d", &voters);
    
    for (int i = 0; i < voters; i++)
    {   
        statusvote = false;
        char nomedovote[50];
        printf("Vote: ");
        scanf(" %49[^\n]", nomedovote);
        for (int i = 0; i < length; i++)
        {
            if (strcmp(nomedovote, candidatos[i].names) == 0)
            {
                candidatos[i].votes++;
                statusvote = true;
            }
        }
        if (statusvote == false)
        {
            printf("Invalid vote.\n");
        }
    }
    selection(length, candidatos);
    printf("%s\n", candidatos[length - 1].names);
}

void selection(int length, cand list[])
{
    for (int i = 0; i < length - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < length; j++)
        {
            if (list[min_idx].votes > list[j].votes)
            {
                min_idx = j;
            }
        }
        cand smaller = list[min_idx];
        list[min_idx] = list[i];
        list[i] = smaller;     
    }
}