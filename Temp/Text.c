#include<stdio.h>
int main()
{
    double K=10.01;

    printf("%d\n",sizeof(K));

    K=(int)K;
    printf("%d\n",sizeof(K));

    return 0;
}