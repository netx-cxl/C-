#include<stdio.h>

int main(void){

    int arr[5] = {5, 4, 8, 7, 5};
    int *P_head = arr;
    int length = sizeof(arr) / sizeof(arr[0]);

    printf("原始数组:");
    for (int i = 0; i < length; i++)
    {
        printf("%d ", *(P_head + i));
    }
    printf("\n");

    for (int i = 0; i < length;i++)
    {
        *(P_head + i) *= 2;
    }

    printf("*2后的数组:");
    for (int i = 0; i < length;i++)
    {
        printf("%d ", *(P_head + i));
    }
    printf("\n");
}