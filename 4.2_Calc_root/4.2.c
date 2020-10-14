#include<stdio.h>
#include<math.h>

double Root1(int A,int B,int C)
{
    double root;
    root = 0.5*(-B+sqrt(pow(B,2)-(4*A*C)));
    return root;
}

int main()
{
    freopen("./Temp/test.in","r",stdin);
    int a,b,c;
    scanf("%d,%d,%d",&a,&b,&c);

    double r1,r2;
    r1 = (-b+sqrt(pow(b,2)-(4*a*c)))/(2*a);
    r2 = (-b-sqrt(pow(b,2)-(4*a*c)))/(2*a);
    printf("%lf,%lf\n",r1,r2);



    return 0;

}

