//被6或7整除的正整数
#include<stdio.h>
#include<math.h>
int main()
{
    int num,count=0;
    scanf("%d",&num);
    for(int i=1;i<=num;i++)
    {
        if(i%6==0 || i%7==0)
        {
            if(!count)    //如果是第一个数，字符前不加逗号
            {
                printf("%d",i);
                count++;
            }
            else {printf(",%d",i);}
        }
    }
    printf("\n");
    return 0;
}