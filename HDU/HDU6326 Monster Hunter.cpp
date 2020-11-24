#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
vector<int>e[maxn];
void link(int u,int v)
{    e[u].push_back(v),e[v].push_back(u); }
struct node
{
    int i; ll a,b;
    node(int i,ll a,ll b):i(i),a(a),b(b){}
};
bool operator <(const node& x,const node& y)
{    
    if(x.a<=x.b&&y.a<=y.b) return x.a>y.a;
    if(x.a>x.b&&y.a>y.b) return x.b<y.b;
    return y.a<=y.b;
}
priority_queue<node>q;
int f[maxn],fat[maxn],vis[maxn];
ll a[maxn],b[maxn];
int find(int x)
{    return f[x]==x?x:f[x]=find(f[x]); }
void dfs(int u,int fu)
{
    fat[u]=fu;
    for(int v:e[u])
        if(v!=fu) dfs(v,u);
}
int main()
{
    int t,n,u,v;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            e[i].clear(),f[i]=i,vis[i]=0;
        for(int i=2;i<=n;i++)
            scanf("%lld%lld",&a[i],&b[i]),q.push(node(i,a[i],b[i]));
        for(int i=1;i<n;i++)
            scanf("%d%d",&u,&v),link(u,v);
        dfs(1,1),vis[1]=1;
        ll ans=0,sum=0;
        while(!q.empty())
        {
            node t=q.top();q.pop();
            if(t.a!=a[t.i]||t.b!=b[t.i]) continue;
            int v=t.i,u=find(fat[v]);
            if(vis[u])
                ans=min(ans,sum-a[v]),sum=sum-a[v]+b[v],vis[v]=1;
            else
            {
                f[v]=u;
                if(a[v]<=b[u]) b[u]+=b[v]-a[v];
                else a[u]+=a[v]-b[u],b[u]=b[v];
                q.push(node(u,a[u],b[u]));
            }
        }
        printf("%lld\n",-ans);
    }
}