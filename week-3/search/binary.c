#include <stdio.h>
#include <stdbool.h>

bool binary_search(int value, int lenght, int *list_values);
int main()
{
    int amount;
    int list_amounts[] = {10,20,30,40,50,60,70,80,90,100};
    printf("Digit an amount from 10 to 100: ");
    scanf("%d", &amount);
    if (binary_search(amount,sizeof(list_amounts), list_amounts) == true)
    {
        printf("This amount exist in list of amounts!\n");
    }
    else
    {
        printf("This amount not exist in list of amounts!\n");
    }
}

bool binary_search(int value, int lenght, int *list_values)
{
    do
    {
        if (value == list_values[lenght/2])
        {
            return true;
        }
        else if(value > list_values[lenght/2])
        {
            
        }
        
    } while (true);
    
}