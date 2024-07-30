#include <cs50.h>
#include <stdio.h>
#include <string.h>
bool isLetter(string str);
int main(int argc, string argv[])
{
    if (argc != 2 || !isLetter(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    string key = argv[1];

    string str = get_string("plaintext:  ");

    int index;
    for (int i = 0, length = strlen(str); i < length; i++)
    {
        //大写
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            index = str[i] - 65;
        }

        //小写
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            index = str[i] - 97;
        }
         str[i] = key[index];
    }

    printf("ciphertext: %s\n", str);



}

bool isLetter(string str)
{
    for (int i = 0, length = strlen(str); i < length; i++)
    {
        if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')))
        {
            return false;
        }
    }
    return true;
}
