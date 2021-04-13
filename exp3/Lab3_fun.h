//存储各个子函数声明
#ifndef _LAB3_FUN_H

#define _LAB3_FUN_H
# define random(x) (rand()%x)

int Validate(char * argv);
int charLen(char * argv);
int isNumber(char * argv);
int mkdir(char * argv);
void saveConf(char * argv);
void inputPath();
// void GenDataFile(CONF Data);
int GetRand(int Max,int Min);


#endif