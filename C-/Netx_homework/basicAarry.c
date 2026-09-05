#include<stdio.h>

int main(void){

    int numAarry[5];
    int length = sizeof(numAarry) / sizeof(numAarry[0]);
    int sum = 0;
    double average;
    int max,min;

    printf("请输入5个整数:80 80 80 80 80(用空格隔开)\n");
    printf("输入位置:");

    for (int num = 0; num < length; num++)
    {
        scanf("%d", &numAarry[num]);
        max = numAarry[0];
        min = numAarry[0];
    }

    for (int num = 0; num < length; num++)
    {
        sum += numAarry[num];

        if (max <= numAarry[num])
        {
            max = numAarry[num];
        }
        if (min >= numAarry[num])
        {
            min = numAarry[num];
        }
    }

    average = (double)sum / 5;

    printf("\n总和:%d", sum);
    printf("\n平均数:%.2f", average);
    printf("\n最大值:%d", max);
    printf("\n最小值:%d", min);
}