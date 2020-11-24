#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=105;
struct edge
{
    int u,v,w;
    edge(){};
    edge(int u,int v,int w):u(u),v(v),w(w){}
    friend bool operator <(const edge& x,const edge& y)
    { return x.w<y.w; }
}e[maxn*maxn];
vector<edge>ex[maxn];
int f[maxn],tag[maxn*maxn];
int lg2[maxn]={-1},dep[maxn],fat[maxn][25],mxv[maxn][25];
int find(int x)
{   return x==f[x]?x:f[x]=find(f[x]); }
int kruskal(int m)
{
    int ans=0;
    sort(e+1,e+m+1);
    for(int i=1;i<=m;i++)
    {
        int u=e[i].u,v=e[i].v,w=e[i].w;
        int fu=find(u),fv=find(v);
        if(fu==fv) continue;
        tag[i]=1,ans+=e[i].w,f[fu]=fv;
        ex[u].push_back(edge(u,v,w));
        ex[v].push_back(edge(v,u,w));
    }
    return ans;
}
void getlg2()
{   for(int i=1;i<=maxn-5;i++) lg2[i]=lg2[i>>1]+1; }
void dfs(int u,int f)
{
    dep[u]=dep[f]+1,fat[u][0]=f;
    for(int i=1;(1<<i)<=dep[u];i++)
    {
        fat[u][i]=fat[fat[u][i-1]][i-1];
        mxv[u][i]=max(mxv[u][i-1],mxv[fat[u][i-1]][i-1]);
    }
    for(int i=0;i<(int)ex[u].size();i++)
    {
        int v=ex[u][i].v;
        if(v!=f) mxv[v][0]=ex[u][i].w,dfs(v,u);
    }
}
int getmxv(int x,int y)
{
  int ans=0;
  if(dep[x]<dep[y]) swap(x,y);
  while(dep[x]>dep[y])
  {
    ans=max(ans,mxv[x][lg2[dep[x]-dep[y]]]);
    x=fat[x][lg2[dep[x]-dep[y]]];
  }
  if(x==y) return ans;
  for(int i=lg2[dep[x]];i>=0;i--)
    if(fat[x][i]!=fat[y][i])
    {
      ans=max(ans,max(mxv[x][i],mxv[y][i]));
      x=fat[x][i],y=fat[y][i];
    }
  return max(ans,max(mxv[x][0],mxv[y][0]));
}
int main()
{
    int t,n,m;
    getlg2();
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        memset(tag,0,sizeof(tag));
        for(int i=1;i<=n;i++) f[i]=i,ex[i].clear();
        for(int i=1;i<=m;i++)
            scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
        int ans1=kruskal(m),ans2=0x3f3f3f3f;
        dfs(1,0);
        for(int i=1;i<=m;i++) if(!tag[i])
        {
            ans2=min(ans2,ans1-getmxv(e[i].u,e[i].v)+e[i].w);
        }
        printf("%d %d\n",ans1,ans2);
    }
}