#include<stdio.h>
#include<math.h>
#define PI 3.14

int main()
{
    int r;
    scanf("%d",&r);
    double S,V;

    V = 4*PI*pow(r,3)/3;   //done
    S = 4*PI*pow(r,2);//done 

    printf("%lf,%lf\n",V,S);


    return 0;
}