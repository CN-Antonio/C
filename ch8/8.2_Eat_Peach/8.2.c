/*
一只猴子第一天摘下若干个桃子，当即吃了一半，还不过瘾，又多吃了一个。第二天早上又将剩下的桃子吃掉一半，又多吃了一个。以后每天早上都吃了前一天剩下的一半零一个。到第N天早上想再吃时，见只剩一个桃子了。求第一天共摘多少桃子？
输入：天数N。
输出：输出第一天摘下的桃子数。
*/
#include<stdio.h>
long long int peach=1;
int main()
{
    int day=0;
    scanf("%d",&day);
    for(int i=1 ; i<day ; i++)
    {peach = (peach + 1)*2;}
    printf("%lld",peach);
    return 0;
}