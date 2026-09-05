#include<stdio.h>

int main(void)
{
    int score;
    char scoreLevel;

    printf("请输入成绩:");
    scanf("%d", &score);

    if(score >= 0 && score <= 100)
    {
        if(score >= 90 && score <= 100 )
        {
            scoreLevel = 'A';
        }
        else if(score >= 80 && score < 90)
        {
            scoreLevel = 'B';
        }
        else if(score >= 70 && score < 80)
        {
            scoreLevel = 'C';
        }
        else if(score >= 60 && score < 70)
        {
            scoreLevel = 'E';
        }
        else if(score >= 50 && score < 60)
        {
            scoreLevel = 'F';
        }
        else if(score >= 40 && score < 50)
        {
            scoreLevel = 'G';
        }
        else if(score >= 30 && score < 40)
        {
            scoreLevel = 'H';
        }
        else if(score >= 20 && score < 30)
        {
            scoreLevel = 'I';
        }
        else if(score >= 10 && score < 20)
        {
            scoreLevel = 'J';
        }
        else if(score >= 0 && score < 10)
        {
            scoreLevel = 'K';
        }
    }
    else
    {
        printf("\n成绩只有0-100");
    }

    printf("成绩等级:%c", scoreLevel);
}