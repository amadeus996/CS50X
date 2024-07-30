#include <cs50.h>
#include <stdio.h>
#include <string.h>
int getLetterCount(string str);
int getSentenceCount(string str);
int main(void)
{
    string text = get_string("Text: ");

    //计算等级
    int L = getLetterCount(text);
    int S = getSentenceCount(text);
    int index = 0.0588 * L - 0.296 * S - 15.8;

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

    return 0;
}

//统计每一百个单词里面的字母数量
int getLetterCount(string str)
{
    int wordCount = 0;
    int letterCount = 0;


    for (int i = 0, length = strlen(str); i < length; i++)
    {
        //确认是不是字母，是字母才是单词
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
        {
            letterCount++;
        }
        //不是字母就是遇到了标点符号，那之前就算是一个单词，单词数量+1
        if((str[i] == '.' || str[i] == '!' || str[i] == '?') ||(str[i] == ' ' && ((str[i - 1] >= 'a' && str[i - 1] <= 'z') || (str[i - 1] >= 'A' && str[i - 1] <= 'Z'))))
        {
            wordCount++;
        }
    }

    float result = ((float)letterCount / (float)wordCount) * 100.0;
    return result;
}

//统计每一百个单词中的句子数量
int getSentenceCount(string str)
{
    int wordCount = 0;
    int sentenceCount = 0;
    for (int i = 0, length = strlen(str); i < length; i++)
    {
        if(str[i] == '.' || str[i] == '!' || str[i] == '?')
        {
            sentenceCount++;
            wordCount++;
        }
        else if(str[i] == ' ' && ((str[i - 1] >= 'a' && str[i - 1] <= 'z') || (str[i - 1] >= 'A' && str[i - 1] <= 'Z')))
        {
            wordCount++;
        }
    }

    float result = ((float)sentenceCount / (float)wordCount) * 100.0;
    return result;

}
