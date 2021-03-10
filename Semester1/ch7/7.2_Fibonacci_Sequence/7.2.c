/*Fibonacci sequence*/
#include<stdio.h>
// #include<vector>

int main()
{
    int SQ[1000],need;
    SQ[0]=0,SQ[1]=1;
    scanf("%d",&need);  //printf("need=%d\n",need);

    for(int i=2;i<=need;i++)
        {SQ[i]=SQ[i-1]+SQ[i-2];}
    printf("%d\n",SQ[need]);
    return 0;
}