#include<stdio.h>
int main()
{
    char sig;
    double n1,n2;
    scanf("%c%lf%lf",&sig,&n1,&n2);
    switch (sig)
    {
    case '+':
        printf("%.2lf+%.2lf=%.2lf\n",n1,n2,n1+n2);
        break;
    case '-':
        printf("%.2lf-%.2lf=%.2lf\n",n1,n2,n1-n2);
        break;
    case '*':
        printf("%.2lf*%.2lf=%.2lf\n",n1,n2,n1*n2);
        break;
    case '/':
        printf("%.2lf/%.2lf=%.2lf\n",n1,n2,n1/n2);
        break;
    default:
        break;
    }
    return 0;
}