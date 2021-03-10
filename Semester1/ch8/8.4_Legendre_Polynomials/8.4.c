#include<stdio.h>
double P(int N,double X)
{
    switch (N)
    {
    case 0:
        return 1;
        break;
    case 1:
        return X;
        break;
    default:
        return ((2*N-1)*X*P(N-1,X)-(N-1)*P(N-2,X))/N;
        break;
    }
}
int main()
{
    int n;
    double x;
    scanf("%lf%d",&x,&n);
    printf("%.4lf\n",P(n,x));
    return 0;
}    