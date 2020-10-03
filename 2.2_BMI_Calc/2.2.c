/*BMI=体重÷ (身高×身高)*/

#include<stdio.h>
#include"math.h"
int main()
{
    double Weight=0,Height=0,BMI=0;
    scanf("%lf,%lf",&Height,&Weight);

    // BMI = Weight/pow(Height , 2);
    BMI = Weight/(Height*Height);
    //printf("%f,%f\n",Height,Weight);
    printf("%0.1f\n",BMI);

    return 0;
}