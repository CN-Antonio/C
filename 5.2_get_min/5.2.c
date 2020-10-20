//输出三个数中的最小值
#include<stdio.h>
int main()
{
    double a,b,c,min;
    scanf("%lf,%lf,%lf",&a,&b,&c);
    if(a<b){b=a;}
    if(b<c){c=b;}
    printf("%lf\n",c);
    return 0;
}