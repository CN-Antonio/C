/*
有x元钱，恰好买y个水果
苹果a元，西瓜b元，梨c元
输入：x,y,a,b,c  //40 100 0.4 4 0.2
输出：水果个数
*/
#include<stdio.h>

int main()
{
    // freopen("./Temp/test.in","r",stdin);
    double x,a,b,c,change;   //Money
    int y;  //Sum of the fruits
    int k;  //amount of pears

    scanf("%lf%d%lf%lf%lf",&x,&y,&a,&b,&c);
    // printf("%.2lf,%d,%.2lf,%.2lf,%.2lf\n",x,y,a,b,c);
    change=x;   //init change
    for(int i=1;(x-a*i)>=b;i++)   //loop.apple_剩余钱至少够买一个瓜
    {
        for(int j=1;(x-a*i-b*j)>=c;j++) //loop.melon_同上
        {
            k=y-i-j;    //amount of pears
            change=x - a*i - b*j - c*k;
            if(change>-0.0001 && change<0.01)
            {
                printf("apple:%d,watermelon:%d,pear:%d\n",i,j,k);
                // printf("change:%lf\n\n",change);
            }
        }
    }
    // printf("Output Done!\n");
    return 0;
}