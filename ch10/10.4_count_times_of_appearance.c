// 不区分大小写
#include<stdio.h>
int Count(const char Str[], char c)
{
    int count=0,k=0;
    while(Str[k]!=0)
    {
        if(Str[k]==c){count++;}
        k++;
    }
    return count;
}
int main()
{
    // freopen("./temp/test.in","r",stdin);
    char str[200]={0},obj_char;
    gets(str);
    scanf("%c",&obj_char);
    // 输入字符数目计数
    int count=0;
    while(str[++count]!=0){}
    // convert char
    if(obj_char>=65 && obj_char<=90){obj_char+=32;}
    for(int i=0;i<count;i++){if(str[i]>=65 && str[i]<=90){str[i]+=32;}}
    // output
    printf("%d\n",Count(str,obj_char));
    return 0;
}