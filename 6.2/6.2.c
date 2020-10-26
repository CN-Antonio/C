#include<stdio.h>
#include<math.h>
int main()
{
    int num;
    scanf("%d",&num);
    for(int i=1;i<=num;i++)
    {
        if(i%6==0 || i%7==0)
        {
            if(i<num){printf("%d,",i);}
            else if(i==num){printf("%d",i);}    //最后一个数不跟逗号
        }
    }
    printf("\n");
    return 0;
}