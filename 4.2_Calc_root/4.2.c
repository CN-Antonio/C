#include<stdio.h>
#include<math.h>

int main()
{
    freopen("./Temp/test.in","r",stdin);
    int a,b,c;
    scanf("%d,%d,%d",&a,&b,&c);
    printf("%d %d %d\n",a,b,c);
    double r1,r2;
    r1 = 0.5*(-b + sqrt(pow(b,2)-4*a*c));
    r2 = 0.5*(-b - sqrt(pow(b,2)-4*a*c));
    printf("%lf,%lf\n",r1,r2);

    return 0;

}