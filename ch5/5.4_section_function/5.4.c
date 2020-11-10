#include<stdio.h>
int main()
{
    double i=0;
    scanf("%lf",&i);

    if(i<1)
    {printf("%lf\n",i);}
    else if(i>=1 && i<10)
    {printf("%lf\n",i*2-1);}
    else if(i >= 10)
    {printf("%lf\n",i*(-3)-11);}

    return 0;
}