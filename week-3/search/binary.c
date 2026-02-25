#include <stdio.h>
#include <stdbool.h>

bool binary_search(int value, int length, int *list_values);
int main()
{
    int amount;
    int list_amounts[] = {10,20,30,40,50,60,70,80,90,100};
    int length = sizeof(list_amounts)/sizeof(list_amounts[0]);
    printf("Digit an amount from 10 to 100: ");
    scanf("%d", &amount);
    if (binary_search(amount,length, list_amounts) == true)
    {
        printf("This amount exist in list of amounts!\n");
        return 0;
    }
    else
    {
        printf("This amount not exist in list of amounts!\n");
        return 1;
    }
}

bool binary_search(int value, int length, int *list_values)
{
    int min = 0;
    int max = length - 1;
    int middle; 
    do
    {
        middle = (min+max)/2;
        if (value == list_values[middle])
        {
            return true;
        }
        else if(value < list_values[middle])
        {
            max = middle-1;
        }
        else if(value > list_values[middle])
        {
            min = middle+1;
        }
    } while (min <= max);
    return false;
}