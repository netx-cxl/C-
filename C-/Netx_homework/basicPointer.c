#include<stdio.h>

int main(void){
    int a = 10;
    int *p = &a;
    *p = 20;
    printf("%d", a);
    printf("\n%d", &a);
    printf("\n%d", *p);
    printf("\n%d", p);
    printf("\n%p", &a);
    printf("\n%p", p);
}