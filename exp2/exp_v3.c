/****************************************************
������Ϣ��
	������������   ѧ�ţ�20281205   �༶�������2007��  ѧԺ�������
     Email: 20281205@bjtu.edu.cn            �绰��13519570701
��Ȩ������
	��Ȩ�ɶ��������У�����ʦ�⣬δ�������ÿ���������ҵ
ģ������: 
      ������� ʵ��2
ժҪ:
  	��ģ���� ʵ��2������
����˵��:
    
ģ����ʷ:
	��������2021��3��16�մ�����ģ�飬email: 20281205@bjtu.edu.cn
    ver1: ��ȷ�������Ҫ���ܣ������ļ���main��������ע�����ʵ�ֳ���ļ�����Ҫ����
    ver2: ��ע����дÿ����Ҫ�����Ӧ��α����
    ver3: ��ȫ���룬��ʵ��Ҫ����
****************************************************/


# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

# define random(x) (rand()%x)
char fileName[25]={0};

//------------�����������------------
int Num=0;
int NumCustom=0;
int FileNameCustom=0;

/*
*�������ƣ�main
*�������ܣ������û�����ֱ���ö�Ӧ���ܺ���ʵ�ֹ���
*���������int argc�������в�������, char* argv[]:�����в���ֵ
*����ֵ����
*�汾��Ϣ��create by ������,2021-03-16
*/
int main(int argc, char *argv[])
{
    srand((int)time(0));
	//------------��һ�������������г��򣬴������������Ϊ��Ҫ��¼���ݵ�����
    for(int i=1;i<argc;i++)
    {
        if(strspn(argv[i], "0123456789")==strlen(argv[i]) && argv[i]!="0") //�жϵ�ǰ�����Ƿ�Ϊ����Ĵ�����
        {
            if(!NumCustom)  //��ֵ����
            {
                Num=atoi(argv[i]);
                NumCustom=1;
            }
            else  //�������У���ֵ�ļ���
            {
                if(!FileNameCustom)
                {
                    strcat(fileName,argv[i]);
                    FileNameCustom=1;
                }
            }
        }
        else //���ַ�
        {
            if(!FileNameCustom)  //��ֵ�ļ���
            {
                strcat(fileName,argv[i]);
                FileNameCustom=1;
            }
        }
    }

    //------------�ڶ�������δ����Ĳ���ָ��ֵ
    if(!NumCustom)
    {Num=random(100);}
    if(!FileNameCustom)
    {strcat(fileName,"default.txt");}
    
    //------------��������ʹ��rand��������������д����ʱ����
    int container[Num][3];
    for(int i=0; i<Num; i++)
    {
        for(int j=0; j<3; j++)
        {
            container[i][j] = random(100);
        }
    }

    //------------���Ĳ��������ļ�д���������ʼд���ļ�
    FILE *fp = NULL;
    fp = fopen(fileName,"w+"); 
    char strTemp[25]={0};
    itoa(Num,strTemp,10);
    strcat(strTemp,"\n");
    fputs(strTemp, fp); //д����������

    char strLine[25]={0};
    for(int i=0; i<Num ;i++)
    {
        memset(strTemp, 0, sizeof(strTemp));    // clear
        memset(strLine, 0, sizeof(strLine));    // clear
        for(int j=0; j<3; j++)
        {
            itoa(container[i][j],strTemp,10);
            strcat(strLine,strTemp);    //ƴ�����������������ַ�ֵ
            if(j<2){strcat(strLine,",");}
            else if(j==2){strcat(strLine,"\n");}
        }
        fputs(strLine, fp); //д�뵱ǰ�е���������
    }
    fclose(fp);
	return 0;
}