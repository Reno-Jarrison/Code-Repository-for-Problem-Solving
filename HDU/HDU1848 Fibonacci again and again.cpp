#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e3;
int fib[20],sg[maxn+5],mex[maxn+5];
void pretreat()
{
    fib[1]=1,fib[2]=2;
    for(int i=3;i<20;i++)
        fib[i]=fib[i-1]+fib[i-2];
    for(int i=1;i<=maxn;i++)
    {
        memset(mex,0,sizeof(mex));
        for(int j=1;j<20&&fib[j]<=i;j++)
            mex[sg[i-fib[j]]]=1;
        for(int j=0;j<=20;j++)
            if(!mex[j]) { sg[i]=j; break; }
    }
}
int main()
{
    int m,n,p;
    pretreat();
    while(scanf("%d%d%d",&m,&n,&p)&&m&&n&&p)
        puts(sg[m]^sg[n]^sg[p]?"Fibo":"Nacci");
}
