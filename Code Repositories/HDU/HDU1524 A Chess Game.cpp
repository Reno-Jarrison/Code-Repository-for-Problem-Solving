#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
const int maxn=1e3+5;
vector<int>e[maxn];
int ind[maxn],mex[maxn][maxn],sg[maxn];
void getsg(int u)
{
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i];
        getsg(v),mex[u][sg[v]]=1;
    }
    for(int i=0;i<=maxn-5;i++)
        if(!mex[u][i]) { sg[u]=i; break; }
}
int main()
{
    int n,m,x,v;
    while(~scanf("%d",&n))
    {
        memset(ind,0,sizeof(ind));
        memset(mex,0,sizeof(mex));
        for(int i=0;i<n;i++)
        {
            e[i].clear();
            scanf("%d",&x);
            for(int j=1;j<=x;j++)
                scanf("%d",&v),e[i].push_back(v),ind[v]++;
        }
        for(int i=0;i<n;i++)
            if(!ind[i]) { getsg(i); }
        while(scanf("%d",&m)&&m)
        {
            int sum=0;
            for(int i=1;i<=m;i++)
                scanf("%d",&v),sum^=sg[v];
            puts(sum?"WIN":"LOSE");
        }
    }
}