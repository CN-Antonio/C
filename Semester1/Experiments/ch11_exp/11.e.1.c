#include<stdio.h>
int n,array[1000];

void ReadRealData()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++){scanf("%d",&array[i]);}
}
int FindMinElement(double dArray[], int nCount)
{
    int order=nCount-1;
    double min=dArray[nCount-1];    //初始化为尾数
    for(int i=nCount-2;i>=0;i--)     //倒序比较(为了得最先),直接从倒二开始
    {if(dArray[i]<=min){order=i,min=dArray[i];}} //当前<=已知min
    return order;
}
int FindMaxElement(double dArray[], int nCount)
{
    int order=nCount-1;
    double max=dArray[nCount-1];
    for(int i=nCount-2;i>=0;i--)
    {if(dArray[i]>=max){order=i,max=dArray[i];}}
    return order;
}
int main()
{
    freopen("./temp/test.in","r",stdin);

    // printf("%d",sizeof(array));

    ReadRealData(array,n);
    FindMinElement(array,n);
    FindMaxElement(array,n);
    return 0;
}