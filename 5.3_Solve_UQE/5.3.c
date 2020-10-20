/*求解一元二次方程，实根虚根
1. 一元一次
2. 一元二次异实根
3. 一元二次同实根
4. 一元二次异虚根*/

#include<stdio.h>
#include<math.h>
int a,b,c;
double delta;

/*1*/int OO(int B,int C)
{printf("x=%.4lf\n",(double)((-C)/B));}
/*2*/
int OTDR(int A,int B,int C)
{
    printf("x1=%.4lf\n",0.5*(-b + sqrt(delta))/a);
    printf("x2=%.4lf\n",0.5*(-b - sqrt(delta))/a);
}
/*3*/
int OTSR(int A,int B,int C)
{printf("x1=x2=%.4lf\n",0.5*(-b)/a);}
/*4*/
int OTDI(int A,int B,int C)
{
    double img = sqrt((-1)*delta)/(2*a); //虚部
    printf("x1=%.4lf+%.4lfi\n",(double)(-b/(2*a)),img);
    printf("x2=%.4lf-%.4lfi\n",(double)(-b/(2*a)),img);
}


int main()
{
    // freopen("./Temp/test.in","r",stdin);
    scanf("%d,%d,%d",&a,&b,&c);
    
    delta = pow(b,2)-4*a*c;
    /*1*/if(a==0)
    {OO(b,c);}
    /*2*/else if(delta>0)
    {OTDR(a,b,c);}
    /*3*/else if(delta==0)
    {OTSR(a,b,c);}
    /*4*/else if(delta<0)
    {OTDI(a,b,c);}

    return 0;
}