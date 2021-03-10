/*
get_saddle_point
鞍点：该元素在矩阵所在的行中最大，所在的列中最小。
（按行按列的比较问题）
矩阵大小不超过5*5
*/
#include<stdio.h>
int row,col;    //数组大小
int ROW,COL;    //鞍点的坐标
int point_exist=0;  //默认不存在鞍点
int match_saddle[5][5];
/*/
void PrintMatch()
{
    for(int i=0;i<col;i++)
    {
        for(int j=0;j<row;j++)
        {printf("%d ",match_saddle[i][j]);}
        printf("\n");
    }
    printf("\n");
}//*/
int main()
{
    // freopen("./temp/test.in","r",stdin);
    scanf("%d%d",&row,&col);
    // int ROW,COL;    //鞍点的坐标
    // int match_saddle[row][col];
    int max,min;
    int matrix[row][col];

    for(int i=0;i<col;i++)
    {
        for(int j=0;j<row;j++)
        {
            scanf("%d",&matrix[i][j]);
            match_saddle[i][j]=1;
        }
    }
    /*/
    for(int i=0;i<col;i++)
    {
        for(int j=0;j<row;j++)
        {printf("%d ",matrix[i][j]);}
        printf("\n");
    }
    printf("\n");//*/

    //*/ judge-j列数-i行数----------------------------------------
    for(int i=0;i<col;i++)  //按列,判断一行,i=行序号
    {
        max=0,ROW=i,COL=0;   //标记
        for(int j=0;j<row;j++)      //行内判断，j=列序号
        {
            // printf("judge:(%d,%d)\n",i,j);
            if(matrix[i][j]>=max) //当前>已知最大
            {
                // printf("%d>=%d\n",matrix[i][j],max);
                if(matrix[i][j]==max)    //相等时
                {
                    // printf("%d=%d\n",matrix[i][j],max);
                    match_saddle[i][j]=0;  //二者均不符合
                }
                match_saddle[ROW][COL]=0;       //已有标记为不符合
                max=matrix[i][j],ROW=i,COL=j;   //更新标记
            }
            else
            {
                match_saddle[i][j]=0;   //当前数字不符合
            }
        }
        // PrintMatch();
    }//*/

    for(int j=0;j<row;j++)  //按行,判断一列,j=列序号
    {
        min=matrix[0][j],ROW=0,COL=j;   //标记
        for(int i=1;i<col;i++)      //列内判断，i=行序号
        {
            // printf("judge:(%d,%d)\n",i,j);
            if(matrix[i][j]<=min) //当前<=已知最小
            {
                // printf("%d<=%d\n",matrix[i][j],min);
                if(matrix[i][j]==min)    //相等时
                {
                    // printf("%d=%d\n",matrix[i][j],min);
                    match_saddle[i][j]=0;  //二者均不符合
                }
                match_saddle[ROW][COL]=0;       //已有标记为不符合
                min=matrix[i][j],ROW=i,COL=j;   //更新标记
            }
            else
            {
                match_saddle[i][j]=0;   //当前数字不符合
            }
            
        }
        // PrintMatch();
    }
    // Output
    for(int i=0;i<col;i++)
    {
        for(int j=0;j<row;j++)
        {
            if(match_saddle[i][j]==1)
            {
                point_exist=1;
                printf("第%d行第%d列是鞍点，鞍点是：%d\n",i+1,j+1,matrix[i][j]);
            }
        }
    }
    if(!point_exist){printf("没有鞍点\n");}

    return 0;
}