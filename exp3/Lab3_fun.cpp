//存储run函数需要调用的各个子函数

#include <iostream> 
#include <time.h>
#include <string>
// #include <sys/types.h>
// #include <sys/stat.h>
#include <dirent.h>
// #include <cstddef>

#include "Lab3_fun.h"
#include "Lab3_data.h"

/*
*函数名称：Validate
*函数功能：判断参数是否合法
*输入参数：char* argv: 待判断参数
*返回值：0 参数非法；1 参数合法
*版本信息：create by 董逸箫，2021-04-08
*/
int Validate(char * argv)
{
    //---------------非法字符--------------
    for(int i=0;*(argv+i)!=0;i++)
    {
        printf("count:%d\n",i);
        if(strspn((argv+i),"\\/:*?\"<>|")) //对非法字符无匹配 strspn==0
            return 0;
    }
    //---------------扩展名.txt--------------
    //!!待补充！！
    //---------------扩展名.dat--------------


    return 1;
}

/*
*函数名称：charLen
*函数功能：返回字符串参数长度
*输入参数：char* argv: 待判断参数
*返回值：__int__ 字符串长度
*版本信息：create by 董逸箫，2021-04-14
*/
int charLen(char * argv)
{
    int i=0;
    while(*(argv+i)!=0)
    {i++;}
    return i;
}


/*
*函数名称：isNumber
*函数功能：判断参数是否是数字
*输入参数：char* argv: 待判断参数
*返回值：0 不合法；1 数字；2 r，随机指定
*版本信息：create by 董逸箫，2021-04-10
*/
int isNumber(char * argv)
{
    // printf("argv:%s\n",argv);
    if(strspn(argv, "0123456789")==strlen(argv) && argv!="0")
        return 1;
    else if(charLen(argv)==1 && strspn(argv, "r")!=0) //输入了r，随机指定
        return 2;
    else
        return 0;
}
/*
*函数名称：mkDir
*函数功能：判断参数为路径是否存在
*输入参数：char* argv: 需创建补全的路径
*返回值：无
*功能：使用递归，若上级目录存在，创建当前目录；若不存在，以上级目录路径为参数再次调用。
*版本信息：create by 董逸箫，2021-04-14
*/
int mkDir(char * argv)
{}

void inputPath()
{}

/*
*函数名称：saveConf
*函数功能：从参数中取出文件路径,拆分成文件名和文件存储目录,写入配置信息变量
*输入参数：文件路径
*返回值：
*版本信息：create by 董逸箫，2021-04-14
*/
void saveConf(char * argv)
{
    //
    //调用mkDir()创建目录
}


/*
*函数名称：GenDataFile
*函数功能：生成数据文件(3-2)
*输入参数：结构体
*返回值：
*版本信息：create by 董逸箫，2021-04-08
*/
void GenDataFile(CONF Data)
{
    //获取目录filesavepath
    // char Path[MAX_STR_LEN] = Data.filesavepath;
    //判断目录存在
    if(NULL == opendir(Data.filesavepath)) //不存在
    {}
    else //存在
    {}
    //  Y-拼接文件路径
    char FullPath[MAX_STR_LEN]={0};
    strcat(FullPath,Data.filesavepath);
    //  N-创建目录
    //      创建失败-return
    //

    //打开文件
    FILE *fp = NULL;
    fp = fopen(FullPath,"w+");

    int container[3]={0};
    for(int i=0; i<Data.number; i++)
    {
        for(int j=0;j<3; j++)
        {
            container[0] = random(100);
        }
    }

    // cout<<"文件生成成功！"<<endl;
}

/*
*函数名称：GetRand
*函数功能：获取一个指定范围内的随机整数
*输入参数：指定范围上限、指定范围下限
*返回值：获取到的随机整数
*版本信息：create by 董逸箫，2021-04-12
*/
int GetRand(int Max,int Min)
{
    srand((int)time(0)); //以时间为种子
    return(random(Max)-Min);
}