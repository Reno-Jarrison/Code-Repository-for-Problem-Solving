#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=1e3+5;
struct node
{   int x,y,p; }vtx[maxn];
struct edge
{
    int u,v; double w;
    edge(){};
    edge(int u,int v,double w):u(u),v(v),w(w){}
    friend bool operator <(const edge& x,const edge& y)
    { return x.w<y.w; }
}e[maxn*maxn];
vector<edge>ex[maxn];
int ecnt,f[maxn];
int sqr(int x) { return x*x; }
double dis(int a,int b)
{   return sqrt(sqr(vtx[a].x-vtx[b].x)+sqr(vtx[a].y-vtx[b].y)); }
int find(int x)
{   return x==f[x]?x:f[x]=find(f[x]); }
double kruskal()
{
    double ans=0;
    sort(e,e+ecnt);
    for(int i=0;i<ecnt;i++)
    {
        int u=e[i].u,v=e[i].v;
        int fu=find(u),fv=find(v);
        if(fu==fv) continue;
        ans+=e[i].w,f[fu]=fv;
        ex[u].push_back(edge(u,v,e[i].w));
        ex[v].push_back(edge(v,u,e[i].w));
    }
    return ans;
}
int lg2[maxn]={-1},dep[maxn],fat[maxn][25];
double mxv[maxn][25];
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
double getmxv(int x,int y)
{
  double ans=0;
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
    int t,n;
    getlg2();
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) 
        {
            scanf("%d%d%d",&vtx[i].x,&vtx[i].y,&vtx[i].p);
           	ex[i].clear(),f[i]=i;
        }
        ecnt=0;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                e[ecnt++]=edge(i,j,dis(i,j));
        double sum=kruskal(),ans=0;
        dfs(1,0);
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                ans=max(ans,(vtx[i].p+vtx[j].p)/(sum-getmxv(i,j)));
        printf("%.2lf\n",ans);
    }
}