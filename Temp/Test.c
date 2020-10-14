#include<stdio.h>
#include<math.h>
int main()
{
    freopen("./Temp/test.in","r",stdin);
    int a,b;
    char c1,c2;
    double x,y,z;
    scanf("%d\n%d\n%c\n%c\n%lf\n%lf\n%lf",&a,&b,&c1,&c2,&x,&y,&z);
    printf("a=%d, b=%d, ",a,b);
    printf("c1='%c', c2='%c', ",c1,c2);
    printf("x=%.1lf, y=%.2lf, z=%.1lf\n",x,y,z);

    return 0;
}