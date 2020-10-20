#include<stdio.h>
int main()
{
    int year=0;
    scanf("%d",&year);
    // printf("%d\n",2100%400);

    if(year%100)    //非整百年
    {
        if(year%4)  //非闰年
        {printf("%d年不是闰年\n",year);}
        else if(!(year%4))    //闰年
        {printf("%d年是闰年\n",year);}
    }
    else if(!(year%100))  //整百年
    {
        if(year%400)  //非闰年
        {printf("%d年不是闰年\n",year);}
        else if(!(year%400))  //闰年
        {printf("%d年是闰年\n",year);}
    }


    return 0;
}