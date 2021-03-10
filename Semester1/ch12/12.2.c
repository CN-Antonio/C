#include<stdio.h>
int nValue;
double xValue;
double aArray[10000],bArray[10000];
double *addrA=aArray,*addrB=bArray;
int lena=0;

void select(double *a, double *b, int n, double x)
{
    for(double *i=b;i<(b+n);i++)
    {
        if(*i>=x && i==b)
        {printf("%.4lf",*i);}
        else if(*i>=x)
        {printf(" %.4lf",*i);}
    }
    printf("\n");
}
int main()
{
    // freopen("./temp/test.in","r",stdin);
    scanf("%d%lf",&nValue,&xValue);
    for(int i=0;i<nValue;i++)
    {scanf("%lf",&bArray[i]);}
    // printf("int");
    select(addrA,addrB,nValue,xValue);

    return 0;
}