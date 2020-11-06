#include<stdio.h>

int GCD(int m,int n) //(default: m>n )
{
    if(m%n==0)
        return n;
    else if(m<n)
        return GCD(n,m);
    else if(m>n)
        return GCD(m-n,n);
}

int main()
{
    int num1,num2;
    scanf("%d%d",&num1,&num2);
    printf("%d\n",num1>num2?GCD(num1,num2):GCD(num2,num1));
    return 0;
}