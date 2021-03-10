/*
输出n个整数，将这n个数的前m个数（m小于n/2）个数和后m个数交换（数据块交换），要求m从键盘输入。
输入形式：n的值 数组中前n个元素的值 m的值
输出形式：交换位置后的数组前n个元素
*/
#include<stdio.h>
int *Exchange(int N,int M,int Array[])
{
    int temp;
    static int Array1[20];
    for(int i=0;i<N;i++){Array1[i]=Array[i];}
    //start exchange
    for(int i=1;i<=M;i++)
    {temp=Array1[N-i],Array1[N-i]=Array1[M-i],Array1[M-i]=temp;}
    return Array1;
}

int main()
{
    int n,m,*p;
    scanf("%d",&n);
    int array[n];
    for(int i=0;i<n;i++){scanf("%d",&array[i]);}
    scanf("%d",&m);
    // for(int i=0;i<n;i++){printf("%d\n",array[i]);}//Veryfied Input
    p = Exchange(n,m,array);
    //output
    for(int i=0;i<n;i++)
    {
        if(!i){printf("%d",*(p+i));}
        else {printf(" %d",*(p+i));}
    }
    printf("\n");
    return 0;
}
