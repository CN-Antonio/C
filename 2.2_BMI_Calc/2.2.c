#include<stdio.h>
#include<math.h>
int main()
{
    float Weight,Height,BMI;
    scanf("%f,%f",&Height,&Weight);

    BMI = Weight/pow(Height,2);
    //printf("%f,%f\n",Height,Weight);
    printf("%0.1f\n",BMI);

    return 0;
}