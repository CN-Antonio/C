
/*11.e.2.c*/
#include<stdio.h>
int n,array[1000];

void ReadRealData()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++){scanf("%d",&array[i]);}
}
void DrawHistogram(int nArray[], int nCount, char ch)
{
    int max=nArray[0];
    for(int i=1;i<nCount;i++){
        if(nArray[i]>max){max=nArray[i];}
    }
    for(int i=0;i<nCount;i++)
    {
        for(int j=0; j<(int)nArray[i]; j++)
        {printf("%c",ch);}
        for(int j=max+5;j>(int)nArray[i];j--)
        {printf(" ");}
        printf("%d\n",nArray[i]);
    }
}
int main()
{
    // freopen("./temp/test.in","r",stdin);
    ReadRealData();
    DrawHistogram(array,n,'*');
    return 0;
}