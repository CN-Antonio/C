//存储run函数的函数实现
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string.h>
#include"Lab3_run.h"
#include"Lab3_fun.h"
#include"Lab3_data.h"

void GenDataFile(CONF Data);

/*
*函数名称：Run
*函数功能：
*输入参数：int argc：命令行参数个数, char* argv[]:命令行参数值
*返回值：无
*版本信息：create by 董逸箫，2021-04-08
*/
void Run(int argc, char *argv[])
{
    //for test
    cout << "argc:"<< argc<<endl;
    cout<< "argv[0]:"<< argv[0]<<endl;
    // cout<< "argv[1]:"<< argv[1]<<endl;
    // cout<< "argv[2]:"<< argv[2]<<endl;

    //声明结构体变量
    CONF Data={0};
    //初始化结构体各分量
    Data.filename[0]={0};
    Data.filesavepath;
    Data.maxvalue1=255;
    Data.minvalue1=0;
    Data.maxvalue2=255;
    Data.minvalue2=0;
    Data.recordcount1=255; //随机上限
    Data.recordcount2=10;  //随机下限

    char number[MAX_STR_LEN]={"A"};
    int Input=0; //首次输入前=0；输入过=1

    // --------------- argc==1 ----------------------------------
    if(argc==1)
    {
        cout<<"无参数，请输入记录条数:";
        while(!isNumber(number)) //合法性检查，输入不合法时
        {
            if(Input){cout<<"输入非法，请重新输入：";}
            memset(number, 0, sizeof(number));    // clear cache
            scanf("%s",number);
            printf("input number:%s\n",number);
            Input=1;
        }
        cout<<"输入合法"<<endl;
        if(isNumber(number)==1) //customize
        {
            Data.number=atoi(number);
            // printf("saved Data.number:%d\n",Data.number); //check
        }
        else if(isNumber(number)==2) //random number
        {
            cout<<"random"<<endl;
            Data.number=GetRand(Data.recordcount1,Data.recordcount2);
            printf("saved Data.number:%d\n",Data.number); //check
        }
        // GenDataFile(Data);
    }
    // --------------- argc==2 ----------------------------------
    else if(argc==2)
    {
        cout<<"1参数"<<endl;
        if(isNumber(argv[1])==1) //为数值
        {
            Data.number=atoi(number);
            //↓提示……

            GenDataFile(Data);
        }
        else
        {
            if(!Validate(argv[1])) //合法性检查
            {
                cout<<"argv1 invalid"<<endl;
                return;
            }
            else // argv[1] valid
            {
                saveConf(argv[1]);
            }
            //以下与argc==1的段落重复
            cout<<"请输入记录条数:";
            while(!isNumber(number)) //合法性检查，输入不合法时
            {
                if(Input){cout<<"输入非法，请重新输入：";}
                memset(number, 0, sizeof(number));    // clear cache
                scanf("%s",number);
                printf("input number:%s\n",number);
                Input=1;
            }
            cout<<"输入合法"<<endl;
            if(isNumber(number)==1) //customize
            {
                Data.number=atoi(number);
                // printf("saved Data.number:%d\n",Data.number); //check
            }
            else if(isNumber(number)==2) //random number
            {
                cout<<"random"<<endl;
                Data.number=GetRand(Data.recordcount1,Data.recordcount2);
                printf("saved Data.number:%d\n",Data.number); //check
            }
            // GenDataFile(Data);
        }
    }
    // --------------- argc==3 ----------------------------------
    else if(argc==3)
    {
        cout<<"2 Parameters"<<endl;
        if(isNumber(argv[1])) //argv1 is num
        {
            cout<<"para1==num"<<endl;
            Data.number=atoi(argv[1]);
            if(!Validate(argv[2]))
            {
                cout<<"argv2 invalid"<<endl;
                return;
            }
            else
            {
                saveConf(argv[2]);//取argv2做路径
                // GenDataFile(Data);
            }
        }
        else if(isNumber(argv[2])) //argv2 is num
        {
            cout<<"para2==num"<<endl;
            Data.number==atoi(argv[2]);
            if(!Validate(argv[1]))
            {
                cout<<"argv1 invalid"<<endl;
                return;
            }
            else
            {
                saveConf(argv[1]);//取argv1做路径
                // GenDataFile(Data);
            }
        }
        else
        {
            cout<<"Err 找不到记录条数"<<endl;
            // return;
        }
    }
    else
    {
        cout<<"Too Many Parameters!"<<endl;
        // return;
    }
}