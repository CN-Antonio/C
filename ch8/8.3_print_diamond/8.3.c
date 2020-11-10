#include<stdio.h>
int line;
void PrintNumers()
{
    for(int i=1;i<=line;i++)    //i=line 
    {
        for(int k=1;k<=(line-i);k++){printf(" ");}  //(space)
        //<try> to use 'while'
        for(int j=1;j<=i;j++){printf("%d",j);}  //j = real elements in line
        for(int j=i-1;j>0;j--){printf("%d",j);} //j = real elements in line
        //</try> it!
        /*/
        int k
        do        
        {
            //
        }while();//*/
        printf("\n");
    }
    for(int i=(line-1);i>0;i--)
    {
        for(int k=(line-i);k>0;k--){printf(" ");}   //space
        for(int j=1;j<=i;j++){printf("%d",j);}   //real ele
        for(int j=i-1;j>0;j--){printf("%d",j);}    //real ele
        printf("\n");
    }
    // printf("\n");
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
        PrintNumers();
        break;
    }
    

    return 0;
}