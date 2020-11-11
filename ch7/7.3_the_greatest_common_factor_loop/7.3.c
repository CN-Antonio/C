#include<stdio.h>
int main()
{
    int num1,num2,temp;
    scanf("%d%d",&num1,&num2);
    while(num1 != num2)
    {
        if(num1<num2){temp=num1,num1=num2,num2=temp;}   //exchange num1,num2
        else if(num1>num2){num1-=num2;}
    }
    printf("%d\n",num1);
    return 0;
}