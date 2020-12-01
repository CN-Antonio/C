#include<stdio.h>
int Bsearch(int nArray[], int x, int head, int tail) //n个数，找x
{
    int is_single=0;
    if(x>nArray[tail]||x<nArray[head])
    {return 0;}
    else if(nArray[(head+tail)/2] == x)
    {return 1;}
    else if(nArray[(tail+head)/2] >x)
    {
        tail = (tail+head)/2 - 1;
        return Bsearch(nArray,x,head,tail);
    }
    else if(nArray[(tail+head)/2] < x)
    {
        head = (tail+head+1)/2;
        return Bsearch(nArray,x,head,tail);
    }
}
int Nsearch(int nArray[], int n, int x)
{
    for(int i=0;i<n;i++)
    {
        if(nArray[i]==x)return 1;
        else return 0;
    }
}
int main()
{
    int num,value;
    scanf("%d",&num);
    int array[num];
    for(int i=0;i<num;i++){scanf("%d",&array[i]);}
    scanf("%d",&value);

    printf("%d\n",Bsearch(array,value,0,num-1));
    return 0;
}