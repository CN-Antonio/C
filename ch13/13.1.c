#include<stdio.h>
#include<stdlib.h>
int n,array[100][100],pointer[10000];

int Array_Judge()
{
    int judge=1;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
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
/*/
int Pointer_Judge()
{
    int *p=pointer;
    p = (int*)realloc(p, )
    int judge=1;
    //
    int *ar = (int(*)[n])malloc(sizeof(int) * n * n);

    for(int row=0;row<n;row++)
    {
        for(int col=1;col<n;col++)
        {
            printf("%p\n",p[row][col]);
            {judge=0;}
        }
    }
    return judge;
}//*/
int main()
{
    // freopen("./temp/test.in","r",stdin);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&array[i][j]);
            pointer[i*n + j] = array[i][j];
        }
    }
    // for(int i=0;i<n*n;i++){printf("%d ",pointer[i]);}

    printf("array:%d\n",Array_Judge());
    printf("pointer:%d\n",Array_Judge());
    return 0;
}