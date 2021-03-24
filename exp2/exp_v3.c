/****************************************************
作者信息：
	姓名：董逸箫   学号：20281205   班级：计算机2007班  学院：计算机
     Email: 20281205@bjtu.edu.cn            电话：13519570701
版权声明：
	版权由董逸箫所有，除老师外，未经允许不得拷贝本人作业
模块名称: 
      程序设计 实验2
摘要:
  	本模块是 实验2交付物
其它说明:
    
模块历史:
	董逸箫于2021年3月16日创建本模块，email: 20281205@bjtu.edu.cn
    ver1: 明确程序的主要功能，创建文件和main函数，用注释理出实现程序的几个主要步骤
    ver2: 用注释填写每个主要步骤对应的伪代码
    ver3: 补全代码，并实现要求功能
****************************************************/


# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

# define random(x) (rand()%x)
char fileName[25]={0};

//------------定义所需变量------------
int Num=0;
int NumCustom=0;
int FileNameCustom=0;

/*
*函数名称：main
*函数功能：读入用户输入分别调用对应功能函数实现功能
*输入参数：int argc：命令行参数个数, char* argv[]:命令行参数值
*返回值：无
*版本信息：create by 董逸箫,2021-03-16
*/
int main(int argc, char *argv[])
{
    srand((int)time(0));
	//------------第一步，命令行运行程序，传入参数，数字为需要记录数据的组数
    for(int i=1;i<argc;i++)
    {
        if(strspn(argv[i], "0123456789")==strlen(argv[i]) && argv[i]!="0") //判断当前参数是否为非零的纯数字
        {
            if(!NumCustom)  //赋值组数
            {
                Num=atoi(argv[i]);
                NumCustom=1;
            }
            else  //组数已有，赋值文件名
            {
                if(!FileNameCustom)
                {
                    strcat(fileName,argv[i]);
                    FileNameCustom=1;
                }
            }
        }
        else //有字符
        {
            if(!FileNameCustom)  //赋值文件名
            {
                strcat(fileName,argv[i]);
                FileNameCustom=1;
            }
        }
    }

    //------------第二步，对未定义的参数指定值
    if(!NumCustom)
    {Num=random(100);}
    if(!FileNameCustom)
    {strcat(fileName,"default.txt");}
    
    //------------第三步，使用rand函数将生成数据写入临时容器
    int container[Num][3];
    for(int i=0; i<Num; i++)
    {
        for(int j=0; j<3; j++)
        {
            container[i][j] = random(100);
        }
    }

    //------------第四步，定义文件写入参数，开始写入文件
    FILE *fp = NULL;
    fp = fopen(fileName,"w+"); 
    char strTemp[25]={0};
    itoa(Num,strTemp,10);
    strcat(strTemp,"\n");
    fputs(strTemp, fp); //写入数据组数

    char strLine[25]={0};
    for(int i=0; i<Num ;i++)
    {
        memset(strTemp, 0, sizeof(strTemp));    // clear
        memset(strLine, 0, sizeof(strLine));    // clear
        for(int j=0; j<3; j++)
        {
            itoa(container[i][j],strTemp,10);
            strcat(strLine,strTemp);    //拼接行内三个分量的字符值
            if(j<2){strcat(strLine,",");}
            else if(j==2){strcat(strLine,"\n");}
        }
        fputs(strLine, fp); //写入当前行的三个分量
    }
    fclose(fp);
	return 0;
}