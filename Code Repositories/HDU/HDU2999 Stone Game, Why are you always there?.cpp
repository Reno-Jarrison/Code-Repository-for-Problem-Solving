#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int cnt,s[105],mex[1005],sg[1500];
int getsg(int x)
{
    if(!x) return 0;
    if(sg[x]!=-1) return sg[x];
    memset(mex,0,sizeof(mex));
    for(int i=1;i<=cnt&&x>=s[i];i++)
        for(int j=0;j+s[i]<=x;j++)
            mex[getsg(j)^getsg(x-s[i]-j)]=1;
    for(int i=0;i<=1000;i++)
        if(!mex[i]) { sg[x]=i; break; }
    return sg[x];
}
int main()
{
    int m,k;
    while(~scanf("%d",&cnt))
    {
        memset(sg,-1,sizeof(sg));
        for(int i=1;i<=cnt;i++)
            scanf("%d",&s[i]);
        sort(s+1,s+cnt+1);
        scanf("%d",&m);
        for(int i=1;i<=m;i++)
            scanf("%d",&k),puts(getsg(k)?"1":"2");
    }
}