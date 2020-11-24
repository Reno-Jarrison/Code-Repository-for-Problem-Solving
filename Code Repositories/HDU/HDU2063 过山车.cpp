#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=505;
int mat[maxn];
bool e[maxn][maxn],vis[maxn];
bool dfs(int u,int n)
{
    for(int i=1;i<=n;i++)
    {
        if(vis[i]||!e[u][i]) continue;
        vis[i]=true;
        if(!mat[i]||dfs(mat[i],n)) 
        {    mat[i]=u; return true; }
    }
    return false;
}
int main()
{
    int k,m,n,u,v,ans;
    while(scanf("%d",&k)&&k)
    {
        scanf("%d%d",&m,&n);
        memset(mat,0,sizeof(mat));
        memset(e,0,sizeof(e)),ans=0;
        for(int i=1;i<=k;i++)
            scanf("%d%d",&u,&v),e[u][v]=true;
        for(int i=1;i<=m;i++)
        {
            memset(vis,0,sizeof(vis));
            if(dfs(i,n)) ans++;
        }
        printf("%d\n",ans);
    }
}