#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>

/*本视频用于证明我还活着还有记录下我区区的技术，之前已经录了一个小时但很显然出了点小问题所以从这截开始重新录还有我其实开着麦克风
并不是哑巴只是我的口才实在不好，好那么继续吧'~'*/

/*界面循环*/
/*
do{
功能1 功能2 功能3 功能4
输入功能名称：
}while(退出开关是否为false);
*/

/*通讯人结构体*/
struct contacts
{

    char phone_number[12];
    char contact_name[20];
};

/*预声明函数*/

void addContacts(struct contacts **Contacts,int *index, char name[], char number[]);//t 给联系人的容器添加联系人
void removeContacts(struct contacts **Contacts, int *length,int number);//t 给联系人的容器删除联系人
int reviewContacts(struct contacts Contacts[], int length);//t 浏览联系人
char check_ContactsData_Validity(char contact_name[], char contact_phone_number[]); // t 检验字符人数20 和 11
char input_str(char store_str[],int size);//t 输入字符 
int check_search(struct contacts Contacts[], int length, char contacts_name[], char phone_number[]);//T 检查联系人是否在联系人容器
int getContactNumber(struct contacts Contacts[], int length, char contacts_name[], char phone_number[]);//t 获取联系人的容器的联系人下标 返回数字

int main(void)
{
    char temp_name[20];
    char temp_number[12];
    int length = 0;
    struct contacts *contacts_P = NULL;
    char store_input_str[100];
    int size = sizeof(store_input_str);
    bool menu_OnOff = true;

    do{
        printf("\n\n===============================================\n");
        printf("=               通讯录主菜单                   =\n");
        printf("===============================================\n\n");
        printf("===============================================================\n");
        printf("=添加联系人1 = 删除联系人2 = 查找联系人3 = 显示所有联系人4 = 退出5=\n");
        printf("===============================================================\n");

        printf("请输入功能键号码:");

        switch (getchar())
            
        {
            case '1':
            /*添加联系人*/

                while (getchar() != '\n');
                length += 1;
                contacts_P = (struct contacts *)realloc(contacts_P,length * sizeof(struct contacts));

                if (contacts_P == NULL)
                {
                    printf("内存分配失败！\n");
                    length--;
                    break;
                }

                

                printf("输入联系人%d的名称:",length);

                input_str(store_input_str,size);
                sscanf(store_input_str, "%20s", temp_name);

                if (check_ContactsData_Validity(temp_name, "_") && check_search(contacts_P, length, temp_name, "_") == 0)
                {

                    printf("输入联系人的号码：");

                    input_str(store_input_str,size);
                    sscanf(store_input_str, "%11s", temp_number);

                    if (check_ContactsData_Validity("_", temp_number) && check_search(contacts_P, length, "_", temp_number) == 0)
                    {
                        addContacts(&contacts_P, &length, temp_name, temp_number);
                        break;
                    }else{
                        printf("不合法请重新输入/或联系人姓名已存在");
                        break;
                    }
                }
                else
                {
                    printf("不合法请重新输入");
                    length -= 1;
                    break;
                }

                break;

            case '2':
            /*删除联系人*/
                while (getchar() != '\n');
                printf("请选择查询方式:x(name) or y(number)");

                switch (getchar())
                {
                case 'y':

                    printf("输入联系人的号码：");

                    input_str(store_input_str, size);

                    // char temp_name[20];
                    // char temp_number[11];

                    sscanf(store_input_str, "%11s", temp_number);

                    if (check_ContactsData_Validity("_", temp_number) && check_search(contacts_P, length, "_", temp_number) == 2)
                    {
                        removeContacts(&contacts_P, &length, getContactNumber(contacts_P, length, "_", temp_number));
                        break;
                    }
                    else if (check_ContactsData_Validity("_", temp_number) && check_search(contacts_P, length, "_", temp_number) == 0)
                    {
                        printf("不存在的联系人\n");
                        break;
                    }
                    else
                    {
                        printf("不合法请重新输入\n");
                        break;
                    } /*那你们也看到了吧实在面对镜头有点无法组织语言@ < @*/

                    break;

                case 'x':

                    printf("输入联系人的名称：");

                    // char temp_name[20];

                    input_str(store_input_str, size);
                    sscanf(store_input_str, "%20s", temp_name);

                    if (check_ContactsData_Validity(temp_name, "_") && check_search(contacts_P, length, temp_name, "_") == 1)
                    {
                        removeContacts(&contacts_P, &length, getContactNumber(contacts_P, length, temp_name, "_"));
                        break;
                    }
                    else if (check_ContactsData_Validity(temp_name, "_") && check_search(contacts_P, length, temp_name, "_") == 0)
                    {
                        printf("不存在的联系人\n");
                        break;
                    }
                    else
                    {
                        printf("不合法请重新输入");
                        break;
                    }

                    default:

                        while (getchar() != '\n')
                            ;
                        printf("无效\n");
                        break;
                    }
                break;

            case '3':
            /*查询联系人*/
                while (getchar() != '\n');
                printf("查询联系人:名字 号码\n");
                printf("查询联系人:");

                // char temp_name[20];
                // char temp_number[11];

                input_str(store_input_str, size);
                sscanf(store_input_str, "%20s %11s", temp_name, temp_number);

                int validity_index = check_ContactsData_Validity(temp_name, temp_number);
                int get_index;

                switch (validity_index)
                {
                case 1:
                    get_index = getContactNumber(contacts_P, length, temp_name, "_");
                    break;
                case 2:
                    get_index = getContactNumber(contacts_P, length, "_", temp_number);
                    break;
                case 3:
                    get_index = getContactNumber(contacts_P, length, temp_name, temp_number);
                    break;
                case 0:
                    get_index = -1;
                    break;
                }

                if (get_index != -1)
                {
                    printf("名字:%s 电话号码:%s\n", contacts_P[get_index].contact_name, contacts_P[get_index].phone_number);
                }
                else
                {
                    printf("查询不到\n");
                }
                break;

            case '4':
                /*显示所有联系人*/
                printf("查询结果如下:\n");

                reviewContacts(contacts_P, length);

                break;

            case '5':
                /*退出*/
                menu_OnOff = false; // 退出
                break;

            default:

                while (getchar() != '\n')
                    ;
                printf("无效\n");
                break;
        }  

    } while (menu_OnOff == true);
}

char input_str(char store_str[],int size){

    fgets(store_str, size, stdin);

    store_str[strcspn(store_str, "\n")] = 0;

    printf("\n");

    return 0;
}

void addContacts(struct contacts **Contacts,int *index, char name[], char number[])
{
    int id = *index;
    id--;
    strcpy((*Contacts)[id].contact_name, name);
    strcpy((*Contacts)[id].phone_number, number);
}

void removeContacts(struct contacts **Contacts, int *length, int number){

    if (number < 0 || number >= *length)
    {
        printf("索引无效！\n");
        return;
    }

    
    for (int i = number; i < (*length-1); i++)
    {
        (*Contacts)[i] = (*Contacts)[i + 1];
    }

    (*length)--;
    
    if(*length == 0){
        free(*Contacts);
        *Contacts = NULL;
    } 
    else
    {
        struct contacts *temp = (struct contacts *)realloc(*Contacts, (*length) * sizeof(struct contacts));

        if (temp != NULL)
        {
            *Contacts = temp;
        }
    }

}

int reviewContacts(struct contacts Contacts[], int length){

    for (int i = 0; i < length; i++){
        printf("联系人姓名:%s 联系人电话:%s\n", Contacts[i].contact_name, Contacts[i].phone_number);
    }

    printf("查阅完毕\n");

    return 0;
}

int check_search(struct contacts Contacts[], int length, char contacts_name[], char phone_number[]){
    // 返回1是有！=1 是无

    for (int i = 0;i < length;i++){
        int name_CR = (strcmp(Contacts[i].contact_name, "_") != 0) && (strcmp(Contacts[i].contact_name, contacts_name) == 0);
        int phone_CR = (strcmp(phone_number, "_") != 0) && (strcmp(Contacts[i].phone_number, phone_number) == 0);

        if (name_CR && phone_CR){
            return 3; // 都匹配
        }
        else if (name_CR){
            return 1; // 只匹配姓名
        }
        else if (phone_CR){
            return 2; // 只匹配电话
        }
    }
    return 0;
}

int getContactNumber(struct contacts Contacts[], int length, char contacts_name[], char phone_number[]){

    int _IF_Result = check_search(Contacts, length, contacts_name, phone_number);

    switch (_IF_Result)
    {
    case 1:
        for(int i = 0; i < length;i++){
            if(strcmp(Contacts[i].contact_name, contacts_name)==0){
                return i;
            }
        }

        break;

    case 2:
        for (int i = 0; i < length; i++)
        {
            if (strcmp(Contacts[i].phone_number, phone_number) == 0)
            {
                return i;
            }
        }

        break;

    case 3:
        for (int i = 0; i < length; i++)
        {
            if (strcmp(Contacts[i].contact_name, contacts_name) == 0)
            {
                return i;
            }
        }

        break;

    case 0:
        break;

    default:
        break;
    }
}

char check_ContactsData_Validity(char contact_name[], char contact_phone_number[])
{
    /*1.检验是否在20和11位以下或等于
      2.通过to_int转换不通过就证明号码不通过    
    */
    int name_CR = (strcmp(contact_name, "_") != 0);
    int number_CR = (strcmp(contact_phone_number, "_") != 0);
    long temp;

    if(name_CR && number_CR){
        if (strlen(contact_name) <= 20 && strlen(contact_phone_number) == 11 && sscanf(contact_phone_number, "%d", &temp))
        {
            return 3;
        }
        else
        {
            return 0;
        }
    }else if(name_CR){
        if (strlen(contact_name) <= 20){
            return 1;
        }else{
            return 0;
        }
    }else if(number_CR){
        if (strlen(contact_phone_number)==11&&sscanf(contact_phone_number,"%d",&temp)){
            return 2;
        }else{
            return 0;
        }
    }else{
        return 0;
    }

}
/* byebye */