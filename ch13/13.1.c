#include<stdio.h>
int n,array[4][4];

int Array_Judge()
{
    int judge=1;
    for(int i=1;i<n;i++)
    {
        for(int j=2;j<n;j++)
        {
            if(array[i][j]!=array[j][i])
            {
                judge=0;
                break;
            }
        }
    }
    return judge;
}
int Pointer_Judge()
{
    int *p=array;
    int judge=1;
    //*/
    for(int row=1;row<n;row++)
    {
        for(int col=2;col<n;col++)
        {
            if(*(p+row*4+col) != *(p+col*4+row))
            {judge=0;}
        }
    }
    return judge;
}
int main()
{
    // freopen("./temp/test.in","r",stdin);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&array[i][j]);
        }
    }

    printf("array:%d\n",Array_Judge());
    printf("pointer:%d\n",Pointer_Judge());
    return 0;
}