#include<bits/stdc++.h>
#define MAXN 1005
#define MAXM 100005
#define eps 1e-8
#define inf 1e18
using namespace std;
queue <int> q;
int cnt,fst[MAXN],nxt[MAXM<<1],to[MAXM<<1],cur[MAXN];
int n,m,S,T,fr[MAXM],tx[MAXM],dep[MAXN],deg[MAXN],ans;
bool vis[MAXN];
double w[MAXM<<1];
void AddEdge(int u,int v,double c)
{
    to[++cnt]=v;
    nxt[cnt]=fst[u];
    fst[u]=cnt;
    w[cnt]=c;
}
bool Spfa()
{
    memset(dep,0,sizeof(dep));
    q.push(S);
    dep[S]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=fst[u];i;i=nxt[i])
        {
            int v=to[i];
            if(!dep[v] && w[i]>eps)
            {
                dep[v]=dep[u]+1;
                q.push(v);
            }
        }
    }
    return dep[T];
}
double Dfs(int u,double flow)
{
    if(u==T || flow==0) return flow;
    double used=0;
    for(int &i=cur[u];i;i=nxt[i])
    {
        int v=to[i];
        if(dep[v]==dep[u]+1 && w[i]>eps)
        {
            double fl=Dfs(v,min(flow,w[i]));
            if(fl>0)
            {
                used+=fl;
                flow-=fl;
                w[i]-=fl;
                w[i^1]+=fl;
                if(fabs(flow)<eps) break;
            }
        }
    }
    return used;
}
double Dinic()
{
    double sum=0;
    while(Spfa())
    {
        memcpy(cur,fst,sizeof(fst));
        sum+=Dfs(S,inf);
    }
    return sum;
}
bool Check(double mid)
{
    cnt=1;
    memset(fst,0,sizeof(fst));
    for(int i=1;i<=n;i++)
    {
        AddEdge(S,i,m);
        AddEdge(i,S,0);
        AddEdge(i,T,m*1.0+mid*2.0-deg[i]*1.0);
        AddEdge(T,i,0);
    }
    for(int i=1;i<=m;i++)
    {
        AddEdge(fr[i],tx[i],1);
        AddEdge(tx[i],fr[i],0);
        AddEdge(tx[i],fr[i],1);
        AddEdge(fr[i],tx[i],0);
    }
    return n*m-Dinic()>eps;
}
void FindAns(int u)
{
    vis[u]=1;
    ans++;
    for(int i=fst[u];i;i=nxt[i])
    {
        int v=to[i];
        if(!vis[v] && w[i]>eps) FindAns(v);
    }
}
int main()
{
    while(~scanf("%d %d",&n,&m))
    {
        S=0;
        T=n+1;
        ans=0;
        memset(deg,0,sizeof(deg));
        memset(vis,0,sizeof(vis));
        if(!m)
        {
            printf("%d\n%d\n\n",1,1);
            continue;
        }
        for(int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            fr[i]=x;
            tx[i]=y;
            deg[x]++;
            deg[y]++;
        }
        double l=0,r=m;
        while(r-l>1e-6)
        {
            double mid=(l+r)/2.0;
            if(Check(mid)) l=mid;
            else r=mid;
        }
        Check(l);
        FindAns(S);
        printf("%d\n",ans-1);
        for(int i=1;i<=n;i++) if(vis[i]) printf("%d\n",i);
    }
    return 0;
}