#include<stdio.h>

int main(void){
    //chooseSort选择排序(其实我写的是冒泡排序但我写成了选择排序)
    int arr[5];
    int temp = 0;
    int length = sizeof(arr) / sizeof(arr[0]);

    printf("请输入五个整数如80 88 77 66 88\n");
    printf("输入位置:");
    
    for (int i = 0; i < length; i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("\n排序前:");

    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    

    for (int i = 0; i < length;i++)
    {
        for (int j = i+1; j < length; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            
        }
        
    }

    printf("\n排序后:");

    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

int BubbleSort(void)
{
    int arr[5];
    int temp;

    printf("请输入5个整数：");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]);
    }

    // 输出排序前
    printf("排序前：");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // ---- 冒泡排序 ----
    for (int i = 0; i < 4; i++)
    { // 5个数需要4轮
        for (int j = 0; j < 4 - i; j++)
        { // 每轮比较次数递减
            if (arr[j] > arr[j + 1])
            { // 如果前大后小，交换
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    // ---- 排序结束 ----

    // 输出排序后
    printf("排序后：");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}