/*
Compare which one is bigger
input：1,2↵
output：2↵
*/

#include<stdio.h>
int main(void)
{
    int a=0,b=0;
    scanf("%d,%d",&a,&b);
    //printf("%d%d\n",a,b);  //test input
    if(a>b)
        printf("%d\n",a);
    else
        printf("%d\n",b);
    return 0;
}