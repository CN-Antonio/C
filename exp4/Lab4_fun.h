//存储各个子函数声明
#ifndef _LAB4_FUN_H

#define _LAB4_FUN_H
# define random(x) (rand()%x)

int Argc1();
int Argc2();
int Argc3();

int Validate(char * argv);
int isNumber(char * argv);
int mkdir(char * argv);
void saveConf(char * argv, char * FileName, char * FilesavePath);
void inputPath(char * FileName, char * FilesavePath);
// void GenDataFile(char* argv[0],CONF Data);
int GetRand(int Max,int Min);


#endif