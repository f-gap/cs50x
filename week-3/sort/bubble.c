//Will do implement bubble sort in C!

#include <stdio.h>
#include <stdbool.h>

void bubble(int length, int *list);
int main ()
{
    int numbers[10]; 
    for (int i = 0;i < 10; i++)
    {
        printf("Digit the %d° value of list: ", i + 1);
        scanf("%d", &numbers[i]);
    }
    bubble(10,numbers);
    printf("Ordered list: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}

void bubble(int length, int *list)
{
    bool swap;
    for (int i = 0; i < length - 1; i++)
    {
        if (swap = false)
        {
            break;
        }
        bool swap = false;
        for (int j = 0; j < length - i - 1; j++)
        {
            if (list[j+1] < list[j])
            {
                int smaller = list[j+1];
                list[j+1] = list[j];
                list[j] = smaller;
                bool swap = true;
            }
        }   
    }
}