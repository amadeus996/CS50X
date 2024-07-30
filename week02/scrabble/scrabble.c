#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int getScore(string str);
const int score[] = {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};
int main(void)
{
    //获取两个字符串
    string s1 = get_string("Player 1: ");
    string s2 = get_string("Player 2: ");


    //获取两个字符串的分数
    int score1 = getScore(s1);
    int score2 = getScore(s2);

    if (score1 > score2)
    {
        printf("Playe 1 wins!\n");
    }
    else if(score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

    return 0;

}


int getScore(string str)
{
    int sum = 0;

    //遍历字符串中的每个字符
    for (int i = 0, length = strlen(str); i < length; i++)
    {
        //保证字符是在A-Z范围内，小写转换成大写
        if (toupper(str[i]) >= 'A' && toupper(str[i]) <= 'Z')
        {
            int index = toupper(str[i]) - 65;
            sum += score[index];
        }
    }

    return sum;

}
