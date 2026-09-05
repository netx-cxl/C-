#include<stdio.h>
#include<math.h>

float compute(float num1, char computeSymbol, float num2)
{

    float result;

    switch (computeSymbol)
    {
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case '*':
        result = num1 * num2;
        break;
    case '/':
        if (fabs(num2) < 0.000001)
        {
            printf("\n除数不为零\n");
        }
        else
        {
            result = num1 / num2;
        }
        break;
    }
    return result;
}
// 主函数用于输入并给出答案
int main(void)
{

    float num1, num2, result;
    char computeSymbol;
    char onOff = 'y';

    do{
        printf("请输入例如 1.0 + 1.0 的式子\n");

        if (scanf("%f %c %f", &num1, &computeSymbol, &num2) != 3)
        {
            printf("\nwarn-请按照正常格式输入-warn\n");
            return 1;
        }
        else
        {
            result = compute(num1, computeSymbol, num2);
            printf("\n计算结果的值:%.2f", result);
        }
        printf("\n输入y继续输入n结束\n");
        getchar();
        onOff = getchar();
    } while (onOff != '\n' && onOff == 'y' || onOff == 'Y');
}