#include<stdio.h>
void Squeeze(char s1[], char s2[], int item1, int item2)
{
    /*/test
    for(int i=0;i<item1;i++){printf("%c",s1[i]);}printf("\n");
    for(int i=0;i<item2;i++){printf("%c",s2[i]);}printf("\n");//*/
    //del
    for(int i=0;i<item2;i++)    //按s2
    {
        for(int j=0;j<item1;j++)     //对比删除s1
        {
            if(s2[i]==s1[j]){s1[j]=0;}
        }
    }
    //output
    for(int i=0;i<item1;i++){if(s1[i]!=0){printf("%c",s1[i]);}} //skip if current item is zero
    printf("\n");
}
int main()
{
    // freopen("./temp/test.in","r",stdin);
    // freopen("./temp/test.out","w",stdout);
    char str1[10]={0},str2[10]={0};
    gets(str1),gets(str2);
    //count number of str_elements
    int count1,count2,k=0;
    while(str2[++k]!=0){}count2=k;
    k=0;
    while(str1[++k]!=0){}count1=k;
    //Squeeze
    Squeeze(str1,str2,count1,count2);
    return 0;
}