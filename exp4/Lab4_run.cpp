//存储run函数的函数实现
#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <cstdlib>
#include <string.h>
#include <ctime>
#include "Lab4_run.h"
#include "Lab4_fun.h"
#include "Lab4_data.h"

void Argv1(char *argv, CONF *conf);
void Argv3(char *argv, CONF *conf);
void GenFile(CONF *Data, int type);
int ReadConfig(CONF *conf);



/*
*函数名称：Run
*函数功能：
*输入参数：int argc：命令行参数个数, char* argv[]:命令行参数值
*返回值：无
*版本信息：create by 董逸箫，2021-04-08
*/
void Run(int argc, char *argv[])
{
    /*/for test
    cout << "argc:" << argc << endl;
    for (int i = 0; i < argc; i++)
    {
        cout << "argv[" << i << "]:" << argv[i] << endl;
    } //*/

    //Init
    // clock_t clockBegin, clockEnd;
    // clockBegin = clock();
    // srand(rand() + (unsigned)time(0)); //以时间+随机数为种子

    //声明结构体变量
    CONF conf = {0};
    DATAITEM Cache = {0};

    //读取默认配置文件
    // if(ReadConfig(&conf) == NULL) //read failed
    // {return;} //?
    ReadConfig(&conf);
    //*/ check config read
    {
        printf("Config:\n");
        printf("path:%s\nname:%s\n", conf.filesavepath, conf.filename);
        printf("number:%d\n", conf.number);
        printf("%d\n%d\n", conf.maxvalue1, conf.minvalue1);
        printf("%d\n%d\n", conf.maxvalue2, conf.minvalue2);
        printf("%d\n%d\n", conf.recordcount1, conf.recordcount2);
    }
    //*/

    char number[MAX_STR_LEN] = {"A"}; //默认输入条数参数不合法
    int Input = 0;                    //首次输入前=0；输入过=1

    //*/ --------------- argc==1 ----------------------------------
    if (argc == 1) //lab3 default
    {
        cout << "无参数，请输入记录条数:";
        while (!isNumber(number)) //合法性检查，输入不合法时
        {
            memset(number, 0, sizeof(number)); // clear cache
            if (Input)                         //二次输入时
            {
                cout << "输入非法，请重新输入：";
            }
            scanf("%s", number);
            printf("input number:%s\n", number);
            Input = 1;
        }
        cout << "输入合法" << endl;
        if (isNumber(number) == 1) //customized number
        {
            if (conf.recordcount1 < atoi(number)) //大于上限
            {
                conf.number = conf.recordcount1;
            }
            else if (conf.recordcount2 > atoi(number)) //小于下限
            {
                conf.number = conf.recordcount2;
            }
            else
            {
                conf.number = atoi(number);
            }
            // printf("saved conf.number:%d\n",conf.number); //check
        }
        else if (isNumber(number) == 2) //random number
        {
            cout << "random" << endl;
            conf.number = GetRand(conf.recordcount1, conf.recordcount2);
            printf("saved conf.number:%d\n", conf.number); //check
        }

        //输入路径
        printf("请输入路径与文件名：");
        inputPath(conf.filename, conf.filesavepath);
        GenFile(&conf, 3);
    } //*/

    //*/ --------------- argc==2 ----------------------------------
    //文件名Lab3; 格式-双文件
    else if (argc == 2) //num or 'r'
    {
        // cout<<"1参数"<<endl;
        if (!isNumber(argv[1])) //合法性检查，参数1不合法时
        {
            cout << "argv1 invalid!" << endl;
            return;
        }
        else if (isNumber(argv[1]) == 1)
        {
            if (conf.recordcount2 < atoi(argv[1])) //大于上限
            {
                conf.number = conf.recordcount2;
            }
            else if (conf.recordcount1 > atoi(argv[1])) //小于下限
            {
                conf.number = conf.recordcount1;
            }
            else
            {
                conf.number = atoi(argv[1]);
            }
        }
        else if (isNumber(argv[1]) == 2)
        {
            conf.number = GetRand(conf.recordcount1, conf.recordcount2);
        }

        GenFile(&conf, 3);
    } //*/
    //*/ --------------- argc==3 ----------------------------------
    else if (argc == 3)
    {
        // cout<<"2 Parameters"<<endl;
        Argv1(argv[1], &conf);

        if (!Validate(argv[2], conf.filename, conf.filesavepath)) //路径合法
        {
            cout << "argv2 invalid" << endl;
            return;
        }
        GenFile(&conf, 3);

    } //*/

    //*/-----argc=4-----
    else if (argc == 4)
    {
        // cout<<"3 Parameters"<<endl;
        //para1
        Argv1(argv[1], &conf);
        //para2
        // Argv2(argv[2]);
        if (!Validate(argv[2], conf.filename, conf.filesavepath))
        {
            cout << "argv2 invalid" << endl;
            return;
        }
        //para3
        // Argv3(argv[3]);
        if (strlen(argv[3]) == 1 && strspn(argv[3], "t") != 0)
        {
            printf("Text\n");
            GenFile(&conf, 1);
        }
        else if (strlen(argv[3]) == 1 && strspn(argv[3], "b") != 0)
        {
            printf("Bin\n");
            GenFile(&conf, 2);
        }
        else
        {
            //Output error
            printf("Parameter 3: File Type Error");
            return;
        }
    } //*/
    //many args
    else
    {
        cout << "Too Many Parameters!" << endl;
        // return;
    }
}