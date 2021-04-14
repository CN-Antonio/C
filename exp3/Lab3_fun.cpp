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
*返回值：0 参数非法；1 参数含扩展名合法；2 参数无扩展名
*版本信息：create by 董逸箫，2021-04-08
*/
int Validate(char * argv)
{
    //---------------非法字符--------------
    for(int i=0;*(argv+i)!=0;i++)
    {
        // printf("count:%d\n",i);
        // if(strspn((argv+i),"\\/:*?\"<>|")) //对非法字符无匹配 strspn==0
        if(strspn((argv+i),"\\*?\"<>|")) //对非法字符无匹配 strspn==0
            return 0;
    }
    //匹配扩展名：4个字符
    char Ext[4]={0};
    for(int i=0;i<4;i++)
    {
        Ext[i]=argv[strlen(argv)-i-1];
    }
    // 判断匹配
    if(Ext[0]=='t')
        if(Ext[1]=='x')
            if(Ext[2]=='t')
                if(Ext[3]=='.')
                    return 1;
    if(Ext[0]=='t')
        if(Ext[1]=='a')
            if(Ext[2]=='d')
                if(Ext[3]=='.')
                    return 1;
    return 0;
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
    else if(strlen(argv)==1 && strspn(argv, "r")!=0) //输入了r，随机指定
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
！！！未完成！！！
*/
int mkDir(char * Path)
{
    //判断参数Path的存在性
    if(NULL == opendir(Path)) //当前路径不存在
    {
        //提取上级目录
        Path[strlen(Path)-1]='\0'; //防止"\"结尾
        int strLen=strlen(Path);
        while(Path[strLen-1]!='/') //未遍历到“/”时
        {
            Path[strLen-1]=0;
            strLen--;
        }
        //得到上级目录
        if(NULL != opendir(Path)) //若上级目录存在
            {}// mkdir(Path.c_str());//创建当前目录
        else
            mkDir(Path); //判断上级目录
    }
    else //当前目录存在
    {return 1;}
}

void inputPath(char * FileName, char * FilesavePath)
{
    scanf("%s",FilesavePath);
    //Validate
    while(!Validate(FilesavePath))
    {
        printf("路径非法，重新输入：");
        scanf("%s",FilesavePath);
    }
}

/*
*函数名称：saveConf
*函数功能：从参数中取出文件路径,拆分成文件名和文件存储目录,写入配置信息变量
*输入参数：文件路径,包含目录与文件名
*返回值：无
*版本信息：create by 董逸箫，2021-04-14
*/
void saveConf(char * argv, char * FileName, char * FilesavePath)
{
    //不创建目录，仅存储配置
    char filename[MAX_STR_LEN]={0};
    int strLen=strlen(argv);
    //拆分路径与文件名
    int i=0;
    while(argv[strLen-i-1]!='/' && strLen-i-1>-1) //未遍历到“/”时
    {
        filename[i]=argv[strLen-i-1]; //倒序存
        //删字符
        i++;
    }
    // printf("i(length):%d\n",i);
    // printf("filename:%s\n",filename);
    for(int j=0;j<i;j++)    //指针存文件名
    {
        FileName[j]=filename[i-j-1]; 
    }
    // printf("%d\n",strLen-i);    //路径长度
    for(int j=0;j<(strLen-i);j++)   //指针存路径
    {
        FilesavePath[j]=argv[j];
    }
    // printf("%s\n",FilesavePath);
    // printf("%s\n",FileName);
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
    // printf("path:%s\n",Data.filesavepath);
    // printf("name:%s\n",Data.filename);
    //---------------规范路径（./??/）

    //-----------判断路径类型
    int abs=0;
    // printf("%s\n",Data.filesavepath);
    for(int i=0; *(Data.filesavepath+i)!=0; i++)
    {
        if(!strspn((Data.filesavepath+i),":")) //无匹配返回0，暂定相对路径
        {
            // printf("abs:%d\n",i);
        }
        else
        {
            abs=1;
            break;
        }
    }
    if(!abs)
    {
        strcat(Data.filesavepath,"OutputData/");
    }
    // printf("%s\n",Data.filesavepath);
    
    //-------------------判断并创建路径！！
    if(!mkDir(Data.filesavepath)) 
    {
        printf("目录创建失败\n");
        return;
    }//路径存在才继续执行

    //------------------拼接文件路径
    char FullPath[MAX_STR_LEN]={0};
    strcat(FullPath,Data.filesavepath);
    strcat(FullPath,Data.filename);
    // printf("FullPath:%s\n",FullPath);

    //------------------创建打开文件
    FILE *fp = NULL;
    fp = fopen(FullPath,"w+");

    //------------------写入条数
    fprintf(fp,"%d\n", Data.number);

    int container[3]={0};
    int tempRand=0;
    for(int i=0; i<Data.number; i++)
    {
        for(int j=0;j<3;j++){container[j]=-1;} //clear
        //----------------组1
        tempRand=GetRand(Data.maxvalue1,Data.minvalue1);
        container[0]=tempRand;
        
        //----------------组2
        while(tempRand==container[0])
        {tempRand=GetRand(Data.maxvalue1,Data.minvalue1);}
        container[1]= tempRand;
        //----------------组3
        tempRand=GetRand(Data.maxvalue2,Data.minvalue2);
        container[2]= tempRand;
        //----------------写入文件
        fprintf(fp,"%d,%d,%d\n",container[0],container[1],container[2]);
    }
    fclose(fp);
    printf("文件生成成功！\n");
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