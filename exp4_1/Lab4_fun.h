//存储各个子函数声明
#ifndef _LAB4_FUN_H

#define _LAB4_FUN_H
#define random(x) (rand() % x)

// void Argv1(char *argv, CONF *conf);
void Argv2(char *argv);
void Argv3(char *argv);

int Validate(char *argv);
int isNumber(char *argv);
int mkdir(char *argv);
void saveConf(char *argv, char *FileName, char *FilesavePath);
void inputPath(char *FileName, char *FilesavePath);
// int ReadConfig(CONF *conf);
// void GenDataFile(CONF *Data);
// void GenBinFile(CONF *Data);
int GetRand(int Max, int Min);

#endif