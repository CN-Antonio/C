#include<stdio.h>

int f(int n, double m)
{
    return (m+n)/4;
} 

int main()
{
    double y=3;
    printf("%d\n",f(y,y+1));
    return 0;
}