/*
Description：计算多项式值
Input:多项式项数，各项（从高次到低次包含0）系数，X的值
output:value
*/
#include<stdio.h>
#include<math.h>
double polyfunc(double dArray[], int ITEM, double X)
{
    int sum=0;
    for(int i=0;i<ITEM;i++){sum+=(dArray[i]*pow(X,i));}
    return sum;
}
int main()
{
    int item=0;
    scanf("%d",&item);
    double Array[item],x;
    for(int i=item-1;i>=0;i--){scanf("%lf",&Array[i]);}
    scanf("%lf",&x);
    printf("%.4lf\n",polyfunc(Array,item,x));
    return 0;
}