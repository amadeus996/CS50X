#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int cash;
    do
    {
        cash = get_int("Change owed: ");
    }while(cash <= 0);

    int count = 0;

    while(cash > 0)
    {
        if (cash >= 25)
        {
            cash -= 25;
            count++;
        }
        else if(cash >= 10)
        {
            cash -= 10;
            count++;
        }
        else if(cash >= 5)
        {
            cash -= 5;
            count++;
        }
        else if(cash >= 1)
        {
            cash -= 1;
            count++;
        }
    }

    printf("%i\n", count);



}
