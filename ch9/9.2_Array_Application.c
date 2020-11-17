/*
input：n和n个数
Output：最小值的序号，最大值的序号，均值，方差
*/
#include<stdio.h>
#include<math.h>
int FindMinElement (double dArray[], int nCount)
{
    int order=nCount-1;
    double min=dArray[nCount-1];
    for(int i=nCount-2;i>0;i--)    //倒序比较(为了得最先),直接从倒二开始
    {if(dArray[i]<=min){order=i,min=dArray[i];}} //当前<=已知min
    return order;
}
int FindMaxElement (double dArray[], int nCount)
{
    int order=nCount-1;
    double max=dArray[nCount-1];
    for(int i=nCount-2;i>0;i--)
    {if(dArray[i]>=max){order=i,max=dArray[i];}}
    return order;
}
double Average(double dArray[], int nCount)
{
    double sum=0;
    for(int i=0;i<nCount;i++){sum+=dArray[i];}
    return (sum/nCount);
}
double Variance(double dArray[], int nCount)    //方差
{
    double sum=0,avg=Average(dArray,nCount);
    for(int i=0;i<nCount;i++){sum+=pow(dArray[i]-avg,2);}
    return (sum/nCount);
}
int main()
{
    int item;
    scanf("%d",&item);
    double Array[item];
    for(int i=0;i<item;i++){scanf("%lf",&Array[i]);}
    printf("min index:%d,max index:%d\n",FindMinElement(Array,item),FindMaxElement(Array,item));
    printf("average:%lf,variance:%lf\n",Average(Array,item),Variance(Array,item));
    return 0;
}