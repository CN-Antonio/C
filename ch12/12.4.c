#include<stdio.h>
char s1[1000],s2[1000];
int lens1=0,lens2=0;
int action(int lenS1,int lenS2)
{
    int count1=0,count2=0; //default:No
    for(char *i=s1;i<(s1+lenS1);i++)
    {
        for(char *j=s2;j<(s2+lenS2);j++)
        {
            if(*i==*j)
            {
                count1++;
                break;
            }
        }
    }
    for(char *i=s2;i<(s2+lenS2);i++)
    {
        for(char *j=s1;j<(s1+lenS1);j++)
        {
            if(*i==*j)
            {
                count2++;
                break;
            }
        }
    }
    if(count1==lenS1&&count2==lenS2){return 1;}
    else            {return 0;}
}
int main()
{
    // freopen("./temp/test.in","r",stdin);
    gets(s1);
    gets(s2);
    while(s1[++lens1]){}
    while(s2[++lens2]){}
    if(action(lens1,lens2))      {printf("s1可以由s2重排得到\n");}
    else if(!action(lens1,lens2)){printf("s1不能由s2重排得到\n");}
    return 0;
}