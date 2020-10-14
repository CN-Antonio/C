#include<stdio.h>
#include<math.h>

#define PI 3.14

int main()
{
    freopen("./Temp/test.in","r",stdin);
    double a,b,c,d,s,S,degree;
    scanf("%lf%lf%lf%lf%lf",&a,&b,&c,&d,&degree);
    degree/=2;

    s=(a+b+c+d)/2;
    S=sqrt((s-a)*(s-b)*(s-c)*(s-d)-a*b*c*d*pow(cos(degree),2));
    printf("%lf\n",pow(cos(degree),2));
    printf("%lf\n",S);


    return 0;
}