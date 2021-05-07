//存储run函数需要调用的各个子函数
#include <iostream>
#include <time.h>
#include <string>
// #include <sys/types.h>
// #include <sys/stat.h>
#include <dirent.h>
// #include <cstddef>

#include "Lab4_fun.h"
#include "Lab4_data.h"
void GenDataFile(CONF *Data);
void GenBinFile(CONF *Data);

/*
判断参数类型，生成保存数字
*/
void Argv1(char *argv, CONF *conf)
{
    if (isNumber(argv) == 1)
    {
        conf->number = atoi(argv);
    }
    else if (isNumber(argv) == 2)
    {
        conf->number = GetRand(conf->recordcount1, conf->recordcount2);
    }
    else
    {
        printf("Parameter 1: Error");
        return;
    }
}
void Argv2(char *argv);
void Argv3(char *argv, CONF *conf)
{
    // if (strlen(argv) == 1 && strspn(argv, "t") != 0)
    // {
    //     printf("Text\n");
    //     GenTextFile(conf);
    // }
    // else if (strlen(argv) == 1 && strspn(argv, "b") != 0)
    // {
    //     printf("Bin\n");
    //     GenBinFile(conf);
    // }
    // else
    // {
    //     //Output error
    //     printf("Parameter 3: File Type Error");
    //     return;
    // }
}

/*
*函数名称：Validate
*函数功能：判断文件名参数是否合法，并存储
*输入参数：char* argv: 待判断参数; 文件名指针；文件路径指针
*返回值：0 参数非法；1 参数含扩展名合法；2 参数无扩展名
*版本信息：create by 董逸箫，2021-04-08
*/
int Validate(char *argv, char *filename, char *filesavepath)
{
    //标记
    char *slash = strrchr(argv, '/');
    char *ext = strrchr(argv, '.');

    // 剔除文件名并检查目录格式
    if (!strrchr(argv, '/') == NULL) //存在'/'进,非纯文件名
    {
        ///以"/"结尾
        if (slash - argv == strlen(argv) - 1)
        {
            return 0;
        }
    }

    //检查扩展名
    if (!strcmp(ext, ".txt") && !strcmp(ext, ".dat")) //扩展名不合法
    {
        return 0;
    }

    //获取文件名
    if (!strrchr(argv, '/') == NULL)
    {
        strcat(filename, slash + 1);
        //获取目录
        slash++, *slash = '\0';
        strcat(filesavepath, argv);
    }
    else
        strcat(filename, argv);
    return 1;
}

/*
*函数名称：isNumber
*函数功能：判断参数是否是数字
*输入参数：char* argv: 待判断参数
*返回值：0 不合法；1 数字；2 r，随机指定
*版本信息：create by 董逸箫，2021-04-10
*/
int isNumber(char *argv)
{
    // printf("argv:%s\n",argv);
    if (strspn(argv, "0123456789") == strlen(argv) && argv != "0")
        return 1;
    else if (strlen(argv) == 1 && strspn(argv, "r") != 0) //输入了r，随机指定
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
int mkDir(char *Path)
{
    //判断参数Path的存在性
    if (NULL == opendir(Path)) //当前路径不存在
    {
        //提取上级目录
        Path[strlen(Path) - 1] = '\0'; //防止"\"结尾
        int strLen = strlen(Path);
        while (Path[strLen - 1] != '/') //未遍历到“/”时
        {
            Path[strLen - 1] = 0;
            strLen--;
        }
        //得到上级目录
        if (NULL != opendir(Path)) //若上级目录存在
        {
        } // mkdir(Path.c_str());//创建当前目录
        else
            mkDir(Path); //判断上级目录

        return 1;
    }
    else //当前目录存在
    {
        return 1;
    }
}

void inputPath(char *FileName, char *FilesavePath)
{
    scanf("%s", FilesavePath);
    //Validate
    while (!Validate(FilesavePath, FileName, FilesavePath))
    {
        printf("路径非法，重新输入：");
        scanf("%s", FilesavePath);
    }
}

/*
*函数名称：ReadConfig
*函数功能：读取配置文件
*输入参数：参数结构体变量指针
*返回值：0
*版本信息：create by 董逸箫，2021-05-04
*/
int ReadConfig(CONF *conf)
{
    char tempChar[MAX_STR_LEN] = {0};
    FILE *fp = NULL;

    fp = fopen("./conf.ini", "r");

    //fgets读入换行符，fscanf不读入
    fscanf(fp, "%s", conf->filesavepath);
    fscanf(fp, "%s", conf->filename);
    fscanf(fp, "%d", &conf->maxvalue1);
    fscanf(fp, "%d", &conf->minvalue1);
    fscanf(fp, "%d", &conf->maxvalue2);
    fscanf(fp, "%d", &conf->minvalue2);
    fscanf(fp, "%d", &conf->recordcount1);
    fscanf(fp, "%d", &conf->recordcount2);

    fclose(fp);
    return 0;
}

/*
*函数名称：GenBinFile
*函数功能：生成二进制数据文件(3-2)
*输入参数：结构体
*返回值：
*版本信息：create by 董逸箫，2021-05-04
*/
void GenBinFile(CONF *Data)
{
    //检查创建文件目录

    //修改扩展名为.dat

    //动态申请空间存DATAITEM
    DATAITEM *item, *head;
    item = (DATAITEM *)malloc(sizeof(DATAITEM) + 4);
    head = item;
    for (int i = 0; i < Data->number; i++)
    {
        item->item1 = GetRand(Data->maxvalue1, Data->minvalue1);
        item->item2 = GetRand(Data->maxvalue1, Data->minvalue1);
        item->item3 = GetRand(Data->maxvalue2, Data->minvalue2);
        item++;
    }
    item = head; //point to first
    //*/

    //创建+写入dat文件
    FILE *fp;
    fp = fopen("1.dat", "wb+");
    // fprintf(fp, "%d\n", Data->number);
    // fwrite();
    for (int i = 0; i < Data->number; i++)
    {
        //写入
        fprintf(fp, "%d%d%d\n", item->item1, item->item2, item->item3);
    }
    fclose(fp);

    free(item);
}

/*
*函数名称：GenTextFile
*函数功能：生成数据文件(3-2)
*输入参数：结构体
*返回值：
*版本信息：create by 董逸箫，2021-04-08
*/
void GenTextFile(CONF *Data)
{
    // printf("path:%s\n",Data.filesavepath);
    // printf("name:%s\n",Data.filename);

    //检查创建文件目录

    //修改扩展名为.dat

    //动态申请空间存DATAITEM
    DATAITEM *item, *head;
    item = (DATAITEM *)malloc(sizeof(DATAITEM) * 3);
    head = item;
    for (int i = 0; i < Data->number; i++)
    {
        item->item1 = GetRand(Data->maxvalue1, Data->minvalue1);
        item->item2 = GetRand(Data->maxvalue1, Data->minvalue1);
        item->item3 = GetRand(Data->maxvalue2, Data->minvalue2);
        item++;
    }
    item = head; //point to first

    //*/

    //创建+写入dat文件
    FILE *fp;
    fp = fopen("1.txt", "w+");
    fprintf(fp, "%d\n", Data->number);
    for (int i = 0; i < Data->number; i++)
    {
        //写入
        fprintf(fp, "%d,%d,%d\n", item->item1, item->item2, item->item3);
        item++;
    }
    fclose(fp);

    free(head);

    /*/
    //-----------判断路径类型
    int abs = 0;
    // printf("%s\n",Data.filesavepath);
    for (int i = 0; *(Data->filesavepath + i) != 0; i++)
    {
        if (!strspn((Data->filesavepath + i), ":")) //无匹配返回0，暂定相对路径
        {
            // printf("abs:%d\n",i);
        }
        else
        {
            abs = 1;
            break;
        }
    }
    if (!abs)
    {
        strcat(Data->filesavepath, "OutputData/");
    }
    // printf("%s\n",Data.filesavepath);

    //-------------------判断并创建路径！！
    if (!mkDir(Data->filesavepath))
    {
        printf("目录创建失败\n");
        return;
    } //路径存在才继续执行

    //------------------拼接文件路径
    char FullPath[MAX_STR_LEN] = {0};
    strcat(FullPath, Data->filesavepath);
    strcat(FullPath, Data->filename);
    printf("FullPath:%s\n", FullPath);

    //------------------创建打开文件
    FILE *fp = NULL;
    fp = fopen(FullPath, "w+");

    //------------------写入条数
    fprintf(fp, "%d\n", Data->number);

    // int container[3]={0};
    DATAITEM *item, *head;
    item = (DATAITEM *)malloc(sizeof(DATAITEM));

    int tempRand = 0;
    for (int i = 0; i < Data->number; i++)
    {
        // for(int j=0;j<3;j++){container[j]=-1;} //clear
        //----------------组1
        tempRand = GetRand(Data->maxvalue1, Data->minvalue1);
        item->item1 = tempRand;

        //----------------组2
        while (tempRand == item->item1)
        {
            tempRand = GetRand(Data->maxvalue1, Data->minvalue1);
        }
        item->item2 = tempRand;
        //----------------组3
        tempRand = GetRand(Data->maxvalue2, Data->minvalue2);
        item->item3 = tempRand;
        //----------------写入文件
        fprintf(fp, "%d,%d,%d\n", item->item1, item->item2, item->item3);
    }
    fclose(fp);
    //*/
    printf("文件生成成功！\n");
}

/*
*函数名称：GetRand
*函数功能：获取一个指定范围内的随机整数
*输入参数：指定范围上限、指定范围下限
*返回值：获取到的随机整数
*版本信息：create by 董逸箫，2021-04-12
*/
int GetRand(int Max, int Min)
{
    srand(rand() + (unsigned)time(0)); //以时间+随机数为种子
    return ((rand() % (Max - Min + 1)) + Min);
}