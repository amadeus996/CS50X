#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int num;
    do
    {
        num = get_int("Heigh: ");
    }
    while(num < 1 || num > 8);

    for (int i = 0; i < num; i++)
    {
        for (int j = i; j < num - 1; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        printf("  ");
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
