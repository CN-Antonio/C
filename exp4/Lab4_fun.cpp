//存储run函数需要调用的各个子函数
#include <iostream>
#include <time.h>
#include <string>
#include <vector>
#include <io.h>
#include <list>
#include <math.h>
#include <direct.h>
// #include <sys/types.h>
// #include <sys/stat.h>
#include <dirent.h>
// #include <cstddef>

#include "Lab4_fun.h"
#include "Lab4_data.h"

using namespace std;
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
    if (strrchr(argv, '/')) //存在'/'进,非纯文件名
    {
        ///以"/"结尾,错误返回
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
    if (strrchr(argv, '/'))
    {
        memset(filename, 0, sizeof(filename));
        strcat(filename, slash + 1);
        //获取目录
        slash++, *slash = '\0';
        memset(filesavepath, 0, sizeof(filesavepath));
        strcat(filesavepath, argv);
    }
    else
        strcat(filename, argv);

    //字符合法性检查
    // filename
    for (int i = 0; *(filename + i) != 0; i++)
    {
        // printf("count:%d\n",i);
        if (strspn((filename + i), "\\/:*?\"<>|")) //对非法字符无匹配 strspn==0
            return 0;
    }
    // filesavepath
    for (int i = 0; *(filename + i) != 0; i++)
    {
        // printf("count:%d\n",i);
        if (strspn((filesavepath + i), "*?\"<>|")) //对非法字符无匹配 strspn==0
            return 0;
    }
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
    else if (!strcmp(argv, "r")) //输入了r，随机指定
        return 2;
    else
        return 0;
}

//得到文件路径的目录
string GetPathDir(string filePath)
{
    string dirPath = filePath;
    size_t p = filePath.find_last_of('\\');
    if (p != -1)
    {
        dirPath.erase(p);
    }
    return dirPath;
}

//创建多级目录
// void CreateMultiLevel(string dir)
void mkDir(string dir)
{
    if (_access(dir.c_str(), 00) == 0)
    {
        return;
    }

    list<string> dirList;
    dirList.push_front(dir);

    string curDir = GetPathDir(dir);
    while (curDir != dir)
    {
        if (_access(curDir.c_str(), 00) == 0)
        {
            break;
        }

        dirList.push_front(curDir);

        dir = curDir;
        curDir = GetPathDir(dir);
    }

    for (auto it : dirList)
    {
        _mkdir(it.c_str());
    }
}

void inputPath(char *FileName, char *FilesavePath)
{
    char *filePath;
    filePath = (char *)malloc(MAX_STR_LEN);
    scanf("%s", filePath);
    //Validate & save
    while (!Validate(filePath, FileName, FilesavePath))
    {
        printf("路径非法，重新输入：");
        scanf("%s", filePath);
    }
    free(filePath);
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
*函数名称：GenFile
*函数功能：生成数据文件(3-2)
*输入参数：结构体,1-仅文本文件，2-仅二进制文件，3-双文件
*返回值：
*版本信息：create by 董逸箫，2021-05-04
*/
void GenFile(CONF *Data, int type)
{
    //检查创建文件目录
    mkDir(Data->filesavepath);

    //动态申请空间存DATAITEM
    DATAITEM *item, *head;
    char *ext;
    item = (DATAITEM *)malloc(sizeof(DATAITEM) * Data->number);
    head = item;
    clock_t clockBegin, clockEnd;
    clockBegin = clock();

    for (int i = 0; i < Data->number; i++)
    {
        item->item1 = GetRand(Data->maxvalue1, Data->minvalue1);
        item->item2 = GetRand(Data->maxvalue1, Data->minvalue1);
        item->item3 = GetRand(Data->maxvalue2, Data->minvalue2);
        item++;
    }
    clockEnd = clock();
    printf("%dms\n", (double)clockBegin / CLK_TCK);
    printf("%dms\n", (double)clockEnd / CLK_TCK);
    printf("存入结构体数组耗时%dms\n", (clockEnd - clockBegin) / CLK_TCK);
    item = head; //point to first

    //dat部分
    //纠正扩展名
    ext = strrchr(Data->filename, '.') + 1;
    *ext = '\0';
    strcat(Data->filename, "dat");

    //创建+写入dat文件
    FILE *fp;
    if (type == 2 || type == 3)
    {
        clockBegin = clock();
        fp = fopen(strcat(Data->filesavepath, Data->filename), "wb+");
        int Bit = 3 - (int)(log(Data->number) / log(256));
        if (Data->number) //非零
        {
            fseek(fp, Bit, SEEK_CUR);
            fwrite(&Data->number, sizeof(int), 1, fp);
        }
        else
        {
            fseek(fp, 3, SEEK_CUR);
            fwrite(&Data->number, sizeof(int), 1, fp);
        }
        for (int i = 0; i < Data->number; i++)
        {
            //写入
            Bit = 3 - (int)(log(Data->number) / log(256));
            fwrite(&item->item1, sizeof(int), 1, fp);
            Bit = 3 - (int)(log(Data->number) / log(256));
            fwrite(&item->item2, sizeof(int), 1, fp);
            Bit = 3 - (int)(log(Data->number) / log(256));
            fwrite(&item->item3, sizeof(int), 1, fp);
            item++;
        }
        fclose(fp);
        clockEnd = clock();
        printf("%dms\n", (double)clockBegin / CLK_TCK);
        printf("%dms\n", (double)clockEnd / CLK_TCK);
        printf("写入dat文件耗时%dms\n", (double)((clockEnd - clockBegin) / CLK_TCK));

        ext = strrchr(Data->filesavepath, '/') + 1;
        *ext = '\0';

        printf("dat文件生成成功！\n");
    }

    if (type == 1 || type == 3)
    {
        //txt部分（完成）
        //纠正扩展名
        ext = strrchr(Data->filename, '.') + 1;
        *ext = '\0';
        strcat(Data->filename, "txt");

        //创建+写入txt文件
        clockBegin = clock();
        fp = fopen(strcat(Data->filesavepath, Data->filename), "w+");
        fprintf(fp, "%d\n", Data->number);
        item = head;
        for (int i = 0; i < Data->number; i++)
        {
            //写入
            fprintf(fp, "%d,%d,%d\n", item->item1, item->item2, item->item3);
            item++;
        }
        fclose(fp);
        clockEnd = clock();
        printf("%dms\n", (double)clockBegin / CLK_TCK);
        printf("%dms\n", (double)clockEnd / CLK_TCK);
        printf("写入txt文件耗时%dms\n", (double)(clockEnd - clockBegin) / CLK_TCK);

        ext = strrchr(Data->filesavepath, '/') + 1;
        *ext = '\0';

        printf("txt文件生成成功！\n");
    }

    free(head);
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