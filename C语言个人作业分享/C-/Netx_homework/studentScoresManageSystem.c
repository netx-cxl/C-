#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <stdbool.h>

//结构体
struct Student{
    char name[20];
    int score;
};

// 声明函数
int score_MIN(struct Student students[],int length);
int score_MAX(struct Student students[],int length);
int scores_SUM(struct Student students[],int length);
double scores_AVERAGE(struct Student students[],int length);
int search(struct Student students[],int length,int result[], char name[],int number);

// 学生成绩管理系统
int main(void)
{
    /*----设置人数输入----*/
    int input_students_num;

    printf("=====学生成绩管理系统=====\n");
    printf("录入人数:");
    if(scanf("%d", &input_students_num)!= 1){
        printf("输入错误");
        return 0;
    }
    if(input_students_num <= 0){
        printf("输入错误");
        return 0;
    }

    while (getchar() != '\n');

    printf("\n");

    /*学生信息录入*/

    int length = input_students_num;
    //智能内存分配
    struct Student *student_container = (struct Student *)malloc(length * sizeof(struct Student));

    if (student_container == NULL)
    {
        printf("内存分配失败！\n");
        return 1;
    }

    printf("格式:名字 成绩(中间用空格,姓名的字符不能超过20个,成绩最大100最小0)\n");

    for (int i = 0; i < length;i++){
        while(1){
            int temp_score;
            char temp_name[20];

            printf("学生成绩编号%d:", i);

            char store_string[50];
            //输入 
            fgets(store_string, sizeof(store_string), stdin);

            store_string[strcspn(store_string, "\n")] = 0;

            if(sscanf(store_string,"%19s %d",temp_name,&temp_score)==2){

                if(strlen(temp_name) <= 20 && temp_score <= 100 && temp_score >= 0 ){

                    strcpy(student_container[i].name, temp_name);
                    student_container[i].score = temp_score;

                    break;

                }else
                {
                    printf("\n请重新输入格式:名字 成绩(中间用空格,姓名的字符不能超过20个,成绩最大100最小0)");
                }
            }else
            {
                printf("请按照格式输入");
            }
        }
    }
    //废案
        /*for (int i = 0; i < length; i++)
        {
            printf("学生成绩编号%d:", i);
            while (getchar() != '\n');
            scanf("%s %d", student_container[i].name, &student_container[i].score);
            if(strlen(student_container[i].name) > 20 || student_container[i].score > 100 || student_container[i].score < 0 ){
                if (i > 0)
                {
                    i -= 1;
                    while (getchar() != '\n');
                    printf("\n请重新输入格式:名字 成绩(中间用空格,姓名的字符不能超过20个,成绩最大100最小0)");
                }
            }
        }*/

        printf("\n");

    /*输出原始的成绩表*/
    printf("姓名: 成绩:\n");
    for (int i = 0;i < length;i++){
        printf("%s %d\n", student_container[i].name, student_container[i].score);
    }

    /*函数输出总结*/

    printf("\n学生成绩单的各项数据\n");
    printf("成绩最高:%s %d\n", student_container[score_MAX(student_container, length)].name, student_container[score_MAX(student_container, length)].score);
    printf("成绩最低:%s %d\n", student_container[score_MIN(student_container, length)].name, student_container[score_MIN(student_container, length)].score);
    printf("成绩总和:%d\n", scores_SUM(student_container, length));
    printf("成绩平均分:%.2f\n", scores_AVERAGE(student_container, length));

    /*搜索*/
    printf("\n查找学生成绩格式:学生姓名/_ 编号/-1(中间用空格名字编号二选一也是可以的)\n");

    bool search_ONOFF = false;
    do{
        printf("搜索栏：");

        char search_store_string[50];
        int search_number;
        char search_name[20];
        char ONOFF = '-';
        int result[length];

        fgets(search_store_string, sizeof(search_store_string), stdin);

        search_store_string[strcspn(search_store_string, "\n")] = 0;

        if(strlen(search_store_string) <= 50){

            if (sscanf(search_store_string,"%19s %d",search_name,&search_number) == 2){

                if (search(student_container,length,result,search_name,search_number) == false){

                    printf("\n查询不到\n");

                }else if(strcmp(search_name,"_") == 0 && search_number == -1){

                    printf("输入为无");

                }else if(strcmp(search_name,"_")==0 && search_number > -1 && search_number <= length){

                    printf("姓名:%s 成绩:%d\n", student_container[search(student_container, length,result, search_name, search_number)].name, student_container[search(student_container, length,result, search_name, search_number)].score);

                }
                else if (strlen(search_name) > 0 && strcmp(search_name, "_") != 0 && search_number == -1){

                    int count = search(student_container, length,result, search_name, search_number);

                    for (int i = 0; i < count;i++){
                        printf("姓名:%s 成绩:%d\n", student_container[result[i]].name, student_container[result[i]].score);
                    }
                }
                else if (strlen(search_name) > 0 && strcmp(search_name, "_") != 0 && search_number > -1 && search_number <= length){
                    printf("姓名:%s 成绩:%d\n", student_container[search(student_container, length, result, search_name, search_number)].name, student_container[search(student_container, length, result, search_name, search_number)].score);
                }

            }else{
                printf("\n不符合目标参数");
            }
            
        }else{
            printf("\n超出目标字符数量50");
        }


            printf("\n是否继续查询?请输入y否则x\n");

            scanf("%c", &ONOFF);

            while (getchar() != '\n');

            switch(ONOFF){
                case '_':
                    printf("这是默认占位符请继续\n");
                    break;
                case 'y':
                    search_ONOFF = true;
                    break;
                case 'x':
                    search_ONOFF = false;
                    break;
                default:
                    printf("这不是预期答案请继续\n");
                    break;
            }

    } while (search_ONOFF == true);

    // 释放内存
    free(student_container);
    return 0;
}

/*函数*/

int score_MIN(struct Student students[],int length){
    /*对比返回编号*/
    int number = 0;

    for (int i = 1; i < length; i++)
    {
        if (students[i].score < students[number].score)
        {
            number = i;
        }
    }

    return number;
}

int score_MAX(struct Student students[], int length)
{
    /*对比返回编号*/
    int number = 0;

    for (int i = 1; i < length; i++)
    {
        if (students[i].score > students[number].score)
        {
            number = i;
        }
    }
    return number;
}

int scores_SUM(struct Student students[], int length)
{
    /*累加返回总数*/
    int number = 0;

    for (int i = 0; i < length; i++)
    {
        number += students[i].score;
    }

    return number;
}

double scores_AVERAGE(struct Student students[], int length)
{
    /*叠加然后根据length平分*/
    double average = 0;

    average = scores_SUM(students,length)/length;

    return average;
}

int search(struct Student students[],int length,int result[], char name[],int number)
{
    /*遍历然后返回有效数*/
    int count = 0;
    bool result_Bool = false;

    if(strlen(name) > 0 && strcmp(name,"_") != 0 && number == -1){

        for (int i = 0; i < length;i++){
            if(strcmp(students[i].name,name) == 0){
                result[count] = i;
                count += 1;
                result_Bool = true;
            }
        }

        if(result_Bool == true){
            return count;
        }else{
            return result_Bool;
        }
        
    }

    if(strcmp(name,"_")==0 && number > -1){

        if(number <= length){
            return number;
        }else{
            return false;
        }

    }

    if (strlen(name) > 0 && strcmp(name, "_") != 0 && number > -1 ){

        if (number <= length)
        {
            return number;
        }
        else
        {
            return false;
        }
    }
}