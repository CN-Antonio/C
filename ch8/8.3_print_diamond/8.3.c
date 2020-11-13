#include<stdio.h>
int line;

void whilePrint()   //while method
{
    int k=0;
    for(int i=1;i<=line;i++)
    {
        k=1;while(k<=(line-i)){printf(" ");k++;}
        k=1;while(k<=i){printf("%d",k);k++;}
        k=i-1;while(k>0){printf("%d",k);k--;}
        printf("\n");
    }
    for(int i=(line-1);i>0;i--)
    {
        k=(line-i);while(k>0){printf(" ");k--;}
        k=1;while(k<=i){printf("%d",k);k++;}
        k=i-1;while(k>0){printf("%d",k);k--;}
        printf("\n");
    }
}
void forPrint() //for method
{
    for(int i=1;i<=line;i++)    //i=line 
    {
        
        for(int k=1;k<=(line-i);k++){printf(" ");}  //(space)
        for(int j=1;j<=i;j++){printf("%d",j);}  //j = real elements in line
        for(int j=i-1;j>0;j--){printf("%d",j);} //j = real elements in line
        printf("\n");
    }
    for(int i=(line-1);i>0;i--)
    {
        for(int k=(line-i);k>0;k--){printf(" ");}   //space
        for(int j=1;j<=i;j++){printf("%d",j);}   //real ele
        for(int j=i-1;j>0;j--){printf("%d",j);}    //real ele
        printf("\n");
    }
}

int main()
{
    scanf("%d",&line);
    switch (line)
    {
    case 0:
        printf("输入参数错误\n");
        break;
    default:
        // forPrint();
        whilePrint();
        break;
    }
    return 0;
}