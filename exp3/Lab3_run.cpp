//存储run函数的函数实现
#include<iostream>
#include"Lab3_run.h"
#include"Lab3_fun.h"
#include"Lab3_data.h"

/*
*函数名称：Run
*函数功能：
*输入参数：int argc：命令行参数个数, char* argv[]:命令行参数值
*返回值：无
*版本信息：create by 董逸箫，2021-04-08
*/
void Run(int argc, char *argv[])
{
    cout << "argc:"<< argc<<endl;
    cout<< "argv[1]:"<< argv[1]<<endl;
    cout<< "argv[2]:"<< argv[2]<<endl;
}