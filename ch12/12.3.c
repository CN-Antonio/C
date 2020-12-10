#include<stdio.h>
int n,aRray[100];
int *maxAddr,*minAddr;
int max,min;

void action()
{
    for(int *i=aRray;i<(aRray+n);i++)
    {
        if(*i>*maxAddr){maxAddr=i;}
        if(*i<*minAddr){minAddr=i;}
    }
}

int main()
{
    // freopen("./temp/test.in","r",stdin);
    scanf("%d",&n);
    for(int i=0;i<n;i++){scanf("%d",&aRray[i]);}
    maxAddr=aRray;
    minAddr=aRray;
    action();
    printf("max:%d,min:%d\n",*maxAddr,*minAddr);
    return 0;
}