#include<stdio.h>
#include<math.h>
int main()
{
    int a=0,sum=0;
    scanf("%d",a);
    if(a<=0){printf("0");}
    else if(a>0)
    {
        for(int i=1;i<=a;i++)
        {
            sum+=pow(i,3);
        }
        printf("%d",sum);
    }
    return 0;
}