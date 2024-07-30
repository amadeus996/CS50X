#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <string.h>
bool isNumber(string str);
int key(string str);
int main(int argc, string argv[])
{
    if (argc == 1 || argc > 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    if (argc == 2 && !isNumber(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int n = key(argv[1]);
    if (n > 26)
    {
        n %= 26;
    }

    string str = get_string("plaintext:  ");

    for (int i = 0, length = strlen(str); i < length; i++)
    {
        //大写情况
        if(str[i] >= 65 && str[i] <= 90)
        {
            //溢出
            if (str[i] + n > 90)
            {
                str[i] = 'A' + (n - ('Z' - str[i]) - 1);
            }
            else
            {
                str[i] += n;
            }
        }

        //小写情况
        if(str[i] >= 97 && str[i] <= 122)
        {
            //溢出
            if (str[i] + n > 122)
            {
                str[i] = 'a' + (n - ('z' - str[i]) - 1);
            }
            else
            {
                str[i] += n;
            }
        }
    }

    printf("ciphertext: %s\n",str);
    return 0;
}

bool isNumber(string str)
{
    for (int i = 0, length = strlen(str); i < length; i++)
    {
        if(!(str[i] >= 48 && str[1] <= 57))
        {
            return false;
        }
    }

    return true;
}

int key(string str)
{
    int sum = 0;
    for (int i = 0, length = strlen(str); i < length; i++)
    {
        sum *= 10;
        sum += (str[i] - 48);
    }

    return sum;
}
