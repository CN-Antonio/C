/*
判断是否回文字符串
*/
#include<stdio.h>
int TENET(char Str[],int item)
{
    int judge=1;
    for(int i=0;i<item;i++){if(Str[i]!=Str[item-1-i]){judge=0;}}
    return judge;
}

int main()
{
    char str[20]={0};
    gets(str);
    int count=0;
    while(str[++count]!=0){/*count++;*/}    //输入字符数目计数

    if(TENET(str,count)){printf("是回文的\n");}         //is TENET
    else if(!TENET(str,count)){printf("不是回文的\n");} //is not TENET

    return 0;
}