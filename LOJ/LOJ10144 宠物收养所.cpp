#include<bits/stdc++.h>
#define ll long long
#define lson(rt) son[rt][0]
#define rson(rt) son[rt][1]
using namespace std;
const int maxn=1e5+5,mod=1e6;
const ll inf=1e12;
struct FHQTreap
{
    int root,tot,siz[maxn],son[maxn][2];
    ll w[maxn],key[maxn];
    int newnode(ll val)
    {
        w[++tot]=val,key[tot]=rand(),siz[tot]=1;
        son[tot][0]=son[tot][1]=0;
        return tot;
    }
    void push_up(int rt)
    {   siz[rt]=siz[lson(rt)]+siz[rson(rt)]+1; }
    void split(int rt,ll val,int& x,int& y)
    {
        if(!rt) { x=y=0; return; };
        if(w[rt]<=val) x=rt,split(rson(rt),val,rson(x),y);
        else y=rt,split(lson(rt),val,x,lson(y));
        push_up(rt);
    }
    int merge(int x,int y)
    {
        if(!x||!y) return x|y;
        if(key[x]<key[y])
            return rson(x)=merge(rson(x),y),push_up(x),x;
        else return lson(y)=merge(x,lson(y)),push_up(y),y;
    }
    void insert(ll val)
    {
        int x,y,ist=newnode(val);
        split(root,val,x,y);
        root=merge(x,merge(ist,y));
    }
    void erase(ll val)
    {
        int x,y,del;
        split(root,val,x,y);
        split(x,val-1,x,del);
        del=merge(lson(del),rson(del));
        root=merge(x,merge(del,y));
    }
    ll getkth(int rt,int k)
    {
        while(true)
        {
            int lsiz=siz[lson(rt)];
            if(k<=lsiz) rt=lson(rt);
            else if(k>lsiz+1)
                k-=lsiz+1,rt=rson(rt);
            else return w[rt];
        }
    }
    ll getpre(int val)
    {
        int x,y;
        split(root,val,x,y);
        ll ans=siz[x]?getkth(x,siz[x]):-inf;
        root=merge(x,y);
        return ans;
    }
    ll getsuc(int val)
    {
        int x,y;
        split(root,val-1,x,y);
        ll ans=siz[y]?getkth(y,1):inf;
        root=merge(x,y);
        return ans;
    }
}t;
int main()
{
    int n,tag,flag;
    scanf("%d",&n);
    ll ans=0,x;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%lld",&tag,&x);
        if(!tag) tag=-1;
        if(!t.siz[t.root]) flag=0;
        if(!flag||flag==tag) flag=tag,t.insert(x);
        else
        {
            ll pre=t.getpre(x),suc=t.getsuc(x);
            ans=(ans+min(x-pre,suc-x))%mod;
            t.erase(x-pre<=suc-x?pre:suc);
        }
    }
    printf("%lld",ans);
}    