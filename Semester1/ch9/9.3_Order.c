#include<stdio.h>

void sort(int nArray[], int n)
{
    int temp=nArray[0];
    //*/
    for(int i=0;i<n;i++)    //sort big--->small
    {
        for(int j=0;j<n;j++)
        {
            if(nArray[i]>nArray[j])
            {temp=nArray[i],nArray[i]=nArray[j],nArray[j]=temp;}
        }
    }//*/

    /*/test
    for(int i=0;i<n;i++)    //sort big--->small
    {
        for(int j=0;j<n;j++)
        {
            if(nArray[j]>temp)
            {temp=nArray[j]}
        }

    }//*/

    for(int i=0;i<10;i++)   //print
    {
        if(i==0){printf("%d",nArray[i]);}
        else{printf(" %d",nArray[i]);}
    }
    printf("\n");
}
int main()
{
    int array[10],n;
    for(int i=0;i<10;i++){scanf("%d",&array[i]);}
    scanf("%d",&n);
    sort(array,n);
    return 0;
}