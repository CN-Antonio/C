/****************************************************\
作者信息：
     作业完成人：董逸箫    学号： 20281205
**********************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// #include<CodeForLab14.h>

char *SzLine;
char Line[1000];

int CountWordsInOneLine(const char *szLine)
{
	int nWords = 0;
	for(char *i=szLine ; *i!=0 ; i++)
    {
        if(*i==' '){nWords++;}
    }
    nWords++;

	return nWords;
}
void Fill()
{
    Line[0]='A',Line[1]='z';
}

int main()
{
    freopen("./temp/test.in","r",stdin);
    gets(Line);
    SzLine=Line;
    // Fill();
    printf("%d\n",CountWordsInOneLine(SzLine));
    return 0;
}