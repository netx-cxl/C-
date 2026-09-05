#include<stdio.h>

//传值和传地址的区别

int SwapValue(int x,int y){
    int temp = x;
    x = y;
    y = temp;
}

int SwapAddress(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main(void){
    int x, y;
    x = 5;
    y = 6;

    printf("原始x:%d y:%d\n",x,y);

    SwapValue(x, y);
    printf("传值x:%d y:%d\n", x, y);

    SwapAddress(&x, &y);
    printf("传地址x:%d y:%d\n", x, y);
}