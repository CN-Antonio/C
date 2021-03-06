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
	无
模块历史:
	董逸箫于2021年3月16日创建本模块，email: 20281205@bjtu.edu.cn
    ver1: 明确程序的主要功能，创建文件和main函数，用注释理出实现程序的几个主要步骤
    ver2: 用注释填写每个主要步骤对应的伪代码
****************************************************/


# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

/*
*函数名称：main
*函数功能：读入用户输入分别调用对应功能函数实现功能
*输入参数：int argc：命令行参数个数
           char* argv[]:命令行参数值
*返回值：无
*版本信息：create by 董逸箫,2021-03-16
*/
int main(int argc, char *argv[])
{
	//------------第一步，命令行运行程序，传入参数，数字为需要记录数据的组数
    /* 考虑缺少用户定义参数时，对两个参数指定默认值 */
    /* 考虑用户参数倒序传入时的应对方法 */
    // for(i=0;i<argc;i++)
    // {
    //     if(argv[i].tyep==number){save as num}
    //     if(argv[i].type==text){save as filename}
    // }

    //------------第二步，对未定义的参数指定值
    /* 初步定义文件名为default.txt， 数据条数由随机数生成 */
    // if(!num_exist){num=rand()}
    // if(!filename_exist){filename=default.txt}

    //------------第三步，使用rand函数将生成数据写入临时容器
    /* 使用time.h与srand()设置随机数种子 */
    /* 使用rand()函数生成随机数 */
    // set seed
    // for(i=0; i<num*3; i++)
    // {container[i]=rand()}

    //------------第四步，定义文件写入参数，开始写入文件
	/*第四步具体步骤：
    初始化文件处理函数
    写入数据组数的值
    fputs(num,fp)
    循环次数为数据组数的值
    for(i=0;i<num;i++)
        每个循环体内将当前行的三个分量与分隔符拼接，并在末尾添加换行符
        strcat(container[i],",",container[i+1],",",container[i],"\n")
        写入当前行数据至文件
        fputs(str,fp)
    关闭文件
    fclose(fp)
	*/
	return 0;
}