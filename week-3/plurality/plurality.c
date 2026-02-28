#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 10

typedef struct 
{
    char **names;
    int *votes;
    int n_candidatos;

}cand;

void selection(int length, int *list);
int main(int argc, char *argv[])
{
    int voters;
    cand candidatos;
    candidatos.n_candidatos = argc - 1;
    candidatos.names = argv;
    //aviso caso o programa seja executado errado
    if (argc == 1)
    {
        printf("Usage: plurality [candidate ...]\n");
    }
    //define um limite para o maximo de candidatos (9)
    if (argc > MAX)
    {
        return 1;
    }
    printf("Numbeer of voters: ");
    scanf("%d", &voters);
    for (int i = 1; i <= voters; i++)
    {
        char nomedovoto[50];
        bool status_vote = false;
        printf("Vote: ");
        scanf("%49[^\n]", nomedovoto);
        for (int i = 1; i < candidatos.n_candidatos; i++)
        {
            if (strcmp(nomedovoto, candidatos.names[i]))
            {
                candidatos.votes[i]++;
                status_vote = true;
            }
        }
        if (status_vote == false)
        {
            printf("Invalid vote.\n");
        }
    }
    selection(candidatos.n_candidatos, candidatos.votes);
    printf("%s", candidatos.names[argc]);
}

void selection(int length, int *list)
{
    for (int i = 0; i < length; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < length; j++)
        {
            if (list[min_idx] > list[j])
            {
                min_idx = j;
            }
        }
        int smaller = list[min_idx];
        list[min_idx] = list[i];
        list[i] = smaller;     
    }
}