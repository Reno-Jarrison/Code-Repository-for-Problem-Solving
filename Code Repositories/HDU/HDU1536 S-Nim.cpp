#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e4;
int cnt,s[105],mex[105],sg[maxn+5];
void getsg()
{
    sort(s+1,s+cnt+1);
    for(int i=1;i<=maxn;i++)
    {
        memset(mex,0,sizeof(mex));
        for(int j=1;j<=cnt&&i>=s[j];j++)
            mex[sg[i-s[j]]]=1;
        for(int j=0;j<=cnt;j++)
            if(!mex[j]) { sg[i]=j; break; }
    }
}
int main()
{
    int m,n;
    while(~scanf("%d",&cnt)&&cnt)
    {
        for(int i=1;i<=cnt;i++)
            scanf("%d",&s[i]);
        getsg();
        scanf("%d",&m);
        for(int i=1;i<=m;i++)
        {
            int sum=0,x;
            scanf("%d",&n);
            for(int j=1;j<=n;j++)
                scanf("%d",&x),sum^=sg[x];
            putchar(sum?'W':'L');
        }
        puts("");
    }
}