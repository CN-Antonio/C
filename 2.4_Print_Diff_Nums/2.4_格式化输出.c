//输出指数、6位小数、较短形式

#include<stdio.h>
#include<math.h>
int main()
{
    double INPUT = 2018.05;
    scanf("%lf",&INPUT);

    //指数部分(12位，整数5位)
    double INDEX = INPUT;
    int Temp = 0; //指数
    // printf();
    for(Temp=0; INDEX>10; Temp++)
    {
        INDEX = INDEX/10;
        // printf("INDEX:%lf\n",INDEX);
    }
    // printf("Temp:%d\n",Temp);
    printf("%lfe+%02d\n",INDEX,Temp);

    //小数部分
    printf("%.6lf\n",INPUT);

    //自动选择形式
    printf("%g\n",INPUT);
    
    return 0;
}