#include<stdio.h>
#include<math.h>
#define PI 3.14

int main()
{
    int r;
    scanf("%d",&r);
    double S,V;

    V = (4/3)*PI*pow(r,3); 
    S = 4*PI*pow(r,2);

    printf("%lf,%lf\n",V,S);


    return 0;
}