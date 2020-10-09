#include<stdio.h>
#include<math.h>
int main()
{
    int a,b;
    char c1,c2;
    double x,y,z;
    scanf("%d%d%c%c%lf%lf%lf",&a,&b,&c1,&c2,&x,&y,&z);
    printf("%d\n%d\n%d\n%d\n",a,b,c1,c2);
    printf("%lf\n%lf\n%lf\n",x,y,z);

    return 0;
}