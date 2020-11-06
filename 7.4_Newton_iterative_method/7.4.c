/*
Request Root of the Function
Output result when difference between former and present result is lower than 0.0001
x(n+1)=x(n)-F(x(n))/f(x(n))
F(x)=ax^3+bx^2+cx+d=0
f(x)=3ax^2+2bx+c
*/
#include<stdio.h>
#include<math.h>
int a,b,c,d;
// int i=0;

/*double F(double x)  //Origin Function
{//printf("F=%lf\n", a*pow(x,3)+b*pow(x,2)+c*x+d );
    return (a*pow(x,3)+b*pow(x,2)+c*x+d);}
double f(double x)  //Derivative function
{//printf("f=%lf\n",3*a*pow(x,2)+2*b*x+c);
    return (3*a*pow(x,2)+2*b*x+c);}*/
double loop(double x)
{
    // printf("loop:%d\n",++i);
    // printf("x=%lf\n",x);
    // double X=x-F(x)/f(x);
    double X=x-(a*pow(x,3)+b*pow(x,2)+c*x+d)/(3*a*pow(x,2)+2*b*x+c);
    // printf("|X-x|*10000=%d\n",((abs(x*10000-X*10000))));
    // printf("X=%lf\n\n",X);
    return ((fabs(x-X))<0.0001)?X:loop(X);    
}

int main()
{
    // freopen("./Temp/test.in","r",stdin);
    double x0;
    scanf("%d,%d,%d,%d,%lf",&a,&b,&c,&d,&x0);
    printf("%.5lf\n",loop(x0));
    return 0;
}