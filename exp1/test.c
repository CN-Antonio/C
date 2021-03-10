
#include "stdafx.h"
typedef struct node
{
    int x, y;
} anstype;
int matrix[1000][1000];
anstype ans[1000];
int lenx = 0, leny = -1;
void prepare();
void work();
void printans();
int main()
{
    prepare();
    // work();
    // printans();
    return 0;
}
void prepare()
{
    //init
    char tem;
    int Intem = -1;
    lenx = 0;
    ans[0].x = 0;
    printf("\n");
    //input
    while (1)
    {
        leny = 0;
        while (1)
        {
            while (tem = getchar(), tem == ' ')
            {
            };
            printf("%d\n",tem);
        }
    }
}