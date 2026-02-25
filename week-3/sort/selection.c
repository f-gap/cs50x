//Will do implement selection sort in C!

#include <stdio.h>

void selection(int length, int *list);
int main ()
{
    int numbers[10]; 
    for (int i = 0;i < 10; i++)
    {
        printf("Digit the %d° value of list: ", i + 1);
        scanf("%d", &numbers[i]);
    }
    selection(10,numbers);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");
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