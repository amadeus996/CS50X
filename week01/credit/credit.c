#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
int numberLen(long number);
int numberHeader(long number);
bool luhn(long number);
int main(void)
{
    long number = get_long("Number: ");
    int len = numberLen(number);
    int header = numberHeader(number);
    //运通卡
    if(len == 15)
    {
        //满足开头
        if(header == 34 || header == 37)
        {
            if(luhn(number))
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }

    }
    //万事达卡或者visa卡
    else if(len == 16)
    {
        //万事达卡51、52、53、54 或 55开头
        if(header <= 55 && header >= 51)
        {
            if(luhn(number))
            {
                printf("MASTERCARD\n");
            }
        }
        //所有 Visa 卡号都以 4 开头
        else if(header / 10 == 4)
        {
            if(luhn(number))
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }

        }
        else
        {
            printf("INVALID\n");
        }

    }
    //visa卡
    else if(len == 13)
    {
        //满足开头
        if(header / 10 == 4)
        {
            if(luhn(number))
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }

        }
        else
        {
            printf("INVALID\n");
        }

    }
    else
    {
        printf("INVALID\n");
    }


}

int numberLen(long number)
{
    int count = 0;
    while(number > 0)
    {
        number /= 10;
        count++;
    }
    return count;
}

int numberHeader(long number)
{
    while(number >= 100)
    {
        number /= 10;
    }

    return number;
}

bool luhn(long number)
{
    long temp = number;
    int sumLine = 0;
    int sumOther = 0;

    for(int i = 0; temp > 0; i++)
    {
        if(i % 2 != 0)
        {
            int num = temp % 10;
            if(num * 2 >= 10)
            {
                num *= 2;
                sumLine += num % 10;
                num /= 10;
                sumLine += num;
            }
            else
            {
                sumLine += num * 2;
            }
        }
        else
        {
            sumOther += temp % 10;
        }

        temp /= 10;
    }

    int sum = sumOther + sumLine;
    //满足条件
    if(sum % 10 == 0)
    {
        return true;
    }

    //不满足条件
    return false;
}
