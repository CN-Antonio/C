//求pi的近似值
#include<stdio.h>
#include<math.h>
int main()
{
    int num,k=1;
    double term1,term2,term3;
    double pi=0;
    scanf("%d",&num);

    for(double i=1;i<=num;i++) //大项
    {
        term1=1;    //init term1
        //*/
        for(int j=2;j<=i;j++)//小项1
        {   
            term1*=(j*2-3);
            term1/=(j*2-2);
        }//*/
        // printf("%.0lf.1=%lf\n",i,term1);
        term2=1/(2*i-1);    //printf("%.0lf.2=%lf\n",i,term2);
        term3=pow(0.5,2*i-1);   //printf("%.0lf.3=%lf\n\n",i,term3);
        pi+=(term1*term2*term3);
    }

    printf("%.9lf\n",6*pi);
    return 0;
}