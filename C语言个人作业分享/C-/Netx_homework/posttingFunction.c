#include<stdio.h>

int bubbleSort(int arr[],int length){

    int temp = 0;

    printf("排序前:");
    for (int i = 0;i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    for (int i = 0; i < length - 1; i++)
    {
        for (int j = 0; j < length - i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        
    }

    printf("排序后:");
    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void)
{
    int arr[5];
    int length = sizeof(arr) / sizeof(arr[0]);

    printf("请输入五个整数如55 46 89 77 77\n");
    printf("请在这输入:");

    for (int i = 0; i < length; i++)
    {
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, length);
}