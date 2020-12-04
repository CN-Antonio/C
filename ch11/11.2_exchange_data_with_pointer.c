#include<stdio.h>
int main()
{
    int num1,num2,temp;
    scanf("%d%d",&num1,&num2);
    int *A=&num1,*B=&num2,*Temp=&temp;
    // printf("%d %d %d\n",A,B,Temp);
    temp=*A,num1=*B,num2=*Temp;
    printf("%d %d\n",num1,num2);
    return 0;
}