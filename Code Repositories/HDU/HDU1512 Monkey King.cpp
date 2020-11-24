#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
struct Ltree
{
    int siz,l[maxn],r[maxn],dis[maxn],val[maxn],f[maxn];
    void build(int n,int* src)
    {
        siz=n,dis[0]=val[0]=-1;
        for(int i=1;i<=n;i++)
            val[i]=src[i],f[i]=i,l[i]=r[i]=dis[i]=0;
    }
    int merge(int x,int y)
    {
        if(!x||!y) return x|y;
        if(val[x]<val[y]) swap(x,y);
        r[x]=merge(r[x],y),f[r[x]]=x;
        if(dis[l[x]]<dis[r[x]])
            swap(l[x],r[x]);
        dis[x]=dis[r[x]]+1;
        return x;
    }
    int find(int x)
    {    return f[x]==x?x:f[x]=find(f[x]); }
    int pop(int x)
    {    
        int rt=f[l[x]]=f[r[x]]=merge(l[x],r[x]);
        l[x]=r[x]=dis[x]=0,f[x]=x;
        return rt;
    }
}lt;
int a[maxn];
int main()
{
    int n,m,x,y;
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        lt.build(n,a);
        scanf("%d",&m);
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&x,&y);
            int fx=lt.find(x),fy=lt.find(y);
            if(fx==fy) { puts("-1"); continue; }
            int rtx=lt.pop(fx),rty=lt.pop(fy);
            lt.val[fx]>>=1,lt.val[fy]>>=1;
            rtx=lt.merge(rtx,fx),rty=lt.merge(rty,fy);
            int rt=lt.merge(rtx,rty);
            printf("%d\n",lt.val[rt]);
        }
    }
}