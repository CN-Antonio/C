#include<stdio.h>
int Num;
int array[100];
int *p=array,*MaxAddr,*MinAddr;

void Action()
{
    MaxAddr=p,MinAddr=p;
    for(int i=1;i<Num;i++)
    {
        if(array[i]>*MaxAddr){MaxAddr=p+i;}
        if(array[i]<*MinAddr){MinAddr=p+i;}
    }
    if(Num>1){printf("%d ",*MinAddr);}
    else{printf("%d\n",*MinAddr);}
    for(int *i=p+1;i<p+Num-1;i++)
    {
        if(i==MaxAddr){printf("%d ",*(p+Num-1));}
        else if(i==MinAddr){printf("%d ",*p);}
        else{printf("%d ",*i);}
    }
    if(Num>1){printf("%d\n",*MaxAddr);}
}
int main()
{
    // freopen("./temp/test.in","r",stdin);
    scanf("%d",&Num);
    for(int i=0;i<Num;i++){scanf("%d",&array[i]);}
    Action(p,5);
    
    return 0;
}