#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e5+5;
struct PstTrie
{
    int tot,root[maxn],nxt[maxn<<6][2];
    int tag[maxn<<6],cnt[maxn<<6];
    void clear()
    {   tot=0,insert(root[0],newnode(),0,0); }
    int newnode()
    {
        tag[tot]=cnt[tot]=0;
        nxt[tot][0]=nxt[tot][1]=0;
        return tot++;
    }
    void insert(int& rt,int prt,ll x,int id)
    {
        rt=newnode();
        bitset<35>b=x;
        int pt=rt;
        for(int i=32;~i;i--)
        {
            nxt[pt][b[i]]=newnode();
            nxt[pt][!b[i]]=nxt[prt][!b[i]];
            pt=nxt[pt][b[i]];
            prt=nxt[prt][b[i]];
            cnt[pt]=cnt[prt]+1;
        }
        tag[pt]=id;
    }
    int query(int l,int r,ll x)
    {
        bitset<35>b=x;
        int lpt=root[l],rpt=root[r];
        for(int i=32;~i;i--)
        {
            if(cnt[nxt[rpt][!b[i]]]>cnt[nxt[lpt][!b[i]]])
                lpt=nxt[lpt][!b[i]],rpt=nxt[rpt][!b[i]];
            else lpt=nxt[lpt][b[i]],rpt=nxt[rpt][b[i]];
        }
        return tag[rpt];
    }
}t;
ll s[maxn];
struct hpnode
{
    int pos,l,r,x;
    hpnode(int p,int l,int r):
        pos(p),l(l),r(r),x(t.query(l-1,r,s[p-1])){};
};
bool operator <(const hpnode& x,const hpnode& y)
{   return (s[x.x]^s[x.pos-1])<(s[y.x]^s[y.pos-1]); }
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    t.clear();
    priority_queue<hpnode>hp;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&s[i]),s[i]^=s[i-1];
        t.insert(t.root[i],t.root[i-1],s[i],i);
    }
    for(int i=1;i<=n;i++)
        hp.push(hpnode(i,i,n));
    ll ans=0;
    while(k--)
    {
        hpnode cur=hp.top(); hp.pop();
        int p=cur.pos,x=cur.x,l=cur.l,r=cur.r;
        ans+=s[x]^s[p-1];
        if(x!=l) hp.push(hpnode(p,l,x-1));
        if(x!=r) hp.push(hpnode(p,x+1,r));
    }
    printf("%lld\n",ans);
}   