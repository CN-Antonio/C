#include<stdio.h>
#include<string.h>
char str1[100],str2[100],Ch;
int main()
{
    // freopen("./temp/test.in","r",stdin);
    scanf("%s%s\n%c",str1,str2,&Ch);
    char *p1=str1,*p2=str2,*pc=Ch;
    int judge=1;
    //*/
    for(int i=0;i<strlen(str1);i++)
    {
        // if(str1[i]!=Ch){judge=0;}
        if(*(p1+i) != pc){judge=0;}
    }
    for(int i=0;i<strlen(str2);i++)
    {
        // if(str2[i]!=Ch){judge=0;}
        if(*(p2+i) != pc){judge=0;}
    }//*/

    if(judge){printf("两个字符串都是由同一字符组成\n");}
    else if(!judge){printf("两个字符串不是由同一字符组成\n");}
    return 0;
}